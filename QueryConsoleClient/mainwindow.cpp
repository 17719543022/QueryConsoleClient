#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUuid>
#include <QTimer>
#include <QTime>
#include <QBuffer>
#include <QSignalMapper>
#include <QScrollBar>
#include "settings.h"

namespace {
bool parse(const QString &str, QJsonObject &object)
{
    QJsonParseError jsonParseError;
    QJsonDocument document = QJsonDocument::fromJson(str.toUtf8(), &jsonParseError);

    if (!document.isNull() && jsonParseError.error == QJsonParseError::NoError) {
        object = document.object();

        return true;
    }

    qDebug() << "QJsonParseError: " << jsonParseError.error;
    return false;
}

bool isConnectedGlobal = false;
}

void MyListen::MultipartRequstListen(const std::string &uri, const std::map<std::string, DataInfo> &mapDataInfo, std::string &strResponse)
{
    Q_UNUSED(mapDataInfo)
    qDebug() << "uri: " << QString::fromLocal8Bit(uri.c_str());

    strResponse = "";
}

void MyListen::CommonRequstListen(const std::string &uri, const std::string &strRequstBody, std::string &strResponse)
{
    Q_UNUSED(uri)
    qDebug() << "strRequestBody: " << QString::fromLocal8Bit(strRequstBody.c_str());

    QJsonObject object;
    if (!parse(QString::fromLocal8Bit(strRequstBody.c_str()), object)) {
        return;
    }
    if (object.value("heartbeat").toInt() != 0) {
        qDebug() << "Console will not response except heartbeat!";
        return;
    }

    QJsonObject json;
    QJsonObject content;

    json.insert("reqId", object.value("reqId").toString());
    json.insert("status", 0);
    json.insert("msg", "");
    json.insert("heartbeat", 0);
    json.insert("devicestatus", isConnectedGlobal && TicketScanSer::instance()->m_isOpen);

    content.insert("type", object.value("content").toObject().value("type").toInt());
    content.insert("rfid", object.value("content").toObject().value("rfid").toString());
    content.insert("status", object.value("content").toObject().value("status").toInt());
    content.insert("position", object.value("content").toObject().value("position").toInt());
    content.insert("mode", object.value("content").toObject().value("mode").toInt());
    content.insert("time", object.value("content").toObject().value("time").toString());
    content.insert("weight", object.value("content").toObject().value("weight").toString());

    json.insert("content", content);
    strResponse = QString(QJsonDocument(json).toJson()).toStdString();
    qDebug() << "strResponse: " << QString::fromLocal8Bit(strResponse.c_str());
}

OptionButtonWidget::OptionButtonWidget(QWidget *parent
                                       , int widgetIndex
                                       , QString flightNo
                                       , QString boardingNumber
                                       , QString flightDay)
    : QWidget(parent)
    , widgetIndex(widgetIndex)
    , flightNo(flightNo)
    , boardingNumber(boardingNumber)
    , flightDay(flightDay)
{
    QSignalMapper *signalMapper = new QSignalMapper();

    QPushButton *selectPushButton = new QPushButton(this);
    selectPushButton->setGeometry(64, 29, 312, 47);
    selectPushButton->setFixedSize(312, 47);
    selectPushButton->setStyleSheet("image: 0; border: 0; background: rgb(2, 112, 187); font: 19pt; color: rgb(255, 255, 255);");

    QLabel *flightLabel = new QLabel(selectPushButton);
    flightLabel->setStyleSheet("color: rgb(255, 255, 255); font: bold; font-size: 32px;");
    flightLabel->setText(flightNo + "/" + boardingNumber);
    flightLabel->setGeometry(15, 0, 200, 47);
    flightLabel->setFixedSize(200, 47);

    QLabel *dateLabel = new QLabel(selectPushButton);
    dateLabel->setStyleSheet("color: rgb(255, 255, 255); font: bold; font-size: 16px;");
    dateLabel->setText("(" + flightDay.left(4) + "/" + flightDay.mid(4, 2) + "/" + flightDay.mid(6, 2) + ")");
    dateLabel->setGeometry(205, 5, 100, 47);
    dateLabel->setFixedSize(100, 47);

    connect(selectPushButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(selectPushButton, widgetIndex);

    connect(signalMapper, SIGNAL(mapped(int)), parent, SLOT(clicked(int)));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , naManager(new QNetworkAccessManager(this))
    , isConnectedSuccess(false)
    , time_request(new QTimer(this))
    , positionNumber(0)
    , kindType(0)
    , ticketScanSer(new TicketScanSer(this))
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    isConnectedGlobal = false;

    login = new LoginDialog(this);
    login->initUI();
    login->move(0, 0);
    login->show();

    ui->flowTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->flowTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->flowTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->flowTableWidget->verticalHeader()->setVisible(false);
    ui->flowTableWidget->horizontalHeader()->setVisible(false);
    ui->flowTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->flowTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->flowTableWidget->setStyleSheet("image: 0; border: 0; background: transparent;");
    ui->flowTableWidget->setShowGrid(false);
    ui->flowTableWidget->setColumnCount(1);
    ui->flowTableWidget->setColumnWidth(0, 766);

    ui->widget_step1->hide();
    ui->widget_step2->hide();
    ui->widget_step3->hide();

    // 开启HTTP服务StartHTTPServer
    int nRet = StartHTTPServer(16666, &myListen);
    if (nRet == 0) {
        qDebug() << "server strart port = 16666";
    } else {
        qDebug() << "server fail";
    }

    connect(naManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onReply(QNetworkReply *)));

    QTimer *time_sync = new QTimer(this);
    connect(time_sync, SIGNAL(timeout()), this, SLOT(updateTime_regularyRestart()));
    time_sync->start(250);

    time_request->setSingleShot(true);
    connect(time_request, SIGNAL(timeout()), this, SLOT(updateNetStatus()));

    connect(login, &LoginDialog::accepted, [&]{
        qDebug() << "[Login Success!]";
        login->hide();
        ui->widget_msg->hide();

        ui->flowQueryLineEdit->clear();
        ui->passengerNameLabel_2->clear();
        ui->passengerFlightLabel_2->clear();
        ui->passengerCodeLabel_2->clear();
        ui->seatIdLabel_2->clear();
        ui->boardingNumberLabel_2->clear();
        ui->flowTableWidget->clear();
        ui->flowTableWidget->scrollToTop();
        while (ui->flowTableWidget->rowCount() > 0) {
            ui->flowTableWidget->removeRow(0);
        }

        ui->widget_step1->hide();
        ui->widget_step2->hide();
        ui->widget_step3->hide();
        ui->widget_dlg->hide();
    });

    connect(ticketScanSer
            , SIGNAL(ScanReadDataResult(const BoardingTicketInfo &))
            , this
            , SLOT(onNewTicket(const BoardingTicketInfo &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_return_clicked()
{
    login->initUI();
    login->move(0, 0);
    login->show();
}

void MainWindow::updateTime_regularyRestart()
{
    ui->label_currentTime->setText(QTime::currentTime().toString());

    if (!isConnectedSuccess) {
        QImage connectedImage;
        connectedImage.load(":/Images/切图/无.png");
        ui->label_netStat->setPixmap(QPixmap::fromImage(connectedImage));

        QNetworkRequest request;

        // Header
        QString showversions = LocalSettings::instance()->value("Interface/showVersionUrl").toString();
        request.setUrl(QUrl(showversions));

        naManager->get(request);
    } else {
        QImage disconnectImage;
        disconnectImage.load(":/Images/切图/有.png");
        ui->label_netStat->setPixmap(QPixmap::fromImage(disconnectImage));
    }
}

void MainWindow::updateNetStatus()
{
    isConnectedSuccess = false;
    isConnectedGlobal = false;
}

QPixmap MainWindow::getQPixmapSync(QString str)
{
    const QUrl url = QUrl::fromUserInput(str);

    QNetworkRequest request(url);
    QNetworkAccessManager *naManager = new QNetworkAccessManager(this);
    QNetworkReply* reply = naManager->get(request);

    QEventLoop eventLoop;
    connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec(QEventLoop::ExcludeUserInputEvents);

    QByteArray byteArray = reply->readAll();

    QPixmap pixmap;
    pixmap.loadFromData(byteArray);

    if (pixmap.isNull()) {
        QImage zhaoImage;
        zhaoImage.load(":/Images/切图/照片-.png");
        zhaoImage = zhaoImage.scaled(150
                                     , 226
                                     , Qt::IgnoreAspectRatio
                                     , Qt::SmoothTransformation);
        pixmap = QPixmap::fromImage(zhaoImage);
    }

    return pixmap;
}

void MainWindow::onNewTicket(const BoardingTicketInfo& btInfo) {
    qDebug() << "BoardingTicketInfo: " << btInfo.flightNo;
    ui->flowQueryLineEdit->setText(btInfo.flightNo + '#' + btInfo.boardingNumber + '#' + btInfo.flightDay);

    this->on_flowQueryPushButton_clicked();
}

void MainWindow::fillWithSpecificResult(const QJsonObject &object)
{
    ui->flowQueryLineEdit->clear();

    QJsonValue userInfoJson = object.value("userInfo");
    if (!userInfoJson.isNull()) {
        ui->passengerNameLabel_2->setText(userInfoJson.toObject().value("passengerName").toString());
        ui->passengerFlightLabel_2->setText(userInfoJson.toObject().value("flightNo").toString());
        ui->passengerCodeLabel_2->setText(userInfoJson.toObject().value("certificateNumber").toString());
        ui->seatIdLabel_2->setText(userInfoJson.toObject().value("seatId").toString());
        ui->boardingNumberLabel_2->setText(userInfoJson.toObject().value("boardingNumber").toString());
    }
    QJsonValue securityInfoJson = object.value("securityInfo");
    if (!securityInfoJson.isNull()) {
        ui->flowTableWidget->setRowHeight(0, 226);
        ui->flowTableWidget->insertRow(0);
        ui->flowTableWidget->setRowHeight(0, 226);

        QWidget *securityWidget = new QWidget();
        securityWidget->setFixedSize(766, 226);
        QLabel *securityLabel = new QLabel(securityWidget);
        securityLabel->setGeometry(0, 0, 180, 226);
        securityLabel->setText("人证验证");
        securityLabel->setFixedSize(180, 226);
        securityLabel->setAlignment(Qt::AlignCenter);
        securityLabel->setStyleSheet("image: 0; border: 0; background: 0; font: bold 20pt; color: rgb(0, 228, 255);");

        QPixmap pixmap = getQPixmapSync(securityInfoJson.toObject().value("photoPath").toString());
        pixmap = pixmap.scaled(150
                               , 198
                               , Qt::IgnoreAspectRatio
                               , Qt::SmoothTransformation);
        QLabel *securityPhotoLabel = new QLabel(securityWidget);
        securityPhotoLabel->setGeometry(180, 0, 150, 226);
        securityPhotoLabel->setPixmap(pixmap);
        securityPhotoLabel->setFixedSize(150, 226);
        securityPhotoLabel->setAlignment(Qt::AlignCenter);

        QLabel *securityGateTitleLabel = new QLabel(securityWidget);
        securityGateTitleLabel->setGeometry(330, 14, 144, 38);
        securityGateTitleLabel->setText("通过位置：");
        securityGateTitleLabel->setFixedSize(144, 38);
        securityGateTitleLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
        securityGateTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

        QLabel *securityTimeTitleLabel = new QLabel(securityWidget);
        securityTimeTitleLabel->setGeometry(330, 58, 144, 38);
        securityTimeTitleLabel->setText("通过时间：");
        securityTimeTitleLabel->setFixedSize(144, 38);
        securityTimeTitleLabel->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
        securityTimeTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

        QLabel *securityGateValueLabel = new QLabel(securityWidget);
        securityGateValueLabel->setGeometry(474, 14, 292, 38);
        securityGateValueLabel->setText(securityInfoJson.toObject().value("channelName").toString());
        securityGateValueLabel->setFixedSize(292, 38);
        securityGateValueLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        securityGateValueLabel->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

        QLabel *securityTimeValueLabel_1 = new QLabel(securityWidget);
        securityTimeValueLabel_1->setGeometry(474, 58, 292, 38);
        QString passTime = securityInfoJson.toObject().value("passTime").toString();
        securityTimeValueLabel_1->setText(passTime.left(4) + "/" + passTime.mid(5, 2) + "/" + passTime.mid(8, 2));
        securityTimeValueLabel_1->setFixedSize(292, 38);
        securityTimeValueLabel_1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        securityTimeValueLabel_1->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

        QLabel *securityTimeValueLabel_2 = new QLabel(securityWidget);
        securityTimeValueLabel_2->setGeometry(474, 102, 292, 38);
        securityTimeValueLabel_2->setText(passTime.mid(11, 2) + "：" + passTime.mid(14, 2) + "：" + passTime.mid(17, 2));
        securityTimeValueLabel_2->setFixedSize(292, 38);
        securityTimeValueLabel_2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        securityTimeValueLabel_2->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

        QImage securityModalImage;
        int passType = securityInfoJson.toObject().value("passType").toInt();
        int passStatus = securityInfoJson.toObject().value("passStatus").toInt();
        switch (passType) {
        case 0:
        case 2:
            switch (passStatus) {
            case 0:
                securityModalImage.load(":/Images/切图/系统验证通过.png");
                break;
            case 1:
                securityModalImage.load(":/Images/切图/系统验证不通过.png");
                break;
            case 3:
                securityModalImage.load(":/Images/切图/证件失效.png");
                break;
            default:
                securityModalImage.load(":/Images/切图/icon_wjl.png");
                break;
            }
            break;
        case 1:
            switch (passStatus) {
            case 0:
                securityModalImage.load(":/Images/切图/人工验证通过.png");
                break;
            case 1:
                securityModalImage.load(":/Images/切图/icon_wjl.png");
                break;
            default:
                securityModalImage.load(":/Images/切图/icon_wjl.png");
                break;
            }
            break;
        case 3:
            securityModalImage.load(":/Images/切图/人工验证通过.png");
            break;
        default:
            securityModalImage.load(":/Images/切图/icon_wjl.png");
            break;
        }
        securityModalImage = securityModalImage.scaled(169
                                                       , 50
                                                       , Qt::IgnoreAspectRatio
                                                       , Qt::SmoothTransformation);
        QPixmap securityModalPixmap = QPixmap::fromImage(securityModalImage);
        QLabel *securityModalLabel = new QLabel(securityWidget);
        securityModalLabel->setGeometry(474, 162, 169, 50);
        securityModalLabel->setFixedSize(169, 50);
        securityModalLabel->setPixmap(securityModalPixmap);
        securityModalLabel->setStyleSheet("image: 0; border: 0; background: 0;");

        QLabel *splitLabel = new QLabel(securityWidget);
        splitLabel->setGeometry(13, 0, 740, 2);
        splitLabel->setStyleSheet("image: 0; background: 0; border-radius: 0; border-width: 1px; border-style: dashed; border-color: rgb(135, 183, 194);");

        QLabel *bottomSplit = new QLabel(securityWidget);
        bottomSplit->setGeometry(13, 224, 740, 2);
        bottomSplit->setStyleSheet("image: 0; background: 0; border-radius: 0; border-width: 1px; border-style: dashed; border-color: rgb(135, 183, 194);");

        ui->flowTableWidget->setCellWidget(0, 0, securityWidget);
    }

    ui->widget_step1->show();
}

void MainWindow::onReply(QNetworkReply *reply)
{
    if (reply->url() != QUrl(LocalSettings::instance()->value("Interface/flowBackQueryUrl").toString())) {
        time_request->stop();
    }

    if (reply->url() == QUrl(LocalSettings::instance()->value("Interface/manualCheckUrl").toString())) {
        ui->widget_msg->hide();
    }

    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if (statusCode.isValid()) {
        qDebug() << "status code: " << statusCode.toInt();
    }

    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute);

    if(reason.isValid()) {
        qDebug() << "reason: " << reason;
    }

    QNetworkReply::NetworkError err = reply->error();

    if (err != QNetworkReply::NoError) {
        qDebug() << "err: " << reply->errorString();
    } else {
        if (reply->url() == LocalSettings::instance()->value("Interface/showVersionUrl").toString()) {
            isConnectedSuccess = true;
            isConnectedGlobal = false;

            qDebug() << "[Connected To Server Success!]";
        } else {
            QByteArray all = reply->readAll();

            QJsonParseError err;
            QJsonDocument document = QJsonDocument::fromJson(all, &err);

            if (err.error == QJsonParseError::NoError) {
                qDebug() << "document: " << document;
                flowDocument = document;

                QJsonObject responseObject = document.object();
                int status = responseObject.value("status").toInt();
                if (status != 0) {
                    ui->label_text->setText("服务器返回错误：" + QString::number(status) + "!");
                    ui->label_text->show();
                    ui->msgButton_Accept->hide();
                    ui->msgButton_Reject->hide();
                    ui->msgButton_X1->show();
                    ui->msgButton_X2->show();
                    ui->widget_msg->show();

                    return;
                }

                if (responseObject.contains("results")) {
                    QJsonValue resultsJson = responseObject.value("results");
                    if (!resultsJson.isNull() && resultsJson.isArray()) {
                        QJsonArray resultsArray = resultsJson.toArray();
                        int flowNum = resultsArray.size();

                        if (flowNum > 1) {
                            ui->optionsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
                            ui->optionsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
                            ui->optionsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
                            ui->optionsTableWidget->verticalHeader()->setVisible(false);
                            ui->optionsTableWidget->horizontalHeader()->setVisible(false);
                            ui->optionsTableWidget->verticalScrollBar()->setStyleSheet("QScrollBar{width: 16px;}");
                            ui->optionsTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
                            ui->optionsTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                            ui->optionsTableWidget->setStyleSheet("image: 0; border: 0; background: transparent;");
                            ui->optionsTableWidget->setShowGrid(false);
                            ui->optionsTableWidget->setColumnCount(1);
                            ui->optionsTableWidget->setColumnWidth(0, 440);

                            for (int i = 0; i < flowNum; i++) {
                                ui->optionsTableWidget->setRowHeight(i, 105);
                                ui->optionsTableWidget->insertRow(i);
                                ui->optionsTableWidget->setRowHeight(i, 105);

                                qDebug() << "securityInfo: " << resultsArray.at(i).toObject().value("securityInfo").toObject();
                                qDebug() << "securityInfo: " << resultsArray.at(i).toObject().value("securityInfo").toObject().value("flightNo").toString();

                                QString flightNo = resultsArray.at(i).toObject().value("userInfo").toObject().value("flightNo").toString();
                                QString boardingNumber = resultsArray.at(i).toObject().value("userInfo").toObject().value("boardingNumber").toString();
                                QString flightDay = resultsArray.at(i).toObject().value("userInfo").toObject().value("flightDay").toString();
                                QWidget *widget = new OptionButtonWidget(this, i, flightNo, boardingNumber, flightDay);

                                ui->optionsTableWidget->setCellWidget(i, 0, widget);
                            }

                            ui->widget_dlg->show();
                        } else if (flowNum > 0) {
                            fillWithSpecificResult(resultsArray.at(0).toObject());
                        } else {
                            ui->label_text->setText("没有该旅客的信息!");
                            ui->msgButton_Accept->hide();
                            ui->msgButton_Reject->hide();
                            ui->msgButton_X1->show();
                            ui->msgButton_X2->show();
                            ui->widget_msg->show();

                            return;
                        }
                    } else {
                        ui->label_text->setText("没有该旅客的信息!");
                        ui->msgButton_Accept->hide();
                        ui->msgButton_Reject->hide();
                        ui->msgButton_X1->show();
                        ui->msgButton_X2->show();
                        ui->widget_msg->show();

                        return;
                    }
                }
            } else {
                qDebug() << "error: " << err.error;
            }
        }
    }
}

void MainWindow::on_flowQueryPushButton_clicked()
{
    ui->flowTableWidget->scrollToTop();
    while (ui->flowTableWidget->rowCount() > 0) {
        ui->flowTableWidget->removeRow(0);
    }
    ui->passengerNameLabel_2->clear();
    ui->passengerCodeLabel_2->clear();
    ui->passengerFlightLabel_2->clear();
    ui->boardingNumberLabel_2->clear();
    ui->seatIdLabel_2->clear();

    QString input = ui->flowQueryLineEdit->text().toUpper();

    if ((input.length() == 0) || (input.length() > 18)) {
        ui->msgButton_Accept->hide();
        ui->msgButton_Reject->hide();
        ui->msgButton_X1->show();
        ui->msgButton_X2->show();
        ui->label_text->setText("请输入有效信息!");
        ui->widget_msg->show();

        return;
    }

    QNetworkRequest request;

    // Header
    QString flowBackUrl = LocalSettings::instance()->value("Interface/flowBackQueryUrl").toString();
    request.setUrl(QUrl(flowBackUrl));
    QString contentType = "application/json";
    request.setHeader(QNetworkRequest::ContentTypeHeader, contentType);
    QString apiId = "123456";
    request.setRawHeader("apiId", apiId.toLatin1());
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    request.setRawHeader("timestamp", timestamp.toLatin1());
    QString apiKey = "1285384ddfb057814bad78127bc789be";
    QString temp = "/api/v1/airport/data/flowback-query" + timestamp + apiKey;
    QByteArray bb = QCryptographicHash::hash(temp.toLatin1(), QCryptographicHash::Md5);
    QString sign = QString().append(bb.toHex());
    request.setRawHeader("sign", sign.toLatin1());

    // body
    QJsonObject json;
    QJsonDocument doc;
    QString uuid = QUuid::createUuid().toString();
    uuid.remove("{").remove("}").remove("-");
    json.insert("reqId", uuid);
    // isFuzzyQuery的填写规则是,如果是通过身份证查询则填0,通过机票加航班号查询时,手动输入填1,刷票输入填0
    // flightDay的填写规则是,如果用扫码枪扫入,则将机票年月日的日填入,如果手动输入则为-1,查询历史所有
    if (input.contains("#", Qt::CaseSensitive)) {
        json.insert("cardId", "");
        json.insert("flightNo", input.section("#", 0, 0));
        json.insert("boardingNumber", input.section("#", 1, 1));
        if (input.section("#", 2, 2) == "") {
            json.insert("flightDay", -1);
        } else {
            json.insert("flightDay", input.section("#", 2, 2).toInt());
        }
        json.insert("isFuzzyQuery", 1);
    } else {
        json.insert("cardId", input);
        json.insert("flightNo", "");
        json.insert("boardingNumber", "");
        json.insert("flightDay", 1);
        json.insert("isFuzzyQuery", 0);
    }

    json.insert("seatId", "");
    qDebug() << "request: " << json;

    doc.setObject(json);
    QByteArray array = doc.toJson(QJsonDocument::Compact);

    naManager->post(request, array);

    time_request->start(3000);
}

void MainWindow::on_msgButton_X2_clicked()
{
    ui->widget_msg->hide();
    ui->widget_step2->hide();
    ui->widget_step3->hide();
}

void MainWindow::on_msgButton_X1_clicked()
{
    ui->widget_msg->hide();
    ui->widget_step2->hide();
    ui->widget_step3->hide();
}

void MainWindow::on_msgButton_Accept_clicked()
{
    // 我不用“1.5 人工放行行李绑定接口”，只用“3.2 行李人工绑定接口”
    QNetworkRequest request;

    // Header
    QString url = LocalSettings::instance()->value("Interface/manualBindingUrl").toString();
    request.setUrl(QUrl(url));
    QString contentType = "application/json";
    request.setHeader(QNetworkRequest::ContentTypeHeader, contentType);
    QString apiId = "123456";
    request.setRawHeader("apiId", apiId.toLatin1());
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    request.setRawHeader("timestamp", timestamp.toLatin1());
    QString apiKey = "1285384ddfb057814bad78127bc789be";
    QString temp = "/api/v1/airport/baggage/manual-binding" + timestamp + apiKey;
    QByteArray bb = QCryptographicHash::hash(temp.toLatin1(), QCryptographicHash::Md5);
    QString sign = QString().append(bb.toHex());
    request.setRawHeader("sign", sign.toLatin1());

    // body
    QJsonObject json;
    QJsonDocument doc;
    QString uuid = QUuid::createUuid().toString();
    uuid.remove("{").remove("}").remove("-");
    json.insert("reqId", uuid);
    json.insert("flightNumber", flowDocument.object().value("results").toArray().at(0).toObject().value("userInfo").toArray().at(0).toObject().value("flightNo").toString());
    json.insert("flightDay", flowDocument.object().value("results").toArray().at(0).toObject().value("userInfo").toArray().at(0).toObject().value("flightDay").toString());
    json.insert("boardingNumber", flowDocument.object().value("results").toArray().at(0).toObject().value("userInfo").toArray().at(0).toObject().value("boardingNumber").toString());
    json.insert("seatNumber", flowDocument.object().value("results").toArray().at(0).toObject().value("userInfo").toArray().at(0).toObject().value("seatId").toString());
    json.insert("certificateType", flowDocument.object().value("results").toArray().at(0).toObject().value("userInfo").toArray().at(0).toObject().value("certificateType").toInt());
    json.insert("certificateNumber", flowDocument.object().value("results").toArray().at(0).toObject().value("userInfo").toArray().at(0).toObject().value("certificateNumber").toString());
    json.insert("passengerName", flowDocument.object().value("results").toArray().at(0).toObject().value("userInfo").toArray().at(0).toObject().value("passengerName").toString());
    json.insert("passengerEnglishName", flowDocument.object().value("results").toArray().at(0).toObject().value("userInfo").toArray().at(0).toObject().value("passengerEnglishName").toString());
    // 接口中说是必须字段，应该是描述错误，应该是非必须字段才对
    json.insert("passengerSex", 0);
    json.insert("positionNumber", positionNumber);
    json.insert("kindType", kindType);

    doc.setObject(json);
    QByteArray array = doc.toJson(QJsonDocument::Compact);

    naManager->post(request, array);
    ui->widget_msg->hide();
}

void MainWindow::on_msgButton_Reject_clicked()
{
    ui->widget_msg->hide();
    ui->widget_step1->show();
    ui->widget_step2->hide();
    ui->widget_step3->hide();
}

void MainWindow::on_pushButton_bind_clicked()
{
    kindType = 0;

    ui->widget_step1->show();
    ui->widget_step2->show();
    ui->widget_step3->hide();
}

void MainWindow::on_pushButton_intercept_clicked()
{
    kindType = 1;

    ui->widget_step1->show();
    ui->widget_step2->hide();
    ui->widget_step3->show();
}

void MainWindow::on_pushButton_location1_clicked()
{
    positionNumber = 1;

    ui->label_text->setText("请确认此次绑定！");

    ui->msgButton_X1->show();
    ui->msgButton_X2->hide();
    ui->msgButton_Accept->show();
    ui->msgButton_Reject->show();
    ui->widget_msg->show();
}

void MainWindow::on_pushButton_location2_clicked()
{
    positionNumber = 2;

    ui->label_text->setText("请确认此次绑定！");

    ui->msgButton_X1->show();
    ui->msgButton_X2->hide();
    ui->msgButton_Accept->show();
    ui->msgButton_Reject->show();
    ui->widget_msg->show();
}

void MainWindow::on_pushButton_location3_clicked()
{
    positionNumber = 3;

    ui->label_text->setText("请确认此次绑定！");

    ui->msgButton_X1->show();
    ui->msgButton_X2->hide();
    ui->msgButton_Accept->show();
    ui->msgButton_Reject->show();
    ui->widget_msg->show();
}

void MainWindow::clicked(int widgetIndex)
{
    qDebug() << "MainWindow::clicked: " << widgetIndex;

    fillWithSpecificResult(flowDocument.object().value("results").toArray().at(widgetIndex).toObject());

    ui->widget_dlg->hide();
}

void MainWindow::on_pushButton_intercept1_clicked()
{
    positionNumber = 1;

    ui->label_text->setText("请确认此次拦截！");

    ui->msgButton_X1->show();
    ui->msgButton_X2->hide();
    ui->msgButton_Accept->show();
    ui->msgButton_Reject->show();
    ui->widget_msg->show();
}

void MainWindow::on_pushButton_intercept2_clicked()
{
    positionNumber = 2;

    ui->label_text->setText("请确认此次拦截！");

    ui->msgButton_X1->show();
    ui->msgButton_X2->hide();
    ui->msgButton_Accept->show();
    ui->msgButton_Reject->show();
    ui->widget_msg->show();
}

void MainWindow::on_pushButton_intercept3_clicked()
{
    positionNumber = 3;

    ui->label_text->setText("请确认此次拦截！");

    ui->msgButton_X1->show();
    ui->msgButton_X2->hide();
    ui->msgButton_Accept->show();
    ui->msgButton_Reject->show();
    ui->widget_msg->show();
}
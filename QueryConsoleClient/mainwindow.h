#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include "ticketscanser.h"
#include "HTTPServer/HTTPServerExp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyListen : public QObject, public RequstListener
{
    Q_OBJECT

private:
    virtual void MultipartRequstListen(const std::string &uri, const std::map<std::string, DataInfo> &mapDataInfo, std::string &strResponse) override;
    virtual void CommonRequstListen(const std::string &uri, const std::string &strRequstBody, std::string &strResponse) override;

signals:
    void newSerialData(QString strRequest);
};

class OptionButtonWidget : public QWidget
{
    Q_OBJECT

public:
    OptionButtonWidget(QWidget *parent = Q_NULLPTR
            , int widgetIndex = 0
            , QString flightNo = QString()
            , QString boardingNumber = QString()
            , QString flightDay = QString());

private:
    int widgetIndex;
    QString flightNo;
    QString boardingNumber;
    QString flightDay;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_return_clicked();

    void on_flowQueryPushButton_clicked();

    void on_msgButton_X2_clicked();

    void on_msgButton_X1_clicked();

    void on_msgButton_Accept_clicked();

    void on_msgButton_Reject_clicked();

    void updateTime_regularyRestart();

    void updateNetStatus();

    void onReply(QNetworkReply *reply);

    void onNewTicket(const BoardingTicketInfo& btInfo);

    void clicked(int widgetIndex);

    void on_pushButton_bind_clicked();

    void on_pushButton_location1_clicked();

    void on_pushButton_location2_clicked();

    void on_pushButton_location3_clicked();

    void on_pushButton_intercept_clicked();

    void on_pushButton_intercept1_clicked();

    void on_pushButton_intercept2_clicked();

    void on_pushButton_intercept3_clicked();

private:
    QPixmap getQPixmapSync(QString str);

    void fillWithSpecificResult(const QJsonObject &object);

private:
    Ui::MainWindow *ui;
    LoginDialog *login;
    QNetworkAccessManager *naManager;
    bool isConnectedSuccess;
    QTimer *time_request;
    QJsonDocument flowDocument;
    int positionNumber;
    int kindType;
    TicketScanSer *ticketScanSer;
    MyListen myListen;
};
#endif // MAINWINDOW_H

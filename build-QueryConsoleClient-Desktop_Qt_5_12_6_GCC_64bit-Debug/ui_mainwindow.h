/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_ALL;
    QWidget *widget_logo;
    QLabel *label_currentTime;
    QLabel *label_netStat;
    QLabel *stateCam_x_2;
    QWidget *widget_menuUp;
    QPushButton *Button_return;
    QLabel *label_tips;
    QWidget *widget_flowback;
    QWidget *flowQueryWidget;
    QWidget *flowqueryWidget;
    QWidget *flowQueryLineWidget;
    QLineEdit *flowQueryLineEdit;
    QPushButton *flowQueryPushButton;
    QWidget *userInfoWidget;
    QLabel *passengerNameLabel_1;
    QLabel *passengerNameLabel_2;
    QLabel *passengerFlightLabel_1;
    QLabel *passengerFlightLabel_2;
    QLabel *passengerCodeLabel_1;
    QLabel *passengerCodeLabel_2;
    QLabel *seatIdLabel_1;
    QLabel *seatIdLabel_2;
    QLabel *boardingNumberLabel_1;
    QLabel *boardingNumberLabel_2;
    QWidget *widget_wrapper;
    QTableWidget *flowTableWidget;
    QWidget *widget_step2;
    QLabel *locationsLabel_1;
    QPushButton *pushButton_location1;
    QPushButton *pushButton_location2;
    QPushButton *pushButton_location3;
    QWidget *widget_step1;
    QPushButton *pushButton_bind;
    QPushButton *pushButton_intercept;
    QWidget *widget_step3;
    QLabel *locationsLabel_2;
    QPushButton *pushButton_intercept1;
    QPushButton *pushButton_intercept2;
    QPushButton *pushButton_intercept3;
    QWidget *widget_msg;
    QWidget *widget_box;
    QLabel *label_text;
    QPushButton *msgButton_X1;
    QPushButton *msgButton_X2;
    QPushButton *msgButton_Reject;
    QPushButton *msgButton_Accept;
    QWidget *widget_dlg;
    QWidget *widget_dialog;
    QLabel *titleLabel;
    QTableWidget *optionsTableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 1280);
        MainWindow->setIconSize(QSize(22, 36));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_ALL = new QWidget(centralwidget);
        widget_ALL->setObjectName(QString::fromUtf8("widget_ALL"));
        widget_ALL->setGeometry(QRect(0, 0, 800, 1280));
        widget_ALL->setStyleSheet(QString::fromUtf8("image: url(:/Images/\345\210\207\345\233\276/\350\247\206\345\261\217\346\241\206\350\243\205\351\245\260-\346\213\267\350\264\235-5.png);"));
        widget_logo = new QWidget(widget_ALL);
        widget_logo->setObjectName(QString::fromUtf8("widget_logo"));
        widget_logo->setGeometry(QRect(0, 0, 800, 49));
        widget_logo->setStyleSheet(QString::fromUtf8("image: url(:/Images/\345\210\207\345\233\276/\347\234\211\345\244\264-\346\213\267\350\264\235.png);"));
        label_currentTime = new QLabel(widget_logo);
        label_currentTime->setObjectName(QString::fromUtf8("label_currentTime"));
        label_currentTime->setGeometry(QRect(0, 0, 100, 50));
        QFont font;
        font.setPointSize(14);
        label_currentTime->setFont(font);
        label_currentTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_currentTime->setAlignment(Qt::AlignCenter);
        label_netStat = new QLabel(widget_logo);
        label_netStat->setObjectName(QString::fromUtf8("label_netStat"));
        label_netStat->setGeometry(QRect(750, 0, 49, 49));
        label_netStat->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_netStat->setPixmap(QPixmap(QString::fromUtf8(":/Images/\345\210\207\345\233\276/\346\234\211.png")));
        label_netStat->setAlignment(Qt::AlignCenter);
        stateCam_x_2 = new QLabel(widget_logo);
        stateCam_x_2->setObjectName(QString::fromUtf8("stateCam_x_2"));
        stateCam_x_2->setGeometry(QRect(680, 18, 80, 14));
        stateCam_x_2->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft Yahei\";font-size:10px;background:transparent;color:#00ff00;"));
        stateCam_x_2->setAlignment(Qt::AlignCenter);
        widget_menuUp = new QWidget(widget_ALL);
        widget_menuUp->setObjectName(QString::fromUtf8("widget_menuUp"));
        widget_menuUp->setGeometry(QRect(0, 49, 800, 47));
        widget_menuUp->setStyleSheet(QString::fromUtf8("image: url(:/Images/\345\210\207\345\233\276/\346\225\205\351\232\234\347\212\266\346\200\201\346\230\276\347\244\272\344\275\215BG.png);"));
        Button_return = new QPushButton(widget_menuUp);
        Button_return->setObjectName(QString::fromUtf8("Button_return"));
        Button_return->setGeometry(QRect(0, 0, 49, 47));
        Button_return->setStyleSheet(QString::fromUtf8("border: 0;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/\345\210\207\345\233\276/\350\277\224\345\233\236-\346\226\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        Button_return->setIcon(icon);
        Button_return->setIconSize(QSize(22, 36));
        label_tips = new QLabel(widget_menuUp);
        label_tips->setObjectName(QString::fromUtf8("label_tips"));
        label_tips->setGeometry(QRect(170, 0, 460, 47));
        label_tips->setStyleSheet(QString::fromUtf8("image: 0;"));
        widget_flowback = new QWidget(widget_ALL);
        widget_flowback->setObjectName(QString::fromUtf8("widget_flowback"));
        widget_flowback->setGeometry(QRect(0, 105, 800, 1175));
        widget_flowback->setStyleSheet(QString::fromUtf8("image: 0;"));
        flowQueryWidget = new QWidget(widget_flowback);
        flowQueryWidget->setObjectName(QString::fromUtf8("flowQueryWidget"));
        flowQueryWidget->setGeometry(QRect(15, 2, 770, 738));
        flowQueryWidget->setStyleSheet(QString::fromUtf8("image: 0;"));
        flowqueryWidget = new QWidget(flowQueryWidget);
        flowqueryWidget->setObjectName(QString::fromUtf8("flowqueryWidget"));
        flowqueryWidget->setGeometry(QRect(0, 0, 770, 92));
        flowqueryWidget->setStyleSheet(QString::fromUtf8("border-image: 0;\n"
"image: 0;\n"
"background: 0;"));
        flowQueryLineWidget = new QWidget(flowqueryWidget);
        flowQueryLineWidget->setObjectName(QString::fromUtf8("flowQueryLineWidget"));
        flowQueryLineWidget->setGeometry(QRect(150, 30, 359, 40));
        flowQueryLineWidget->setStyleSheet(QString::fromUtf8("border: 0;\n"
"image: 0;\n"
"background: rgb(63, 95, 120);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 4px;"));
        flowQueryLineEdit = new QLineEdit(flowQueryLineWidget);
        flowQueryLineEdit->setObjectName(QString::fromUtf8("flowQueryLineEdit"));
        flowQueryLineEdit->setGeometry(QRect(4, 1, 351, 38));
        QFont font1;
        font1.setPointSize(18);
        flowQueryLineEdit->setFont(font1);
        flowQueryLineEdit->setStyleSheet(QString::fromUtf8(""));
        flowQueryLineEdit->setMaxLength(18);
        flowQueryPushButton = new QPushButton(flowqueryWidget);
        flowQueryPushButton->setObjectName(QString::fromUtf8("flowQueryPushButton"));
        flowQueryPushButton->setGeometry(QRect(588, 30, 122, 40));
        flowQueryPushButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/Images/\345\210\207\345\233\276/\346\237\245\350\257\242.png);}\n"
"QPushButton:pressed{border-image: url(:/Images/\345\210\207\345\233\276/\346\237\245\350\257\242-\346\213\267\350\264\235.png);}"));
        userInfoWidget = new QWidget(flowQueryWidget);
        userInfoWidget->setObjectName(QString::fromUtf8("userInfoWidget"));
        userInfoWidget->setGeometry(QRect(0, 107, 770, 158));
        userInfoWidget->setStyleSheet(QString::fromUtf8("border-image: 0;\n"
"image: 0;\n"
"border: 0;\n"
"background: 0;"));
        passengerNameLabel_1 = new QLabel(userInfoWidget);
        passengerNameLabel_1->setObjectName(QString::fromUtf8("passengerNameLabel_1"));
        passengerNameLabel_1->setGeometry(QRect(75, 0, 120, 38));
        QFont font2;
        font2.setPointSize(19);
        passengerNameLabel_1->setFont(font2);
        passengerNameLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        passengerNameLabel_2 = new QLabel(userInfoWidget);
        passengerNameLabel_2->setObjectName(QString::fromUtf8("passengerNameLabel_2"));
        passengerNameLabel_2->setGeometry(QRect(200, 0, 241, 38));
        passengerNameLabel_2->setFont(font2);
        passengerNameLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        passengerFlightLabel_1 = new QLabel(userInfoWidget);
        passengerFlightLabel_1->setObjectName(QString::fromUtf8("passengerFlightLabel_1"));
        passengerFlightLabel_1->setGeometry(QRect(445, 0, 110, 38));
        passengerFlightLabel_1->setFont(font2);
        passengerFlightLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        passengerFlightLabel_2 = new QLabel(userInfoWidget);
        passengerFlightLabel_2->setObjectName(QString::fromUtf8("passengerFlightLabel_2"));
        passengerFlightLabel_2->setGeometry(QRect(560, 0, 191, 38));
        passengerFlightLabel_2->setFont(font2);
        passengerFlightLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        passengerCodeLabel_1 = new QLabel(userInfoWidget);
        passengerCodeLabel_1->setObjectName(QString::fromUtf8("passengerCodeLabel_1"));
        passengerCodeLabel_1->setGeometry(QRect(75, 60, 111, 38));
        passengerCodeLabel_1->setFont(font2);
        passengerCodeLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        passengerCodeLabel_2 = new QLabel(userInfoWidget);
        passengerCodeLabel_2->setObjectName(QString::fromUtf8("passengerCodeLabel_2"));
        passengerCodeLabel_2->setGeometry(QRect(195, 60, 541, 38));
        passengerCodeLabel_2->setFont(font2);
        passengerCodeLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        seatIdLabel_1 = new QLabel(userInfoWidget);
        seatIdLabel_1->setObjectName(QString::fromUtf8("seatIdLabel_1"));
        seatIdLabel_1->setGeometry(QRect(75, 120, 111, 38));
        seatIdLabel_1->setFont(font2);
        seatIdLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        seatIdLabel_2 = new QLabel(userInfoWidget);
        seatIdLabel_2->setObjectName(QString::fromUtf8("seatIdLabel_2"));
        seatIdLabel_2->setGeometry(QRect(195, 120, 221, 38));
        seatIdLabel_2->setFont(font2);
        seatIdLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        boardingNumberLabel_1 = new QLabel(userInfoWidget);
        boardingNumberLabel_1->setObjectName(QString::fromUtf8("boardingNumberLabel_1"));
        boardingNumberLabel_1->setGeometry(QRect(445, 120, 91, 38));
        boardingNumberLabel_1->setFont(font2);
        boardingNumberLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        boardingNumberLabel_2 = new QLabel(userInfoWidget);
        boardingNumberLabel_2->setObjectName(QString::fromUtf8("boardingNumberLabel_2"));
        boardingNumberLabel_2->setGeometry(QRect(549, 120, 191, 38));
        boardingNumberLabel_2->setFont(font2);
        boardingNumberLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        widget_wrapper = new QWidget(flowQueryWidget);
        widget_wrapper->setObjectName(QString::fromUtf8("widget_wrapper"));
        widget_wrapper->setGeometry(QRect(2, 280, 766, 455));
        widget_wrapper->setStyleSheet(QString::fromUtf8("border-image: 0;\n"
"background: transparent;"));
        flowTableWidget = new QTableWidget(widget_wrapper);
        if (flowTableWidget->columnCount() < 1)
            flowTableWidget->setColumnCount(1);
        flowTableWidget->setObjectName(QString::fromUtf8("flowTableWidget"));
        flowTableWidget->setGeometry(QRect(0, 0, 766, 455));
        flowTableWidget->setStyleSheet(QString::fromUtf8(""));
        flowTableWidget->setColumnCount(1);
        widget_step2 = new QWidget(widget_flowback);
        widget_step2->setObjectName(QString::fromUtf8("widget_step2"));
        widget_step2->setGeometry(QRect(0, 702, 800, 200));
        locationsLabel_1 = new QLabel(widget_step2);
        locationsLabel_1->setObjectName(QString::fromUtf8("locationsLabel_1"));
        locationsLabel_1->setGeometry(QRect(52, 48, 311, 41));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(true);
        locationsLabel_1->setFont(font3);
        locationsLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_location1 = new QPushButton(widget_step2);
        pushButton_location1->setObjectName(QString::fromUtf8("pushButton_location1"));
        pushButton_location1->setGeometry(QRect(90, 148, 163, 52));
        pushButton_location1->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/Images/\345\210\207\345\233\276/1\345\217\267\345\207\206\345\244\207\344\275\215.png);}\n"
"QPushButton:pressed{border-image: url(:/Images/\345\210\207\345\233\276/1\345\217\267\345\207\206\345\244\207\344\275\215-\346\213\267\350\264\235.png);}"));
        pushButton_location2 = new QPushButton(widget_step2);
        pushButton_location2->setObjectName(QString::fromUtf8("pushButton_location2"));
        pushButton_location2->setGeometry(QRect(319, 148, 163, 52));
        pushButton_location2->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/Images/\345\210\207\345\233\276/2\345\217\267\345\207\206\345\244\207\344\275\215.png);}\n"
"QPushButton:pressed{border-image: url(:/Images/\345\210\207\345\233\276/2\345\217\267\345\207\206\345\244\207\344\275\215-\346\213\267\350\264\235.png);}"));
        pushButton_location3 = new QPushButton(widget_step2);
        pushButton_location3->setObjectName(QString::fromUtf8("pushButton_location3"));
        pushButton_location3->setGeometry(QRect(547, 148, 163, 52));
        pushButton_location3->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/Images/\345\210\207\345\233\276/3\345\217\267\345\207\206\345\244\207\344\275\215.png);}\n"
"QPushButton:pressed{border-image: url(:/Images/\345\210\207\345\233\276/3\345\217\267\345\207\206\345\244\207\344\275\215-\346\213\267\350\264\235.png);}"));
        widget_step1 = new QWidget(widget_flowback);
        widget_step1->setObjectName(QString::fromUtf8("widget_step1"));
        widget_step1->setGeometry(QRect(0, 650, 800, 52));
        pushButton_bind = new QPushButton(widget_step1);
        pushButton_bind->setObjectName(QString::fromUtf8("pushButton_bind"));
        pushButton_bind->setGeometry(QRect(130, 0, 163, 52));
        pushButton_bind->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/Images/\345\210\207\345\233\276/\344\272\272\345\267\245\347\273\221\345\256\232.png);}\n"
"QPushButton:pressed{border-image: url(:/Images/\345\210\207\345\233\276/\344\272\272\345\267\245\347\273\221\345\256\232-\346\213\267\350\264\235.png);}"));
        pushButton_intercept = new QPushButton(widget_step1);
        pushButton_intercept->setObjectName(QString::fromUtf8("pushButton_intercept"));
        pushButton_intercept->setGeometry(QRect(507, 0, 163, 52));
        pushButton_intercept->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/Images/\345\210\207\345\233\276/\346\213\246----\346\210\252.png);}\n"
"QPushButton:pressed{border-image: url(:/Images/\345\210\207\345\233\276/\346\213\246----\346\210\252-\346\213\267\350\264\235.png);}"));
        widget_step3 = new QWidget(widget_flowback);
        widget_step3->setObjectName(QString::fromUtf8("widget_step3"));
        widget_step3->setGeometry(QRect(0, 702, 800, 200));
        locationsLabel_2 = new QLabel(widget_step3);
        locationsLabel_2->setObjectName(QString::fromUtf8("locationsLabel_2"));
        locationsLabel_2->setGeometry(QRect(52, 48, 311, 41));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        locationsLabel_2->setFont(font4);
        locationsLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_intercept1 = new QPushButton(widget_step3);
        pushButton_intercept1->setObjectName(QString::fromUtf8("pushButton_intercept1"));
        pushButton_intercept1->setGeometry(QRect(90, 148, 163, 52));
        pushButton_intercept1->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/Images/\345\210\207\345\233\276/1\345\217\267\345\207\206\345\244\207\344\275\215-\346\213\267\350\264\235-2.png);}\n"
"QPushButton:pressed{border-image: url(:/Images/\345\210\207\345\233\276/1\345\217\267\345\207\206\345\244\207\344\275\215-\346\213\267\350\264\235-3.png);}"));
        pushButton_intercept2 = new QPushButton(widget_step3);
        pushButton_intercept2->setObjectName(QString::fromUtf8("pushButton_intercept2"));
        pushButton_intercept2->setGeometry(QRect(319, 148, 163, 52));
        pushButton_intercept2->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/Images/\345\210\207\345\233\276/2\345\217\267\345\207\206\345\244\207\344\275\215-\346\213\267\350\264\235-2.png);}\n"
"QPushButton:pressed{border-image: url(:/Images/\345\210\207\345\233\276/2\345\217\267\345\207\206\345\244\207\344\275\215-\346\213\267\350\264\235-3.png);}"));
        pushButton_intercept3 = new QPushButton(widget_step3);
        pushButton_intercept3->setObjectName(QString::fromUtf8("pushButton_intercept3"));
        pushButton_intercept3->setGeometry(QRect(547, 148, 163, 52));
        pushButton_intercept3->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/Images/\345\210\207\345\233\276/3\345\217\267\345\207\206\345\244\207\344\275\215-\346\213\267\350\264\235-2.png);}\n"
"QPushButton:pressed{border-image: url(:/Images/\345\210\207\345\233\276/3\345\217\267\345\207\206\345\244\207\344\275\215-\346\213\267\350\264\235-3.png);}"));
        widget_msg = new QWidget(centralwidget);
        widget_msg->setObjectName(QString::fromUtf8("widget_msg"));
        widget_msg->setGeometry(QRect(0, 0, 800, 1280));
        widget_msg->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-color: rgba(0, 0, 0, 0.5);"));
        widget_box = new QWidget(widget_msg);
        widget_box->setObjectName(QString::fromUtf8("widget_box"));
        widget_box->setGeometry(QRect(124, 467, 552, 345));
        widget_box->setStyleSheet(QString::fromUtf8("background: 0;\n"
"image: url(:/Images/\345\210\207\345\233\276/\345\260\217\345\274\271\347\252\227BG.png);"));
        label_text = new QLabel(widget_box);
        label_text->setObjectName(QString::fromUtf8("label_text"));
        label_text->setGeometry(QRect(0, 80, 552, 150));
        QFont font5;
        font5.setPointSize(20);
        label_text->setFont(font5);
        label_text->setStyleSheet(QString::fromUtf8("image: 0;\n"
"background: 0;\n"
"color: rgb(255, 255, 255);"));
        label_text->setAlignment(Qt::AlignCenter);
        msgButton_X1 = new QPushButton(widget_box);
        msgButton_X1->setObjectName(QString::fromUtf8("msgButton_X1"));
        msgButton_X1->setGeometry(QRect(485, 40, 30, 30));
        msgButton_X1->setStyleSheet(QString::fromUtf8("QPushButton{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\345\205\263--\351\227\255-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\345\205\263--\351\227\255-\346\213\267\350\264\235-\346\214\211\344\270\213.png);}"));
        msgButton_X2 = new QPushButton(widget_box);
        msgButton_X2->setObjectName(QString::fromUtf8("msgButton_X2"));
        msgButton_X2->setGeometry(QRect(206, 230, 140, 40));
        msgButton_X2->setStyleSheet(QString::fromUtf8("QPushButton{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\347\241\256--\350\256\244-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\347\241\256--\350\256\244-\346\213\267\350\264\235-2.png);}"));
        msgButton_Reject = new QPushButton(widget_box);
        msgButton_Reject->setObjectName(QString::fromUtf8("msgButton_Reject"));
        msgButton_Reject->setGeometry(QRect(90, 230, 140, 40));
        msgButton_Reject->setStyleSheet(QString::fromUtf8("QPushButton{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\345\217\226\346\266\210-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\345\217\226\346\266\210-\346\213\267\350\264\235-2.png);}"));
        msgButton_Accept = new QPushButton(widget_box);
        msgButton_Accept->setObjectName(QString::fromUtf8("msgButton_Accept"));
        msgButton_Accept->setGeometry(QRect(322, 230, 140, 40));
        msgButton_Accept->setStyleSheet(QString::fromUtf8("QPushButton{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\347\241\256--\350\256\244-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\347\241\256--\350\256\244-\346\213\267\350\264\235-2.png);}"));
        widget_dlg = new QWidget(centralwidget);
        widget_dlg->setObjectName(QString::fromUtf8("widget_dlg"));
        widget_dlg->setGeometry(QRect(0, 0, 800, 1280));
        widget_dlg->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-color: rgba(0, 0, 0, 0.5);"));
        widget_dialog = new QWidget(widget_dlg);
        widget_dialog->setObjectName(QString::fromUtf8("widget_dialog"));
        widget_dialog->setGeometry(QRect(150, 462, 500, 356));
        widget_dialog->setStyleSheet(QString::fromUtf8("background: 0;\n"
"image: url(:/Images/\345\210\207\345\233\276/\345\244\247\345\274\271\347\252\227BG.png);"));
        titleLabel = new QLabel(widget_dialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(0, 0, 500, 65));
        QFont font6;
        font6.setPointSize(30);
        titleLabel->setFont(font6);
        titleLabel->setStyleSheet(QString::fromUtf8("image: 0;\n"
"background: 0;\n"
"color: rgb(0, 228, 255);"));
        titleLabel->setAlignment(Qt::AlignCenter);
        optionsTableWidget = new QTableWidget(widget_dialog);
        optionsTableWidget->setObjectName(QString::fromUtf8("optionsTableWidget"));
        optionsTableWidget->setGeometry(QRect(30, 100, 440, 210));
        optionsTableWidget->setColumnCount(0);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_currentTime->setText(QApplication::translate("MainWindow", "00:00:00", nullptr));
        label_netStat->setText(QString());
        stateCam_x_2->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\345\217\267\357\274\232v1.0.0", nullptr));
        Button_return->setText(QString());
        label_tips->setText(QString());
        flowQueryLineEdit->setText(QString());
        flowQueryLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\201\344\273\266\345\217\267 \346\210\226 \350\210\252\347\217\255\345\217\267#\345\272\217\345\217\267", nullptr));
        flowQueryPushButton->setText(QString());
        passengerNameLabel_1->setText(QApplication::translate("MainWindow", "\346\227\205\345\256\242\345\247\223\345\220\215\357\274\232", nullptr));
        passengerNameLabel_2->setText(QString());
        passengerFlightLabel_1->setText(QApplication::translate("MainWindow", "\350\210\252 \347\217\255 \345\217\267\357\274\232", nullptr));
        passengerFlightLabel_2->setText(QString());
        passengerCodeLabel_1->setText(QApplication::translate("MainWindow", "\350\257\201 \344\273\266 \345\217\267\357\274\232", nullptr));
        passengerCodeLabel_2->setText(QString());
        seatIdLabel_1->setText(QApplication::translate("MainWindow", "\345\272\247 \344\275\215 \345\217\267\357\274\232", nullptr));
        seatIdLabel_2->setText(QString());
        boardingNumberLabel_1->setText(QApplication::translate("MainWindow", "\345\272\217    \345\217\267\357\274\232", nullptr));
        boardingNumberLabel_2->setText(QString());
        locationsLabel_1->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\345\257\271\345\272\224\347\232\204\345\207\206\345\244\207\344\275\215\357\274\232", nullptr));
        pushButton_location1->setText(QString());
        pushButton_location2->setText(QString());
        pushButton_location3->setText(QString());
        pushButton_bind->setText(QString());
        pushButton_intercept->setText(QString());
        locationsLabel_2->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\345\257\271\345\272\224\347\232\204\345\207\206\345\244\207\344\275\215\357\274\232", nullptr));
        pushButton_intercept1->setText(QString());
        pushButton_intercept2->setText(QString());
        pushButton_intercept3->setText(QString());
        label_text->setText(QApplication::translate("MainWindow", "\346\230\257 \345\220\246 \347\241\256 \350\256\244 \357\274\237", nullptr));
        msgButton_X1->setText(QString());
        msgButton_X2->setText(QString());
        msgButton_Reject->setText(QString());
        msgButton_Accept->setText(QString());
        titleLabel->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\346\227\205\345\256\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

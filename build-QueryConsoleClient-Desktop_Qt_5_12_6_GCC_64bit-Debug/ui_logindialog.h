/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QFrame *frame_error;
    QWidget *we;
    QLabel *label;
    QPushButton *pushButton_yes;
    QPushButton *pushButton_exit;
    QFrame *frame_input;
    QWidget *widget_2;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;
    QLabel *label_background;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(800, 1280);
        LoginDialog->setFocusPolicy(Qt::NoFocus);
        LoginDialog->setStyleSheet(QString::fromUtf8(""));
        frame_error = new QFrame(LoginDialog);
        frame_error->setObjectName(QString::fromUtf8("frame_error"));
        frame_error->setGeometry(QRect(0, 0, 800, 1280));
        frame_error->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-color: rgba(0, 0, 0, 0.5);"));
        frame_error->setFrameShape(QFrame::StyledPanel);
        frame_error->setFrameShadow(QFrame::Raised);
        we = new QWidget(frame_error);
        we->setObjectName(QString::fromUtf8("we"));
        we->setGeometry(QRect(124, 468, 552, 345));
        we->setStyleSheet(QString::fromUtf8("image: url(:/Images/\345\210\207\345\233\276/\345\274\271\347\252\227BG.png);\n"
"background: transparent;"));
        label = new QLabel(we);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 130, 552, 50));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("image: 0;\n"
"background: 0;\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        pushButton_yes = new QPushButton(we);
        pushButton_yes->setObjectName(QString::fromUtf8("pushButton_yes"));
        pushButton_yes->setGeometry(QRect(206, 230, 140, 40));
        pushButton_yes->setFocusPolicy(Qt::StrongFocus);
        pushButton_yes->setStyleSheet(QString::fromUtf8("QPushButton{image: 0; border-image: url(:/Images/\345\210\207\345\233\276/\347\241\256--\350\256\244-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{image: 0; border-image: url(:/Images/\345\210\207\345\233\276/\347\241\256--\350\256\244-\346\213\267\350\264\235-2.png);}"));
        pushButton_exit = new QPushButton(we);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(485, 40, 30, 30));
        pushButton_exit->setFocusPolicy(Qt::StrongFocus);
        pushButton_exit->setStyleSheet(QString::fromUtf8("QPushButton{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\345\205\263--\351\227\255-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{image: 0; background: 0; border-image: url(:/Images/\345\210\207\345\233\276/\345\205\263--\351\227\255-\346\213\267\350\264\235-\346\214\211\344\270\213.png);}"));
        frame_input = new QFrame(LoginDialog);
        frame_input->setObjectName(QString::fromUtf8("frame_input"));
        frame_input->setGeometry(QRect(0, 0, 800, 1280));
        QFont font1;
        font1.setPointSize(11);
        frame_input->setFont(font1);
        frame_input->setStyleSheet(QString::fromUtf8("border: 0;"));
        frame_input->setFrameShape(QFrame::StyledPanel);
        frame_input->setFrameShadow(QFrame::Raised);
        widget_2 = new QWidget(frame_input);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(186, 793, 428, 72));
        widget_2->setStyleSheet(QString::fromUtf8("image: url(:/Images/\345\210\207\345\233\276/\345\234\206\350\247\222\347\237\251\345\275\242-1.png);"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 80, 72));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/Images/\345\210\207\345\233\276/mima-(2).png);"));
        lineEdit_password = new QLineEdit(widget_2);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(70, 0, 350, 72));
        QFont font2;
        font2.setPointSize(30);
        lineEdit_password->setFont(font2);
        lineEdit_password->setStyleSheet(QString::fromUtf8("image: 0;\n"
"color: rgb(255, 255, 255);\n"
"background:transparent;\n"
"border-style:none;"));
        pushButton_login = new QPushButton(frame_input);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(289, 983, 222, 72));
        QFont font3;
        font3.setPointSize(40);
        pushButton_login->setFont(font3);
        pushButton_login->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-color: rgb(13, 225, 255);\n"
"border-radius:10px;"));
        label_background = new QLabel(LoginDialog);
        label_background->setObjectName(QString::fromUtf8("label_background"));
        label_background->setGeometry(QRect(0, 0, 800, 1280));
        label_background->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/\345\210\207\345\233\276/BG2.png);"));
        label_background->raise();
        frame_input->raise();
        frame_error->raise();

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201\351\224\231\350\257\257\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245\357\274\201", nullptr));
        pushButton_yes->setText(QString());
        pushButton_exit->setText(QString());
        label_2->setText(QString());
        lineEdit_password->setText(QString());
        lineEdit_password->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201", nullptr));
        pushButton_login->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        label_background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H

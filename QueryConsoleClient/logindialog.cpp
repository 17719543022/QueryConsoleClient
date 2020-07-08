#include "logindialog.h"
#include "ui_logindialog.h"
#include "settings.h"
#include "QDebug"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setModal(false);

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    this->initUI();

    QByteArray userBase64 = LocalSettings::instance()->value("System/username", "YWRtaW4=").toByteArray();
    QByteArray passwdBase64 = LocalSettings::instance()->value("System/password", "YWRtaW4=").toByteArray();
    m_username = QByteArray::fromBase64(userBase64);
    m_password = QByteArray::fromBase64(passwdBase64);

    qDebug() << "m_username: " << m_username;
    qDebug() << "m_password: " << m_password;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::initUI()
{
    ui->frame_error->hide();
    ui->lineEdit_password->setFocus();
}

void LoginDialog::on_pushButton_login_clicked()
{
    QString username = "admin";
    QString password = ui->lineEdit_password->text();

    if ((username == m_username) && (password == m_password)) {
        ui->lineEdit_password->clear();
        accept();
        initUI();
    } else {
        ui->frame_error->show();
        ui->pushButton_yes->setFocus();
    }
}

void LoginDialog::on_pushButton_exit_clicked()
{
    // 不清空用户名和密码
    ui->frame_error->hide();
    ui->pushButton_login->setFocus();
}

void LoginDialog::on_pushButton_yes_clicked()
{
    this->initUI();
}

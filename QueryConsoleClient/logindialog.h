#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    void initUI();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_yes_clicked();

private:
    Ui::LoginDialog *ui;
    QString m_username;
    QString m_password;
};

#endif // LOGINDIALOG_H

#include "mainwindow.h"
#include <QApplication>
#include "CardReader/paramdef.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<CardDataInfo>("CardDataInfo");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

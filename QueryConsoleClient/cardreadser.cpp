#include "cardreadser.h"
#include <QDebug>
#include <QCoreApplication>
#include <QFile>
#include <QPixmap>
#include <QBuffer>
#include "settings.h"

CardReadSer::CardReadSer(QObject *parent) : QObject(parent)
{
    m_readInterval = LocalSettings::instance()->value("IdCard/CardReadInterval").toString();

    this->Init();
}

CardReadSer::~CardReadSer()
{

}

int CardReadSer::Init()
{
    int res=-1;
    try {
        QByteArray temp=m_readInterval.toLatin1();
        res=IDCardSDKInit(DeviceType::JingLun,temp.data());
        SetIDCardReadCB(IDCardReadCB,this,IDCardReadOnlineCB,IDCardReadOfflineCB);
        return res;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return res;
    }
}

int CardReadSer::UnInit()
{
    int res=-1;
    try {
        IDCardSDKRelease();
        res=0;
        return res;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return res;
    }
}

void CardReadSer::IDCardReadCB(IDCardReadInfos *idCardReadInfos, void *userData)
{
    try {
        CardDataInfo cdi;
        cdi.cardType=idCardReadInfos->idType;
        cdi.idCard=QString::fromLocal8Bit(idCardReadInfos->code).replace(QString(" "),QString(""));
        cdi.nameZh=QString::fromLocal8Bit(idCardReadInfos->name).replace(QString(" "),QString(""));
        cdi.nameEn=QString::fromLocal8Bit(idCardReadInfos->eName).replace(QString(" "),QString(""));
        cdi.sex=2;
        cdi.age=0;
        QString sexStr=QString::fromLocal8Bit(idCardReadInfos->gender).replace(QString(" "),QString(""));
        if(sexStr.contains(QString("女"))){
            cdi.sex=0;
        }else if(sexStr.contains(QString("男"))){
            cdi.sex=1;
        }
        cdi.birthDate=QString::fromLocal8Bit(idCardReadInfos->birthDay).replace(QString(" "),QString(""));
        cdi.address=QString::fromLocal8Bit(idCardReadInfos->address).replace(QString(" "),QString(""));
        cdi.expireStart=QString::fromLocal8Bit(idCardReadInfos->expireStart).replace(QString(" "),QString(""));
        cdi.expireEnd=QString::fromLocal8Bit(idCardReadInfos->expireEnd).replace(QString(" "),QString(""));
        cdi.nationality=QString::fromLocal8Bit(idCardReadInfos->nation).replace(QString(" "),QString(""));
        cdi.ethnic=QString::fromLocal8Bit(idCardReadInfos->folk).replace(QString(" "),QString(""));
        cdi.contactWay=QString("");
        QString photoPath=QString("%1/photo_JingLun.bmp").arg(QCoreApplication::applicationDirPath());
        QPixmap image(photoPath);
        QByteArray bytearray;
        QBuffer buffer(&bytearray);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer,"jpg");
        QFile file(photoPath);
        file.remove();
        cdi.cardPhoto=QByteArray(bytearray);

        qInfo()<<QString("IDCardReadCB:%1 %2 %3 %4 %5").arg(cdi.nameZh).arg(cdi.nameEn).arg(cdi.idCard).arg(cdi.birthDate).arg(cdi.expireEnd);

        emit static_cast<CardReadSer*>(userData)->CardDataResult(cdi);
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
}

void CardReadSer::IDCardReadOnlineCB(void *userData)
{
    try {
        auto cardReadSer=static_cast<CardReadSer*>(userData);
        DevStatDisplay dsd;
        dsd.dType=DTCardReader;
        dsd.dStatus=DSNormal;
        emit cardReadSer->DeviceStatusResult(dsd);
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
}

void CardReadSer::IDCardReadOfflineCB(void *userData)
{
    try {
        auto cardReadSer=static_cast<CardReadSer*>(userData);
        DevStatDisplay dsd;
        dsd.dType=DTCardReader;
        dsd.dStatus=DSFault;
        emit cardReadSer->DeviceStatusResult(dsd);
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
}

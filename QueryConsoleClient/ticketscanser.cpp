#include "ticketscanser.h"
#include <QTimer>
#include <QTime>
#include <QDate>
#include <QDateTime>
#include "settings.h"

TicketScanSer::TicketScanSer(QObject *parent) : QObject(parent)
{
    m_isOpen=false;
    m_port = LocalSettings::instance()->value("Scanner/ScanGunPort").toString();
    m_readInterval = LocalSettings::instance()->value("Scanner/ScanReadInterval").toInt();
    m_curBTI.flightNo.clear();

    this->Init();
}

TicketScanSer::~TicketScanSer()
{
}

int TicketScanSer::Init()
{
    int res=-1;
    try {
        m_sp=new QSerialPort;
        m_sp->setPortName(m_port);
        m_sp->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
        m_sp->setDataBits(QSerialPort::Data8);
        m_sp->setParity(QSerialPort::NoParity);
        m_sp->setStopBits(QSerialPort::OneStop);
        m_sp->setFlowControl(QSerialPort::NoFlowControl);
        m_sp->close();

        if(m_sp->open(QIODevice::ReadWrite))
        {
            m_isOpen=true;
            m_readConnection=connect(m_sp,&QSerialPort::readyRead,this,&TicketScanSer::ReadData);
            m_testTimer=new QTimer(this);
            m_timerConnection=connect(m_testTimer,&QTimer::timeout,this,&TicketScanSer::TestOnline);
            m_dataTimer=new QTimer(this);
            m_dataConnection=connect(m_dataTimer,&QTimer::timeout,this,&TicketScanSer::ReadDataTimeout);
            m_testTimer->start(5000);
            m_readTimer=new QTimer(this);
            m_readdataConnection=connect(m_readTimer,&QTimer::timeout,this,&TicketScanSer::ReadTimeout);
            m_readTimer->start(m_readInterval);

            res=0;
            return res;
        }else{
            UnInit();
            return res;
        }
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return res;
    }
}

int TicketScanSer::UnInit()
{
    int res=-1;
    try {
        if(m_testTimer!=nullptr){
            m_testTimer->stop();
            m_testTimer=nullptr;
        }
        if(m_dataTimer!=nullptr){
            m_dataTimer->stop();
            m_dataTimer=nullptr;
        }
        if(m_readTimer!=nullptr){
            m_readTimer->stop();
            m_readTimer=nullptr;
        }

        m_isOpen=false;
        if(m_sp!=nullptr)
        {
            m_sp->clear();
            m_sp->close();
            m_sp=nullptr;
        }

        if(m_readConnection!=nullptr){
            disconnect(m_readConnection);
        }
        if(m_timerConnection!=nullptr){
            disconnect(m_timerConnection);
        }
        if(m_dataConnection!=nullptr){
            disconnect(m_dataConnection);
        }
        if(m_readdataConnection!=nullptr){
            disconnect(m_readdataConnection);
        }
        res=0;
        return res;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return res;
    }
}

void TicketScanSer::TestOnline()
{
    try {
        {
            m_mutex.lock();
            if(m_isOpen && m_sp!=nullptr){
                if(!m_sp->isOpen()){
                    m_isOpen=false;
                }
            }
            if(!m_isOpen && m_sp!=nullptr){
                m_sp->close();
                QThread::msleep(20);
                if(m_sp->open(QIODevice::ReadWrite)){
                    m_isOpen=true;
                }
            }
            m_mutex.unlock();
        }
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
}

void TicketScanSer::ReadData()
{
    try {
        if(m_isOpen){
           m_mutex.lock();
           m_buffer.append(m_sp->readAll());
           m_mutex.unlock();
        }
        if(m_dataTimer!=nullptr && !m_dataTimer->isActive()){
            m_dataTimer->start(20);
        }
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
}

void TicketScanSer::ReadDataTimeout()
{
    try {
        if(m_dataTimer!=nullptr && m_dataTimer->isActive()){
            m_dataTimer->stop();
        }

        QByteArray buffer;
        m_mutex.lock();
        buffer=QByteArray(m_buffer);
        m_buffer.clear();
        m_mutex.unlock();

        buffer=buffer.replace('\r',"").replace('\t',"").replace('\n',"");

        qInfo()<<QString("TicketScanSer:%1").arg(QString::fromLocal8Bit(buffer));

        if(!buffer.isEmpty() && buffer.size()>15){
            if(buffer.size()>=60){
                QByteArray startPortBytes=buffer.mid(30,3);
                QByteArray endPortBytes=buffer.mid(33,3);
                QByteArray flightNoBytes=buffer.mid(36,7);
                QByteArray flightDayBytes=buffer.mid(44,3);
                QByteArray seatIdBytes=buffer.mid(49,3);
                QByteArray boardingNumberBytes=buffer.mid(53,3);

                QDate date(QDate::currentDate().year(),1,1);
                QDate ndate=date.addDays(QString(flightDayBytes).toInt()-1);

                m_mutexread.lock();
                {
                    m_curBTI.flightNo=QString(flightNoBytes).replace(" ","");
                    m_curBTI.flightDay=QString("%1").arg(ndate.day(), 2, 10, QLatin1Char('0')).replace(" ","");
                    m_curBTI.seatId=QString(seatIdBytes).replace(" ","");
                    m_curBTI.boardingNumber=QString(boardingNumberBytes).replace(" ","");
                    m_curBTI.startPort=QString(startPortBytes).replace(" ","");
                    m_curBTI.endPort=QString(endPortBytes).replace(" ","");
                }
                m_mutexread.unlock();


            }else if(buffer.size()==18){
                QByteArray flightNoBytes=buffer.mid(0,6);
                QByteArray flightDayBytes=buffer.mid(7,2);
                QByteArray seatIdBytes=buffer.mid(9,3);
                QByteArray startPortBytes=buffer.mid(12,3);
                QByteArray boardingNumberBytes=buffer.mid(15,3);

                m_mutexread.lock();
                {
                    m_curBTI.flightNo=QString(flightNoBytes).replace(" ","");
                    m_curBTI.flightDay=QString(flightDayBytes).replace(" ","");
                    m_curBTI.seatId=QString(seatIdBytes).replace(" ","");
                    m_curBTI.boardingNumber=QString(boardingNumberBytes).replace(" ","");
                    m_curBTI.startPort=QString(startPortBytes).replace(" ","");
                    m_curBTI.endPort="";
                }
                m_mutexread.unlock();
            }
            else if(buffer.size()==16){
                QByteArray flightNoBytes=buffer.mid(0,6);
                QByteArray flightDayBytes=buffer.mid(7,2);
                QByteArray startPortBytes=buffer.mid(10,3);
                QByteArray boardingNumberBytes=buffer.mid(13,3);

                m_mutexread.lock();
                {
                    m_curBTI.flightNo=QString(flightNoBytes).replace(" ","");
                    m_curBTI.flightDay=QString(flightDayBytes).replace(" ","");
                    m_curBTI.seatId="";
                    m_curBTI.boardingNumber=QString(boardingNumberBytes).replace(" ","");
                    m_curBTI.startPort=QString(startPortBytes).replace(" ","");
                    m_curBTI.endPort="";
                }
                m_mutexread.unlock();
            }
        }
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
}

void TicketScanSer::ReadTimeout()
{
    try {
        BoardingTicketInfo bti;
        bti.flightNo.clear();

        m_mutexread.lock();
        {
            if(!m_curBTI.flightNo.isNull() &&  !m_curBTI.flightNo.isEmpty()){
                bti=m_curBTI;
                m_curBTI.flightNo.clear();
            }
        }
        m_mutexread.unlock();

        if(!bti.flightNo.isNull() &&  !bti.flightNo.isEmpty()){
            emit ScanReadDataResult(bti);
            qInfo()<<QString("TicketScanSer ReadTimeout:%1 %2%3%4%5").arg(bti.flightNo).arg(bti.flightDay).arg(bti.seatId).arg(bti.startPort).arg(bti.boardingNumber);
        }

    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
}


#ifndef TICKETSCANSER_H
#define TICKETSCANSER_H

#include "paramdef.h"
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QTimer>

class TicketScanSer : public QObject
{
    Q_OBJECT
public:
    explicit TicketScanSer(QObject *parent = nullptr);
    virtual ~TicketScanSer(void);
    static TicketScanSer* instance();

public:
    int Init();
    int UnInit();

signals:
    void ScanReadDataResult(const BoardingTicketInfo& btInfo);

private slots:
    void TestOnline();
    void ReadData();
    void ReadDataTimeout();
    void ReadTimeout();

private:
    QMetaObject::Connection m_readConnection;
    QMetaObject::Connection m_timerConnection;
    QMetaObject::Connection m_dataConnection;
    QMetaObject::Connection m_readdataConnection;

    QString m_port;
    QMutex m_mutex;
    QSerialPort *m_sp;
    QTimer *m_testTimer;
    QTimer *m_dataTimer;
    QByteArray m_buffer;

    QTimer *m_readTimer;
    int m_readInterval;
    BoardingTicketInfo m_curBTI;
    QMutex m_mutexread;

public:
    bool m_isOpen;
};

inline TicketScanSer* TicketScanSer::instance()
{
    static TicketScanSer tsSer;
    return &tsSer;
}

Q_DECLARE_METATYPE(BoardingTicketInfo)

#endif // TICKETSCANSER_H

#ifndef CARDREADSER_H
#define CARDREADSER_H

#include <dlfcn.h> /* 必须加这个头文件 */
#include "CardReader/DataStructDefine.h"
#include "CardReader/IDCardRead_RecogSDK.h"
#include "CardReader/paramdef.h"
#include <QObject>
#include <QTimer>

class CardReadSer : public QObject
{
    Q_OBJECT
public:
    explicit CardReadSer(QObject *parent = nullptr);
    virtual ~CardReadSer(void);
public:
    static CardReadSer* instance();

public:
    int Init();
    int UnInit();

signals:
    void CardDataResult(const CardDataInfo& cardData);
    void DeviceStatusResult(const DevStatDisplay& dsd);

private:
    /// \breif 读卡器响应后回调函数
    /// 读卡器响应回调，设置该回调函数后身份证读卡器读取数据后自动响应，返回证件信息
    /// \param idCardReadInfos[out]-身份证信息
    /// \param userData[out]-用户信息
    static void  IDCardReadCB(IDCardReadInfos *idCardReadInfos ,void *userData);

    /// \brief 读卡器上线事件
    /// \param userData[out]-用户信息
    static void  IDCardReadOnlineCB(void *userData);
    /// \brief 读卡器下线事件
    /// \param userData[out]-用户信息
    static void  IDCardReadOfflineCB(void *userData);

private:
    QString m_readInterval;

};

inline CardReadSer* CardReadSer::instance()
{
    static CardReadSer crSer;
    return &crSer;
}

Q_DECLARE_METATYPE(CardDataInfo)
Q_DECLARE_METATYPE(DevStatDisplay)

#endif // CARDREADSER_H

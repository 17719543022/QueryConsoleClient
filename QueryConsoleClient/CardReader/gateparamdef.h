#ifndef GATEPARAMDEF_H
#define GATEPARAMDEF_H

#include <QDateTime>
//函数返回错误码
#define GP_SUCCESS      0   //成功
#define GP_FAILURE		101	//失败
#define GP_PARAM_ERR    102 //参数设置错误
#define GP_OTHER_ERR	109	//其他错误

//闸机相关参数
enum GateMessageType{
    GateMsg_NormalQuery=0,      //主动查询返回
    GateMsg_AfterDoorOpen,      //开门后延迟返回
    GateMsg_AfterDoorClose,     //主动关门返回
    GateMsg_WorkStateChanged,   //闸机工作状体变化返回,或主动推送
    GateMsg_WorkModeChanged,    //闸机工作模式变化返回
    GateMsg_wrSerialTimeout,    //写指令后，超时未收到数据返回
};

enum GateDoorEvents{
    GateDoorNothing = 0, //待定
    GateDoorAutoPass,    //正常通过
    GateDoorHandPass,    //手动开门正常通过
    GateDoorTimeOut,     //超时未通过
    GateDoorTailed       //发生尾随
};
enum GateDoorStatus{
    GateDoorClose = 0,   //关闭
    GateDoorOpen         //打开
};
enum GateChannelStatus{
    GateChannelNobody = 0,  //无人
    GateChannelBody         //有人
};
enum GateAlarmStatus{
    GateAlarmNormal = 0,     //正常//no Warning
    GateAlarmForwardTrip,    //正向闯闸
    GateAlarmReverseTrip,    //逆向闯闸
    GateAlarmReverseEntry,   //逆向进入
    GateAlarmTailed,         //尾随
    GateAlarmExit            //未完全通过退出,暂不用
};
enum GateWorkStatus{
    GateWorkNormal = 0, //正常
    GateWorkPause,      //暂停
    GateWorkKeepClose,  //常闭
    GateWorkKeepOpen    //常开
};
enum GateWorkMode{
    GateBoardingMode = 0, //登机模式
    GateCollectMode,      //采集模式
    GateStandbyMode,      //daiji模式
};

enum GateFaultStatus{
    GateFaultNormal = 0, //正常
    GateFaultFault,      //故障
};

enum GateDoorType{
    GateDoorA = 0,  //第一扇门A门
    GateDoorB,      //第二扇门B门
    GateDoorC,      //第3扇门C门
};

/*控制门消息结构体*/
typedef struct ConctrolDoorInfo_S
{
    GateDoorType gdType;
    GateDoorStatus gdStatus;
}ConctrolDoorInfo;

/*闸机消息结构体*/
typedef struct GateMessage_s
{
    GateMessageType	gmType;         //闸机消息类型
    GateDoorStatus	gdAStatus;      //闸机A门状态
    GateDoorStatus	gdBStatus;      //闸机B门状态
    GateDoorStatus	gdCStatus;      //闸机C门状态
    GateChannelStatus gcStatus;     //闸机通道内状态
    GateDoorEvents	gdAEvents;      //闸机A门通行事件
    GateDoorEvents	gdBEvents;      //闸机B门通行事件
    GateDoorEvents	gdCEvents;      //闸机C门通行事件
    GateAlarmStatus	gaStatus;       //闸机报警状态
    GateWorkStatus	gwStatus;       //闸机工作状态
    GateWorkMode    gwMode;         //闸机工作模式
    GateFaultStatus gfStatus;       //闸机故障状态
    QDateTime gmTime;
    /*默认构造函数*/
    GateMessage_s()
    {
        gmType=GateMsg_wrSerialTimeout;
        gdAStatus=GateDoorClose;
        gdBStatus=GateDoorClose;
        gdCStatus=GateDoorClose;
        gcStatus=GateChannelNobody;
        gdAEvents=GateDoorNothing;
        gdBEvents=GateDoorNothing;
        gdCEvents=GateDoorNothing;
        gaStatus=GateAlarmNormal;
        gwStatus=GateWorkNormal;
        gwMode=GateBoardingMode;
        gfStatus=GateFaultNormal;
        gmTime=QDateTime::currentDateTime();
    }
}GateMessage;

class GateCmdDictionary{
public:
    //闸机发送命令集

    static const char OpenADoorCmd[];       //开A门命令
    static const char CloseADoorCmd[];       //关A门命令
    static const char OpenBDoorCmd[];       //开B门命令
    static const char CloseBDoorCmd[];       //关B门命令
    static const char OpenCDoorCmd[];       //开C门命令
    static const char CloseCDoorCmd[];       //关C门命令
    static const char QueryCmd[];           //查询命令
    static const char NormalStatusCmd[];    //正常工作状态命令
    static const char PauseStatusCmd[];     //暂停工作状态命令
    static const char KeepCloseStatusCmd[]; //常闭工作状态命令
    static const char KeepOpenStatusCmd[];  //常开工作状态命令
    static const char BoardingModeCmd[];    //登机模式命令
    static const char CollectModeCmd[];     //采集模式命令
    static const char StandbyModeCmd[];     //daiji模式命令

    //闸机接收命令集
    static const char CharStatusResultHead[];
    static const char CharWorkStatusResultHead[];
    static const char Char0x00[];
    static const char Char0x01[];
    static const char Char0x02[];
    static const char Char0x03[];
    static const char Char0x04[];
    static const char Char0x05[];
    static const char Char0x06[];
};

#endif // GATEPARAMDEF_H

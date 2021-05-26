#ifndef PARAMDEF_H
#define PARAMDEF_H

//#include "DetectOptimumDef.h"


#include <QDateTime>
#include <QJsonObject>
#include <QImage>

//工作模式
enum WorkMode{
    WMBoardingNoPlan=0, //登机无计划
    WMBoardingPlan,     //登机有计划
    WMBoarding,         //登机中
    WMCollectPlan,      //采集有计划
    WMCollecting,       //采集中
};

//工作类型
enum WorkType{
    WTFace=0,       //刷脸类型
    WTTicket,       //刷票类型
};

//设备类型
enum DeviceTypes{
    DTCamera1=0,    //摄像头1
    DTCamera2,      //摄像头2
    DTCardReader,   //读卡器
    DTScanningGun,  //扫描枪
    DTNetwork,      //网络
    DTGate,         //闸机
    DTWeight        //体重称
};

//设备状态
enum DeviceStatus{
    DSNormal=0,     //正常
    DSFault,        //故障
};



/*各类设备状态消息结构体*/
typedef struct DevStatDisplay_S
{
    DeviceTypes      dType;
    DeviceStatus    dStatus;
    QDateTime       dTime;

    DevStatDisplay_S()
    {
        dType=DTCardReader;
        dStatus=DSNormal;
        dTime=QDateTime::currentDateTime();
    }
}DevStatDisplay;

/*计划消息结构体*/
typedef struct PlanMessage_S
{
    QString         boardingGate;   //登机口
    QString         threeFlightNo;  //三字母航班号
    QString         twoFlightNo;    //两字母航班号（用于航班显示）
    QString         depTimeJ;       //预计起飞时间hhmm
    QString         depTimeS;       //实际起飞时间
    QString         boardingTime;   //实际登机时间hhmm
    QString         flightDate;     //起飞日期yyyyMMdd
    QString         midwayCode;     //经停编码
    QString         midwayName;     //经停名称
    QString         arrAirportCode; //到达站编码
    QString         arrAirportName; //到达站名称
    QString         depAirportCode; //离开站编码
    QString         depAirportName; //离开站名称
    QString         shareFltno;     //共享航班编码
    int             mode;           //计划模式 0-登机模式；1-采集模式
    int             collectType;    //mode=0 不关注；mode=1 0-经停采集；1-备降采集
    int             status;         //状态 mode=0，0-无登机计划；1-等待登机；2-开始登机；3-结束登机。mode=1,0-无采集计划（暂不用）；1-等待采集；2-开始采集；3-结束采集
    WorkType        type;           //0-人脸模式即常规模式；1表示刷票模式即快速模式
    QDateTime       recTime;        //消息接收时间

    PlanMessage_S()
    {
        boardingGate="";
        threeFlightNo="";
        twoFlightNo="";
        depTimeJ="";
        depTimeS="";
        boardingTime="";
        flightDate="";
        midwayCode="";
        midwayName="";
        arrAirportCode="";
        arrAirportName="";
        depAirportCode="";
        depAirportName="";
        shareFltno="";
        mode=-1;
        collectType=-1;
        status=-1;
        type=WorkType::WTFace;
        recTime=QDateTime::currentDateTime();
    }
}PlanMessage;


/*人脸位置消息结构体*/
typedef struct FacePosInfo_S
{
    int id;
    int left;
    int top;
    int right;
    int bottom;


    FacePosInfo_S()
    {
        id=-1;
        left=-1;
        top=-1;
        right=-1;
        bottom=-1;
    }
}FacePosInfo;

/*网络请求消息*/
/*登机自助识别请求消息结构体*/
typedef struct BoardingRecogData_S
{
    int             workType;       //0-人脸模式即常规模式；1表示刷票模式即快速模式
    QString         deviceCode;     //设备编号
    QString         boardingGate;   //登机口编号
    QString         gateNo;         //登机口区域编号
    QString         flightNo;       //航班号
    QString         flightDay;      //航班日（yyyyMMdd）
    int             IsVipChannel;   //是否贵宾通道（新增）1-是 0-不是
    QByteArray      faceImage;      //现场照
    QImage          faceImg;         //
    QByteArray      faceFeature;    //人脸特征
    FacePosInfo        faceInfo;       //人脸信息
    QString         boardingNumber; //登机序列号
    QString         seatId;         //座位号
    QString         mainFlightNo;   //主航班
    int             cardType;       //证件类型
    QString         cardId;         //证件号
    QString         nameZh;         //中文名称
    int             sex;            //性别
    QString         weight;         //旅客重量

    BoardingRecogData_S()
    {
        workType=-1;
        deviceCode="";
        boardingGate="";
        gateNo="";
        flightNo="";
        flightDay="";
        IsVipChannel=0;
        faceImage=nullptr;
        faceImg=QImage();
        boardingNumber="";
        seatId="";
        cardType=-1;
        cardId="";
        nameZh="";
        sex=2;
		weight="";
    }
}BoardingRecogData;

/*登机人工放行请求消息结构体*/
typedef struct BoardingManualData_S
{
    int             workType;       //0-人脸模式即常规模式；1表示刷票模式即快速模式
    QByteArray      scenePhoto;     //现场照
    QImage          faceImg;         //
    QString         deviceCode;     //设备编号
    QString         boardingGate;   //登机口编号
    QString         gateNo;         //登机口区域编号
    QString         flightNo;       //航班号
    QString         date;           //航班日（yyyyMMdd）
    QString         boardingNumber; //登机序列号
    QString         seatId;         //座位号
    QString         cardId;         //身份证
    QString         passengerName;  //旅客姓名
    int             sourceType;     //0-放行，1-报警
    int             controlType;    //是否控制闸机门 0-控制闸机门；1-不控制闸机门，直接透传
    QString         weight;         //旅客重量
    QString         startPort;      //
    QString         endPort;        //
    int             isFocus;        //0-非布控人员，1-是布控人员
    int             hasBaby;        //0-无小孩，1-有小孩
    int             moreTicket;     //0-无多张票，1-有多张票
    int             isSpecialChannel;     //0-正常，1-特殊通道
    int             secondBoardingPass;     //0-不是二次登机，1-是二次登机
    int             transferSourceType;     //-1, 非过站旅客，其他值为过站旅客；详细参数为：0,中转；1，经停；2、备降采集；3、中转人工放行；4、经停人工放行；5、备降人工放行；6、经停证件采集（新增）
    int             hasSecurityInfo;     //中转时判断是否出过安检区域：0-没有安检信息，1-有安检信息

    BoardingManualData_S()
    {
        workType=-1;
        scenePhoto=nullptr;
        faceImg=QImage();
        deviceCode="";
        boardingGate="";
        gateNo="";
        flightNo="";
        date="";
        boardingNumber="";
        seatId="";
        cardId="";
        sourceType=-1;
        controlType=-1;
        weight="0.000";
        startPort="";
        endPort="";
        isFocus=-1;
        hasBaby=-1;
        moreTicket=-1;
        isSpecialChannel=-1;
        secondBoardingPass=-1;
        transferSourceType=-1;
        hasSecurityInfo=-1;
    }
}BoardingManualData;


/*登机请求结果消息结构体,也是请求结果请求消息结构体*/
typedef struct BoardingInfoResult_S
{
    int             netStatus;      //登机口复核接口请求网络状态，0-故障；1-正常
    QString         deviceCode;     //设备编号
    QString         boardingGate;   //登机口编号
    QString         gateNo;         //登机口区域编号
    QString         flightNo;       //航班号
    QString         flightDay;      //航班日（yyyyMMdd）
    int             IsVipChannel;   //是否贵宾通道（新增）1-是 0-不是
    int             recheckType;    //0-人脸模式下人脸识别验证类型；1-人脸模式下人工验证类型；2-刷票模式下自助验证类型；3-刷票模式下人工验证类型
    int             result;         //recheckType =0，0-表示比对成功，1-表示比对失败。recheckType =1，0-表示人工放行，1-表示人工拦截。recheckType =2，0-表示验证成功，1-表示验证失败。recheckType =3，0-表示人工放行，1-表示人工拦截。
    int             recognizeType;  //recheckType=0或2时，比对成功后，0-旅客，1-保留，2-可疑人员，3-流程缺失，4-二次登机
    int             boardingStatus; //登机状态1-已登机0-未登机
    int             isCarryBaby;    //recognizeType=0,是否携带婴儿  1-携带，0-未携带
    int             isMultiTicket;  //recognizeType=0,本航班是否购买多张票，1-多张票，0-单张票
    int             isInterceptLabel; //recognizeType=0,是否人工标记拦截，1-已标记，0-未标记
    int             seatLabel;        //recognizeType=0,0-正常；1-有值机信息时是否更改座位号；2-无座位号
    QByteArray      faceImage;      //现场照
    QImage          faceImg;
    QString         boardingNumber; //登记序列号
    QString         seatId;         //座位号
    QString         mainFlightNo;   //主航班
    int             cardType;       //证件类型
    QString         cardId;         //证件号
    QString         nameZh;         //中文名称
    int             sex;            //性别
    QString         boardingId;     //32位UUID，登机口复核的流水表ID。
    int             isWrite;        //是否写入0-是；1-不是。
    QJsonObject      userInfo;       //recheckType =0或2 自动识别的旅客的具体信息
    QJsonObject      manualInfo;     //recheckType =1或3 人工干预后的旅客的具体信息
	QString      weight;		//旅客重量
    int          controlType;    //是否控制闸机门 0-控制闸机门；1-不控制闸机门，直接透传


    BoardingInfoResult_S()
    {
        netStatus=0;
        deviceCode="";
        boardingGate="";
        gateNo="";
        flightNo="";
        flightDay="";
        IsVipChannel=0;
        recheckType=-1;
        result=-1;
		recognizeType=-1;
        boardingStatus=-1;
        isCarryBaby=-1;
        isMultiTicket=-1;
        isInterceptLabel=-1;
        seatLabel=-1;
        faceImage=nullptr;
        faceImg=QImage();
        boardingNumber="";
        seatId="";
        cardType=-1;
        cardId="";
        nameZh="";
        sex=2;
        boardingId="";
        isWrite=-1;
        userInfo=QJsonObject();
        manualInfo=QJsonObject();
        weight="0.000";
        controlType=0;
    }
}BoardingInfoResult;



/*登机采集请求消息结构体,采集结果请求消息结构体，也是采集人工放行消息结构体*/
typedef struct BoardingcollectData_S
{
    int             workType;       //0-人脸模式即常规模式；1表示刷票模式即快速模式
    int             netStatus;      //登机口采集接口请求网络状态，0-故障；1-正常
    QString         deviceCode;     //设备编号
    QString         boardingGate;   //登机口编号
    QString         gateNo;         //登机口区域编号
    QString         flightNo;       //航班号
    QString         flightDay;      //航班日（dd）
    QString         boardingNumber; //登机序列号
    QString         seatId;         //座位号
    QString         startPort;      //出发港
    QString         endPort;        //目的站
    QString         cardId;         //
    QString         nameZh;         //
    QByteArray      faceImage;      //现场照
    QImage          faceImg;
    QByteArray      faceFeature;    //人脸特征
    int             sourceType;     //0,中转；1，经停；2、备降采集；3、中转人工放行；4、经停人工放行；5、备降人工放行；
    QString         mainFlightNo;   //主航班
    QByteArray      cardPhoto;      //证件照
    QByteArray      cardFeature;    //证件照特征
    QByteArray      largePhoto;     //大图照
    QString         facePst;        //大图人脸坐标
    int             isBaby;         //婴儿标记 0-不是婴儿，1-是婴儿
    QString         babyFlightNo;       //婴儿航班号
    QString         babyFlightDay;      //婴儿航班日（dd）
    QString         babyBoardingNumber; //婴儿登机序列号
    QString         babySeatId;         //婴儿座位号
    QString         babyStartPort;      //婴儿出发港
    QString         babyEndPort;        //婴儿目的站
    QString         babyCardId;         //
    QString         babyNameZh;         //
    int             babySourceType; //0,中转；1，经停；2、备降采集；3、中转人工放行；4、经停人工放行；5、备降人工放行；
    int             collectStep;    //采集步骤：0-采集模式下第一道门推送预先采集信息，不上传服务器，用于中控台预先显示，同时推送离港系统；1-采集模式下第二道门推送采集结果信息，上传服务器，用于中控台采集结果显示，不推送离港系统
    int             result;         //collectStep=1，即过闸机B门时的采集结果。人脸采集下采集结果： 0-成功，1-戴口罩，2-比对失败（带证件照）,3-不能自动抓拍超时强制抓拍。刷票采集下采集结果：0-成功
    int             collectType;    //采集类型 0-人脸采集下类似闸机A门刷票采集，即控制开A门；1-人脸采集下闸机B门前强制抓拍；2-刷票采集下类似闸机A门刷票采集，即控制开A门

    BoardingcollectData_S()
    {
        workType=-1;
        netStatus=0;
        deviceCode="";
        boardingGate="";
        gateNo="";
        flightNo="";
        flightDay="";
        boardingNumber="";
        seatId="";
        startPort="";
        endPort="";
        cardId="";
        nameZh="";
        faceImage=nullptr;
        faceImg=QImage();
        faceImage=nullptr;
        sourceType=-1;
        mainFlightNo="";
        cardPhoto=nullptr;
        cardFeature=nullptr;
        largePhoto=nullptr;
        facePst="";
        isBaby=0;
        babyCardId="";
        babyNameZh="";
        collectStep=0;
        result=-1;
        collectType=-1;
    }
}BoardingcollectData;



/*登机闸机控制请求消息结构体*/
typedef struct BoardingGateControlData_S
{
    QString         reqId;          //32位UUID
    int             gateWorkStatus; //闸机工作状态,0无状态、1正常、2暂停、3常闭、4常开
    int             gateDoorStatus; //闸机门状态，0无状态、1开A门、2关A门、3、开B门、4、关B门


    BoardingGateControlData_S()
    {
        reqId="";
        gateWorkStatus=0;
        gateDoorStatus=0;
    }
}BoardingGateControlData;



/*登机牌消息结构体*/
typedef struct BoardingTicketInfo_S
{
    QString         flightNo;       //航班号
    QString         flightDay;      //航班日（dd）
    QString         boardingNumber; //登机序列号
    QString         seatId;         //座位号
    QString         startPort;      //出发港(三字母)
    QString         endPort;        //目的站(三字母)

    BoardingTicketInfo_S()
    {

        flightNo="";
        flightDay="";
        boardingNumber="";
        seatId="";
        startPort="";
        endPort="";
    }
}BoardingTicketInfo;

/*证消息结构体*/
typedef struct CardDataInfo_S
{
    int cardType;                   //证件类型
    QString idCard;                 //证件号码
    QString nameZh;                 //中文姓名
    QString nameEn;                 //英文姓名
    int age;                        //年龄
    int sex;                        //性别 0-女，1-男
    QString birthDate;              //生日
    QString address;                //证件上面的地址
    QString expireStart;            //Ê±¼äyyyymmdd
    QString expireEnd;              //Ê±¼äyyyymmdd»òÕß³¤ÆÚ
    QString nationality;            //国籍
    QString ethnic;                 //名族
    QString contactWay;             //联系方式
    QByteArray cardPhoto;           //身份证照片

    CardDataInfo_S()
    {
        cardType=0;
        idCard="";
        nameZh="";
        nameEn="";
        age=0;
        sex=2;
        birthDate="";
        address="";
        expireStart="";
        expireEnd="";
        nationality="";
        ethnic="";
        contactWay="";
        cardPhoto=nullptr;
    }

}CardDataInfo;

/*人脸识别消息消息*/
/*人脸寻优结果消息结构体*/
typedef struct OptimumFaceInfo_S
{
    int camId;              //摄像头ID

    /*人脸在剪切后图像中的位置信息*/
    int facePstId;          //人脸ID
    int facePstLeft;        //人脸左边界值
    int facePstTop;         //人脸上边界值
    int facePstRight;       //人脸右边界值
    int facePstBottom;      //人脸下边界值

    float quality;          //人脸质量
    int	width;              //剪切后图像的宽度
    int	height;             //剪切后图像的高度
    int	imgLen;             //剪切后图像所占内存大小
    QByteArray faceData;    //剪切后图像内存数据
    QImage faceDataImg;		//剪切后图像内存数据图片
    int	featureLen;         //人脸特征长度，不提特征时为0
    QByteArray featureData;	//人脸特征，不提特征时为NULL
    long curTime;           //人脸当前时间，为当前日期的毫秒数计时

    /*人脸所在的整张视频帧图片的数据信息*/
    int	frmImgIndex;        //帧号信息
    int	frmImgLen;          //整帧图像（JPEG格式）的长度
    QByteArray frmImgData;  //整帧图像数据（JPEG格式），通过解码JPEG数据可以得到图像的宽高等信息
    QImage frmImgDataImg;   //整帧图像数据图片
    int	frmImgMenLen;       //图像数据区申请的总内存大小
    /*人脸在大图像中的位置信息*/
    int frmFacePstId;          //人脸ID
    int frmFacePstLeft;        //人脸左边界值
    int frmFacePstTop;         //人脸上边界值
    int frmFacePstRight;       //人脸右边界值
    int frmFacePstBottom;      //人脸下边界值

    OptimumFaceInfo_S(){
        camId=-1;
        facePstId=-1;
        facePstLeft=-1;
        facePstTop=-1;
        facePstBottom=-1;
        quality = 0;
        width = 0;
        height = 0;
        imgLen = 0;
        faceData=nullptr;
        //faceDataImg
        featureLen = 0;
        featureData=nullptr;
        curTime = 0;
        frmImgIndex=-1;
        frmImgLen=0;
        frmImgData=nullptr;
        //frmImgDataImg
        frmImgMenLen=0;
        frmFacePstId=-1;
        frmFacePstLeft=-1;
        frmFacePstTop=-1;
        frmFacePstRight=-1;
        frmFacePstBottom=-1;
    }
}OptimumFaceInfo;


/*人脸消息结构体*/
//typedef struct FaceInfo_S
//{
//    int camId;              //摄像头ID
//    QImage faceImg;         //图像内存数据图片
//    int faceNum;
//    FacePosition facePst[10];

//    FaceInfo_S(){
//        camId=-1;
//        faceNum=0;
//        //faceImg;
//        //facePst;

//    }
//}FaceInfo;

#endif // PARAMDEF_H

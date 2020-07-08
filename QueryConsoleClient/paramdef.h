#include <QString>

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

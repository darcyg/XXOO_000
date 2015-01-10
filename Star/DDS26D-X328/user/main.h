/*******************************************************************
	版权声明:
	文件功能:主程序
	备注说明:
			1 DTS27-VN31三相电能表
	文件版本:V1.0
********************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_

/*--------------------宏定义---------------------------*/

/*--------------------外部常量申明---------------------*/

/*--------------------外部变量申明---------------------*/
extern uint16 ResetCause;
extern __no_init uint16 RTCResetRecord[5];
//0  --por 复位
//1  ---LVD 复位
//2  ---时钟出错---回到默认值
//3  ---时钟出错
//4  ---掉电时间大于时钟
extern uint8  energyEepError;                   //电能出错
extern uint8  caliEepError;                     //校表数据出错
/*--------------------外部函数申明-------------------------*/






#endif

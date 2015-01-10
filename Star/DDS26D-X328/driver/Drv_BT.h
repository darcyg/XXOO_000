
/*******************************************************************
* Copyright (c) 2013,深圳市思达仪表有限公司 
* All rights reserved. 
* 
* 文件名称：drv_bt.h 
* 文件标识：见配置管理计划书 
* 摘要：基本定时器移植层
BT0-RTC(秒脉冲)
BT1-RTC(秒脉冲)
BT2-
BT3-
BT4-
BT5-
BT6-taskTimer(中断任务节拍)
BT7-系统时钟校准(用系统时钟测量RTC秒脉冲)

SYSTICK-task(系统节拍5ms)
MFT-EMU(能量累计250us)

* 当前版本：1.0.0 
* 作者：张玉清
* 完成日期：20131024
*******************************************************************/
#ifndef _DRV_BT_H_
#define _DRV_BT_H_

/*--------------------宏定义---------------------------*/


/*--------------------外部常量申明---------------------*/

/*--------------------外部变量申明---------------------*/



/*--------------------外部函数申明-------------------------*/
void Config_SystemClock_Priority(void);
void RF1MSInit(void);
void RF1MSStart(void);
void RF1MSPowerDownInit(void);




#endif

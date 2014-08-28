/*******************************************************************************
** 硬件平台: 富士通MB9AF005学习板
** 固件库  ：V1.0
** 文件名  : UserLed.h
** 实现功能: UserLed头文件，包含了LED管脚的定义，LED函数声明
** 作者    : 微控事业部
** 创建日期: 2013/8/11
** 版权    : 利尔达科技有限公司
** ----------------------------------------------------------------------------
** 修改者:
** 修改日期:
** 修改内容:
*******************************************************************************/
#ifndef __USERLED_H__
#define __USERLED_H__

#include "pdl_header.h"

/******************************************************************************/
/**                          以下是定义LED的IO口                  	      	 **/
/******************************************************************************/
//LED接口配置 P54->LED 低电平点亮
#define USER_LED_PORT IO_PORT3
#define USER_LED_PIN  IO_PINx6
//如果所用LED的IO有模拟输入功能请定义
// #define USER_IO_AN     IO_AN27

/******************************************************************************/
/**                          以下是内部函数申明                              **/
/******************************************************************************/
void UserLed_Init(void);
void USER_LED_ON(void);
void USER_LED_OFF(void);
void UserLed_Blink(void);

#endif

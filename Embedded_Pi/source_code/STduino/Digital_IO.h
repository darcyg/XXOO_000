#ifndef __Digital_IO_H_
#define __Digital_IO_H_


/*** define and type ***/
#define     EMBEDDED_PI    1



typedef enum
{
    PA0 = 0,
    PA1,
    PA2,
    PA3,
    PA4,
    PA5,
    PA6,
    PA7,
    PA8,
    PA9,
    PA10,
//    PA11, // USB_DM
//    PA12, // USB_DP
//    PA13, // SWDIO__TMS
//    PA14, // SWCLK__TCLK
//    PA15, // TDI__D8
    PB0,
    PB1,
//    PB2,  // BOOT1
//    PB3,  // SWO TDO
//    PB4,  // USB_DISC__TRST
    PB5,
    PB6,
    PB7,
    PB8,
    PB9,
    PB10,
    PB11,
    PB12,
    PB13,
    PB14,
    PB15,
    PC0,
    PC1,
    PC2,
    PC3,
    PC4,
    PC5,
    PC6,
    PC7,
    PC8,
    PC9,
    PC10,
    PC11,
    PC12,
    PC13,
//    PC14, // OSC32_IN
//    PC15, // OSC32_OUT
//    PD0,  // OSC_IN
//    PD1,  // OSC_OUT
    PD2
}STM32F103x_PIN_TYPE;


typedef enum
{
    D0 = 0,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
    D8,
    D9,
    D10,
    D11,
    D12,
    D13,
    D14,
    D15,
    A16,
    A17,
    A18,
    A19,
    A20,
    A21,
    D22,
    D23,
    D24,
    D25,
    D26,
    D27,
    D28,
    D29,
    D30,
    D31,
    D32,
    D33,
    D34,
    D35,
    D36,
    D37,
    D38,
    D39,
    A40,
    A41,
    A42,
    A43,
    A44,
    A45
    //..    
}EMBEDDED_PI_PIN_TYPE;

typedef struct
{
     GPIO_TypeDef*  PORTx;
     u32            pinx;
}PORT_PIN_TYPE;

/*** extern variable declarations ***/



/*** extern function prototype declarations ***/
extern void pinMode_ALL(GPIO_TypeDef* PORT, u16 pin, 
                        GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed);
extern void digitalWrite_ALL(GPIO_TypeDef* PORT, u16 pin, BitAction BitVal);
extern u8 digitalRead_ALL(GPIO_TypeDef* PORT, u16 pin);

extern void pinMode_Px(STM32F103x_PIN_TYPE pin, GPIOMode_TypeDef mode);
extern void digitalWrite_Px(STM32F103x_PIN_TYPE pin, BitAction BitVal);
extern u8 digitalRead_Px(STM32F103x_PIN_TYPE pin);

extern void pinMode(EMBEDDED_PI_PIN_TYPE pin, GPIOMode_TypeDef mode);
extern void digitalWrite(EMBEDDED_PI_PIN_TYPE pin, BitAction BitVal);
extern u8 digitalRead(EMBEDDED_PI_PIN_TYPE pin);

#endif   /* end __Digital_IO_H_ */



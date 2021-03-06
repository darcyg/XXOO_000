#ifndef   _ALL_H_
#define   _ALL_H_

/*** C standard lib ***/
#include <stdio.h>      /* import printf scanf   */ 
#include <stdlib.h>     /* import string convert */
#include <string.h>     /* import memcpy memset memcmp ... */
#include <stdint.h>     /* import uint8_t */
//#include <stdarg.h>


/*** cortex M0 lib ***/
#include <intrinsics.h>	/* _nop_() enalbe */
#include <MSP430FE427.h>



/***  user lib ***/
#include  "def_and_type.h"
#include  "main.h"

/* APP lib */




/* BSP lib */




/* OpenSource lib */



/* shield lib */
//#include "LED.h"
#include "RF_SPI.h"
#include "RF_regConfig.h"
#include "RF.h"


/* arduino lib */
#include "Serial.h"






#endif
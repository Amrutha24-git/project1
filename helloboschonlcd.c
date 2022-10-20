/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-20, 09:45, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "lcd.h"
#include "BitsIoLdd1.h"
#include "rs.h"
#include "BitIoLdd1.h"
#include "rw.h"
#include "BitIoLdd2.h"
#include "en.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void LCD_delay(){
	int i;
	for(i=0;i<0x7fff;i++);
}
void LCD_command(unsigned char x){
	lcd_PutVal(x);
	rs_PutVal(0);
	rw_PutVal(0);
	en_PutVal(1);
	LCD_delay(1);
	en_PutVal(0);
}
void LCD_data(unsigned char y){
	lcd_PutVal(y);
	rs_PutVal(1);
	rw_PutVal(0);
	en_PutVal(1);
	LCD_delay(1);
	en_PutVal(0);
}
void LCD_init(){
	
    LCD_command(0x01);
    LCD_command(0x38);
    LCD_command(0x0F);
    LCD_command(0x80);
    LCD_command(0x06);
     
}
 void lcd_puts(unsigned char *lcd_string){
	 while(*lcd_string){
		 LCD_data(*lcd_string++);
	 }
 }
/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  LCD_init();
  /* For example: for(;;) { } */
while(1){
	
	 
	 
	
	lcd_puts("HELLO BOSCH");
	
	while(1);
	  
	}  


  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_gpio.h"
#include "misc.h"
#include "attributes.h"
#include "tm_stm32f4_rtc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx.h"
#include "tm_stm32f4_pcd8544.h"
#include "config_button.h"
#include "display.h"
#include "sound.h"

 TM_RTC_Time_t datatime;

void przycisk (){
	for (int i=0; i<100;i++);
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
timer();

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);


	DACinit();
timer();
	Configure_PB9();
	Configure_PB11();
	Configure_PB12();
	Configure_PB13();
	Configure_PB14();
	Configure_PB15();
	PCD8544_Init(0x38);




	if (!TM_RTC_Init(TM_RTC_ClockSource_Internal)) {	}
    TM_RTC_Interrupts(TM_RTC_Int_1s);
	   datatime.hours = 12;
	   datatime.minutes = 0;
	   datatime.seconds = 5;
	   datatime.year = 16;
	   datatime.month = 6;
	   datatime.date = 30;
	   datatime.day = 6;
   TM_RTC_SetDateTime(&datatime, TM_RTC_Format_BIN); // pierwsze automatyczne ustawienie godziny i czasu


   while (1)
   {
	  graj();

   }
}



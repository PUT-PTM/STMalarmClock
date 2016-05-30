#include "config_button.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_syscfg.h"
#include "misc.h"
#include "attributes.h"
#include "tm_stm32f4_rtc.h"
#include "tm_stm32f4_pcd8544.h"
#include "display.h"
#include "sound.h"
#include "stm32f4xx_tim.h"


char buf[50], buf2[50];
int alarmhours=12, alarmminutes=01;
TM_RTC_Time_t datatime;
int a=0,b=0;
int active=0;
int yeartemp=0, monthtemp=0, daytemp=0, hourstemp=0, minutestemp=0;

void timer(){
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	  TIM_TimeBaseStructure.TIM_Period = 125-1;
	  TIM_TimeBaseStructure.TIM_Prescaler = 168000-1;
	  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	  TIM_TimeBaseStructure.TIM_CounterMode =  TIM_CounterMode_Up;
	  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);}


void Configure_PB9(void) {
    GPIO_InitTypeDef GPIO_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource9);

    /* PB12 is connected to EXTI_Line12 */
    EXTI_InitStruct.EXTI_Line = GPIO_Pin_9;
    /* Enable interrupt */
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    /* Interrupt mode */
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    /* Triggers on rising and falling edge */
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    /* Add to EXTI */
    EXTI_Init(&EXTI_InitStruct);

    /* Add IRQ vector to NVIC */
    /* PB12 is connected to EXTI_Line12, which has EXTI15_10_IRQn vector */
    NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
    /* Set priority */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
    /* Set sub priority */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
    /* Enable interrupt */
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    /* Add to NVIC */
    NVIC_Init(&NVIC_InitStruct);
}


void Configure_PB11(void) {
    GPIO_InitTypeDef GPIO_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource11);

    /* PB12 is connected to EXTI_Line12 */
    EXTI_InitStruct.EXTI_Line = GPIO_Pin_11;
    /* Enable interrupt */
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    /* Interrupt mode */
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    /* Triggers on rising and falling edge */
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    /* Add to EXTI */
    EXTI_Init(&EXTI_InitStruct);

    /* Add IRQ vector to NVIC */
    /* PB12 is connected to EXTI_Line12, which has EXTI15_10_IRQn vector */
    NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
    /* Set priority */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
    /* Set sub priority */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
    /* Enable interrupt */
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    /* Add to NVIC */
    NVIC_Init(&NVIC_InitStruct);
}

void Configure_PB12(void) {
    GPIO_InitTypeDef GPIO_InitStruct2;
    EXTI_InitTypeDef EXTI_InitStruct2;
    NVIC_InitTypeDef NVIC_InitStruct2;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    GPIO_InitStruct2.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct2.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct2.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStruct2.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct2.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct2);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource12);

    /* PB12 is connected to EXTI_Line12 */
    EXTI_InitStruct2.EXTI_Line = GPIO_Pin_12;
    /* Enable interrupt */
    EXTI_InitStruct2.EXTI_LineCmd = ENABLE;
    /* Interrupt mode */
    EXTI_InitStruct2.EXTI_Mode = EXTI_Mode_Interrupt;
    /* Triggers on rising and falling edge */
    EXTI_InitStruct2.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    /* Add to EXTI */
    EXTI_Init(&EXTI_InitStruct2);

    /* Add IRQ vector to NVIC */
    /* PB12 is connected to EXTI_Line12, which has EXTI15_10_IRQn vector */
    NVIC_InitStruct2.NVIC_IRQChannel = EXTI15_10_IRQn;
    /* Set priority */
    NVIC_InitStruct2.NVIC_IRQChannelPreemptionPriority = 0x00;
    /* Set sub priority */
    NVIC_InitStruct2.NVIC_IRQChannelSubPriority = 0x01;
    /* Enable interrupt */
    NVIC_InitStruct2.NVIC_IRQChannelCmd = ENABLE;
    /* Add to NVIC */
    NVIC_Init(&NVIC_InitStruct2);
}
/* Set interrupt handlers */
/* Handle PD0 interrupt */
void Configure_PB13(void) {
    GPIO_InitTypeDef GPIO_InitStruct3;
    EXTI_InitTypeDef EXTI_InitStruct3;
    NVIC_InitTypeDef NVIC_InitStruct3;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    GPIO_InitStruct3.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct3.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct3.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStruct3.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct3.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct3);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource13);

    /* PB12 is connected to EXTI_Line12 */
    EXTI_InitStruct3.EXTI_Line = GPIO_Pin_13;
    /* Enable interrupt */
    EXTI_InitStruct3.EXTI_LineCmd = ENABLE;
    /* Interrupt mode */
    EXTI_InitStruct3.EXTI_Mode = EXTI_Mode_Interrupt;
    /* Triggers on rising and falling edge */
    EXTI_InitStruct3.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    /* Add to EXTI */
    EXTI_Init(&EXTI_InitStruct3);

    /* Add IRQ vector to NVIC */
    /* PB12 is connected to EXTI_Line12, which has EXTI15_10_IRQn vector */
    NVIC_InitStruct3.NVIC_IRQChannel = EXTI15_10_IRQn;
    /* Set priority */
    NVIC_InitStruct3.NVIC_IRQChannelPreemptionPriority = 0x00;
    /* Set sub priority */
    NVIC_InitStruct3.NVIC_IRQChannelSubPriority = 0x01;
    /* Enable interrupt */
    NVIC_InitStruct3.NVIC_IRQChannelCmd = ENABLE;
    /* Add to NVIC */
    NVIC_Init(&NVIC_InitStruct3);
}
void Configure_PB14(void) {
    GPIO_InitTypeDef GPIO_InitStruct4;
    EXTI_InitTypeDef EXTI_InitStruct4;
    NVIC_InitTypeDef NVIC_InitStruct4;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    GPIO_InitStruct4.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct4.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct4.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStruct4.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct4.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct4);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource14);

    /* PB12 is connected to EXTI_Line12 */
    EXTI_InitStruct4.EXTI_Line = GPIO_Pin_14;
    /* Enable interrupt */
    EXTI_InitStruct4.EXTI_LineCmd = ENABLE;
    /* Interrupt mode */
    EXTI_InitStruct4.EXTI_Mode = EXTI_Mode_Interrupt;
    /* Triggers on rising and falling edge */
    EXTI_InitStruct4.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    /* Add to EXTI */
    EXTI_Init(&EXTI_InitStruct4);

    /* Add IRQ vector to NVIC */
    /* PB12 is connected to EXTI_Line12, which has EXTI15_10_IRQn vector */
    NVIC_InitStruct4.NVIC_IRQChannel = EXTI15_10_IRQn;
    /* Set priority */
    NVIC_InitStruct4.NVIC_IRQChannelPreemptionPriority = 0x00;
    /* Set sub priority */
    NVIC_InitStruct4.NVIC_IRQChannelSubPriority = 0x01;
    /* Enable interrupt */
    NVIC_InitStruct4.NVIC_IRQChannelCmd = ENABLE;
    /* Add to NVIC */
    NVIC_Init(&NVIC_InitStruct4);
}


void Configure_PB15(void) {
    GPIO_InitTypeDef GPIO_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource15);

    /* PB12 is connected to EXTI_Line12 */
    EXTI_InitStruct.EXTI_Line = GPIO_Pin_15;
    /* Enable interrupt */
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    /* Interrupt mode */
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    /* Triggers on rising and falling edge */
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    /* Add to EXTI */
    EXTI_Init(&EXTI_InitStruct);

    /* Add IRQ vector to NVIC */
    /* PB12 is connected to EXTI_Line12, which has EXTI15_10_IRQn vector */
    NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
    /* Set priority */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
    /* Set sub priority */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
    /* Enable interrupt */
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    /* Add to NVIC */
    NVIC_Init(&NVIC_InitStruct);
}

void EXTI9_5_IRQHandler(void) {
  	if (EXTI_GetITStatus(EXTI_Line9) != RESET){
  		TIM_Cmd(TIM2, ENABLE);
  		 if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)){
	if(a==1){
	    TM_RTC_GetDateTime(&datatime, TM_RTC_Format_BIN);

	    if(b==0){

	    	if(hourstemp<=23){hourstemp+=1;}
	    	if(hourstemp==24){hourstemp=0;}

	    	wyswietl_date_hours();

			PCD8544_GotoXY(5, 32);
			PCD8544_Puts("Ustaw godzine.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

			PCD8544_Refresh();

	    }

	    if(b==1){
	    	if(minutestemp<=59){minutestemp+=1;}
	    	if(minutestemp==60){minutestemp=0;}

	    	wyswietl_date_hours();

			PCD8544_GotoXY(5, 32);
			PCD8544_Puts("Ustaw minuty.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

			PCD8544_Refresh();

	    }
		if(b==2){
			if(daytemp<=31){daytemp+=1;}
			if(daytemp==32){daytemp=1;}

	    	wyswietl_date_hours();

			PCD8544_GotoXY(5, 32);
			PCD8544_Puts("Ustaw dzien.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

			PCD8544_Refresh();

		}
		if(b==3){

			if(monthtemp<=12){monthtemp+=1;}
			if(monthtemp==13){monthtemp=1;}

	    	wyswietl_date_hours();

			PCD8544_GotoXY(5, 32);
			PCD8544_Puts("Ustaw miesiac.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

			PCD8544_Refresh();

		}
		if(b==4){
			if(yeartemp<=99){yeartemp+=1;}
			if(yeartemp==100){yeartemp=1;}

	    	wyswietl_date_hours();

			PCD8544_GotoXY(5, 32);
			PCD8544_Puts("Ustaw rok.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

			PCD8544_Refresh();
		}

		}

		if(a==2)
		{
			if(b==0)
			{
				alarmhours+=1;
					if(alarmhours==24)
					{
						alarmhours=0;
					}
					wyswietl_alarm();

					PCD8544_GotoXY(5, 13);
					PCD8544_Puts("Ustaw godzine. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

					PCD8544_Refresh();
					//edytujesz godzinê	alarmu
			}
			if(b==1)
			{
				alarmminutes+=1;
				if(alarmminutes==60){alarmminutes=0;}
					wyswietl_alarm();

					PCD8544_GotoXY(5, 13);
					PCD8544_Puts("Ustaw minuty. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

					PCD8544_Refresh();
					//edytujesz godzinê	alarmu
			}

}
		 TIM_ClearFlag(TIM2, TIM_FLAG_Update);
		 TIM_Cmd(TIM2, DISABLE);
				 }
  		EXTI_ClearITPendingBit(EXTI_Line9);  /* Clear interrupt flag */
  		        }

}



/* Handle PB12 interrupt */
void EXTI15_10_IRQHandler(void) {

    if (EXTI_GetITStatus(EXTI_Line11) != RESET)
	{
    	TIM_Cmd(TIM2, ENABLE);
    	if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)){
    	if(a==1)
    	{
    		b++;
    		if(b==1)
    		{
    			wyswietl_date_hours();
    			PCD8544_GotoXY(5, 32);
    			PCD8544_Puts("Ustaw minuty.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();
	//edytujesz minuty
    		}
    		if(b==2)
    		{
    			wyswietl_date_hours();
    			PCD8544_GotoXY(5, 32);
    			PCD8544_Puts("Ustaw dzien.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();

	//edytujesz dzieñ
    		}
    		if(b==3)
    		{
    			wyswietl_date_hours();
    			PCD8544_GotoXY(5, 32);
    			PCD8544_Puts("Ustaw miesiac.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();
    			//edytujesz miesi¹c
    		}
    		if(b==4)
    		{
    			wyswietl_date_hours();
    		   	PCD8544_GotoXY(5, 32);
    		    PCD8544_Puts("Ustaw rok.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    		    PCD8544_Refresh();
	//edytujesz rok

    		}
    		if(b==5)
    		{
    			wyswietl_date_hours();
    			PCD8544_GotoXY(5, 32);
    			PCD8544_Puts("Ustaw godzine.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();
    			b=0;

    			datatime.hours=hourstemp;
    			datatime.minutes=minutestemp;
    			datatime.year=yeartemp;
    			datatime.month=monthtemp;
    			datatime.date=daytemp;

    			TM_RTC_SetDateTime(&datatime, TM_RTC_Format_BIN); // pierwsze automatyczne ustawienie godziny i czasu

    		}//ZAPISAC DATE!!!!!
    	}
    	if(a==2)
    	{
    		b++;
    		if(b==1)
    		{
    			wyswietl_alarm();

    			PCD8544_GotoXY(5, 13);
    			PCD8544_Puts("Ustaw minuty. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();
    			//edytujesz minuty	alarmu

    		}
    		if(b==2)
    		{
    			wyswietl_alarm();

    			PCD8544_GotoXY(5, 13);
    			PCD8544_Puts("Ustaw godzine. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();
    			b=0;
    		}
    	}
    	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    	TIM_Cmd(TIM2, DISABLE);/* Clear interrupt flag */
				 }
    	  					 EXTI_ClearITPendingBit(EXTI_Line11);

}


    if (EXTI_GetITStatus(EXTI_Line12) != RESET)
    {
            /* Do your stuff when PB12 is changed */
    	TIM_Cmd(TIM2, ENABLE);
    	if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)){
    	if(a==2)
    	{
    		if(active==0)
    		{
    			active=1;
    			if(b==1)
    			{
    				wyswietl_alarm();

    				PCD8544_GotoXY(5, 13);
    				PCD8544_Puts("Ustaw minuty. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    				PCD8544_Refresh();
    			//edytujesz minuty	alarmu

    			}
    			if(b==0)
    			{
    				wyswietl_alarm();

    				PCD8544_GotoXY(5, 13);
    				PCD8544_Puts("Ustaw godzine. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    				PCD8544_Refresh();
    				b=0;
    			}
    		}
    		else
    		{
    			active=0;
    			if(b==1)
    			{
    				wyswietl_alarm();

    				PCD8544_GotoXY(5, 13);
    				PCD8544_Puts("Ustaw minuty. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    				PCD8544_Refresh();
    			//edytujesz minuty	alarmu

    			}
    			if(b==0)
    			{
    				wyswietl_alarm();

    				PCD8544_GotoXY(5, 13);
    				PCD8544_Puts("Ustaw godzine. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    				PCD8544_Refresh();
    				b=0;
    			}
    		}

    	}
    	if(a==0)
		{
			if(active==0)
			{
				active=1;
				wyswietl_wszystko();
			}
			else
			{
				active=0;
				wyswietl_wszystko();
			}

		}

    	 TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    	 TIM_Cmd(TIM2, DISABLE);/* Clear interrupt flag */
    					 }
		EXTI_ClearITPendingBit(EXTI_Line12);

        }

if (EXTI_GetITStatus(EXTI_Line13) != RESET)
{
            /* Do your stuff when PB12 is changed */
	TIM_Cmd(TIM2, ENABLE);
	if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)){
	if(a==1)
	{
			TM_RTC_GetDateTime(&datatime, TM_RTC_Format_BIN);
			if(b==0)
			{
				if(hourstemp>=0){hourstemp-=1;}
				if(hourstemp==-1){hourstemp=23;}

    			wyswietl_date_hours();
    			PCD8544_GotoXY(5, 32);
    			PCD8544_Puts("Ustaw godzine.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();

			}
			if(b==1)
			{
				if(minutestemp>=0){minutestemp-=1;}
				if(minutestemp==-1){minutestemp=59;}

    			wyswietl_date_hours();
    			PCD8544_GotoXY(5, 32);
    			PCD8544_Puts("Ustaw minuty.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();
			}
			if(b==2)
			{
				if(daytemp>=1){daytemp-=1;}
				if(daytemp==0){daytemp=31;}

    			wyswietl_date_hours();
    			PCD8544_GotoXY(5, 32);
    			PCD8544_Puts("Ustaw dzien.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();
			}
			if(b==3)
			{
				if(monthtemp>=1){monthtemp-=1;}
				if(monthtemp==0){monthtemp=12;}

    			wyswietl_date_hours();
    			PCD8544_GotoXY(5, 32);
    			PCD8544_Puts("Ustaw miesiac.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();
			}
			if(b==4)
			{
				if(yeartemp>=1){yeartemp-=1;}
				if(yeartemp==0){yeartemp=99;}

    			wyswietl_date_hours();
    			PCD8544_GotoXY(5, 32);
    			PCD8544_Puts("Ustaw rok.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    			PCD8544_Refresh();
			}

	}

    if(a==2)
    {
    	if(b==0)
    	{
    		alarmhours-=1;
    		if(alarmhours==-1){alarmhours=23;}

    		wyswietl_alarm();

    		PCD8544_GotoXY(5, 13);
    		PCD8544_Puts("Ustaw godziny. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    		PCD8544_Refresh();

    	//edytujesz godzinê	alarmu
    	}
    	if(b==1)
    	{
    		alarmminutes-=1;
    		if(alarmminutes==-1){alarmminutes=59;}

    		wyswietl_alarm();

    		PCD8544_GotoXY(5, 13);
    		PCD8544_Puts("Ustaw minuty. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    		PCD8544_Refresh();
    	//edytujesz minuty alarmu

    	}
    }
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    TIM_Cmd(TIM2, DISABLE);/* Clear interrupt flag */
   				 }
   EXTI_ClearITPendingBit(EXTI_Line13);

}

if (EXTI_GetITStatus(EXTI_Line14) != RESET)
{
	TIM_Cmd(TIM2, ENABLE);
	if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)){
               /* Do your stuff when PB12 is changed */
	a++;
	if(a==3){a=0;}
	if(a==1)
	{
		b=0;
	//pierwszy ekran
		wyswietl_date_hours();
		PCD8544_GotoXY(5, 32);
		PCD8544_Puts("Ustaw godzine.", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

		PCD8544_Refresh();


	//edytujesz godzinê

	}
	if(a==2)
	{
		b=0;

		wyswietl_alarm();

		PCD8544_GotoXY(5, 13);
		PCD8544_Puts("Ustaw godziny. ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

		PCD8544_Refresh();

		PCD8544_Refresh();
	//edytujesz godzinê	alarmu

	}
	if(a==0)
	{
		wyswietl_wszystko();

		PCD8544_Refresh();
	}
	 TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	 TIM_Cmd(TIM2, DISABLE);/* Clear interrupt flag */
					 }
    EXTI_ClearITPendingBit(EXTI_Line14);

}


 if (EXTI_GetITStatus(EXTI_Line15) != RESET) {
            /* Do your stuff when PB12 is changed */

          EXTI_ClearITPendingBit(EXTI_Line15);  /* Clear interrupt flag */
        }
}

void graj()
{
	   if(active==1)
	   {
		   if(alarmhours==datatime.hours)
		   {
			   	 if(alarmminutes==datatime.minutes)
			   	 {
			   		 Play();
			   	 }
		   }
	   }

}


void TM_RTC_RequestHandler() {
    //Get time
	   TM_RTC_GetDateTime(&datatime, TM_RTC_Format_BIN);
//sprawdza czy nie jest wlaczony tryb edycji

	   if(a==0)
	   {
		   wyswietl_wszystko();
	   }

}






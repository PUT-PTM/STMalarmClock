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

char buf[50], buf2[50];
TM_RTC_Time_t datatime;

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

/* Handle PB12 interrupt */
void EXTI15_10_IRQHandler(void) {
    /* Make sure that interrupt flag is set */


    if (EXTI_GetITStatus(EXTI_Line11) != RESET) {
            /* Do your stuff when PB12 is changed */

        	for(int i=0;i<5;i++){
        	    	    			GPIO_SetBits(GPIOD,GPIO_Pin_12);
        	    	    			for (int g=0;g<1000000;g++){};
        	    	    			GPIO_ResetBits(GPIOD,GPIO_Pin_12);
        	    	    			for (int g=0;g<1000000;g++){};
        	    	    	}
          EXTI_ClearITPendingBit(EXTI_Line11);  /* Clear interrupt flag */
        }


    if (EXTI_GetITStatus(EXTI_Line12) != RESET) {
            /* Do your stuff when PB12 is changed */

        	for(int i=0;i<5;i++){
        	    	    			GPIO_SetBits(GPIOD,GPIO_Pin_13);
        	    	    			for (int g=0;g<1000000;g++){};
        	    	    			GPIO_ResetBits(GPIOD,GPIO_Pin_13);
        	    	    			for (int g=0;g<1000000;g++){};
        	    	    	}
          EXTI_ClearITPendingBit(EXTI_Line12);  /* Clear interrupt flag */
        }

    if (EXTI_GetITStatus(EXTI_Line13) != RESET) {
            /* Do your stuff when PB12 is changed */

        	for(int i=0;i<5;i++){
        	    	    			GPIO_SetBits(GPIOD,GPIO_Pin_14);
        	    	    			for (int g=0;g<1000000;g++){};
        	    	    			GPIO_ResetBits(GPIOD,GPIO_Pin_14);
        	    	    			for (int g=0;g<1000000;g++){};
        	    	    	}
          EXTI_ClearITPendingBit(EXTI_Line13);  /* Clear interrupt flag */
        }
    if (EXTI_GetITStatus(EXTI_Line14) != RESET) {
               /* Do your stuff when PB12 is changed */

           	for(int i=0;i<5;i++){
           	    	    			GPIO_SetBits(GPIOD,GPIO_Pin_15);
           	    	    			for (int g=0;g<1000000;g++){};
           	    	    			GPIO_ResetBits(GPIOD,GPIO_Pin_15);
           	    	    			for (int g=0;g<1000000;g++){};
           	    	    	}
             EXTI_ClearITPendingBit(EXTI_Line14);  /* Clear interrupt flag */
           }

}





void Init_Diod() {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14
			| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}


void Init_Tim4(){
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 1000;
	TIM_TimeBaseStructure.TIM_Prescaler = 7199;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM4, ENABLE);
}

int main(void)
{
    TM_RTC_Interrupts(TM_RTC_Int_1s);
    datatime.hours = 12;
            datatime.minutes = 0;
            datatime.seconds = 0;
            datatime.year = 14;
            datatime.month = 6;
            datatime.date = 30;
            datatime.day = 6;
    TM_RTC_SetDateTime(&datatime, TM_RTC_Format_BIN); // pierwsze automatyczne ustawienie godziny i czasu

	SystemInit();
	Init_Diod();
	Init_Tim4();
	PCD8544_Init(0x38);

	Configure_PB12();
	Configure_PB13();
	Configure_PB14();
	Configure_PB11();

	int mrugaj=0;

	while (1) {
		if(TIM_GetFlagStatus(TIM4, TIM_FLAG_Update))
				{
					GPIO_ToggleBits(GPIOD,GPIO_Pin_14);

					if(mrugaj==0)
					{
						PCD8544_Clear();

						PCD8544_GotoXY(5, 3);
						PCD8544_Puts("TIME:", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
						PCD8544_GotoXY(30, 3);
						PCD8544_Puts(" 15:40", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
						PCD8544_GotoXY(5, 13);
						PCD8544_Puts("ALARM:", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
						PCD8544_GotoXY(40, 13);
						PCD8544_Puts("mrugaj", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
						PCD8544_GotoXY(5, 26);
						PCD8544_Puts("DATE:2015-04-18", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

						PCD8544_Refresh();
						mrugaj++;
					}
					else{
						PCD8544_Clear();

						PCD8544_GotoXY(5, 3);
						PCD8544_Puts("TIME:", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
						PCD8544_GotoXY(30, 3);
						PCD8544_Puts(" 15:40", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
						PCD8544_GotoXY(5, 13);
						PCD8544_Puts("ALARM:", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
						PCD8544_GotoXY(40, 13);
						PCD8544_Puts("", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
						PCD8544_GotoXY(5, 26);
						PCD8544_Puts("DATE:2015-04-18", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

						PCD8544_Refresh();
						mrugaj=0;
					}
					TIM_ClearFlag(TIM4, TIM_FLAG_Update);
				}
	}
}

void TM_RTC_RequestHandler() {
    //Get time
    TM_RTC_GetDateTime(&datatime, TM_RTC_Format_BIN);

}

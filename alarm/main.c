#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_gpio.h"
#include "misc.h"
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




int main(void)
{

	SystemInit();
	Init_Diod();
	Configure_PB12();
	Configure_PB13();
	Configure_PB14();
	Configure_PB11();
	    while (1) {

	    }
}

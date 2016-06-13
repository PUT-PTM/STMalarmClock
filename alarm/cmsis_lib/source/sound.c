#include "stm32f4xx_dac.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "math.h"
#include "stm32f4xx_tim.h"

float i=0;
int increase = 1;

void timer_sound()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = 125-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 250-1;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode =  TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
}

void DACinit()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14|
	GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	DAC_InitTypeDef DAC_InitStructure;
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	DAC_Init(DAC_Channel_1, &DAC_InitStructure);

	DAC_Cmd(DAC_Channel_1, ENABLE);

	DAC_SetChannel1Data(DAC_Align_12b_R, 0x7FF);
}

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

void Play()
{

	TIM_Cmd(TIM6, ENABLE);
	if(TIM_GetFlagStatus(TIM6, TIM_FLAG_Update)) {
   	 GPIO_ToggleBits(GPIOD,GPIO_Pin_14);


		DAC_SetChannel1Data(DAC_Align_12b_R, (sin(i)*4095));
	    		if(i<4095 && increase == 1)i+=1;
	    		if(i>=4095)increase=0;
	    			if(increase == 0){
	    				i-=1;}

	    		if (i==0) increase = 1;
	TIM_ClearFlag(TIM6, TIM_FLAG_Update);
	TIM_Cmd(TIM6, DISABLE);
	}
}

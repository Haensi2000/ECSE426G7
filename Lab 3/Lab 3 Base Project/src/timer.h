#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#define NO_TIMEOUT 0
#define TIMEOUT_OCCURRED 1

extern short interruptStatus;

void initTimer(void);

void TIM3_IRQHandler(void)
{
	// Get current interrupt status	
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) {
			interruptStatus = TIMEOUT_OCCURRED;
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		}
}

void initTimer() {
	NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

  /* Enable the TIM3 global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	
	TIM_TimeBaseInitTypeDef TIM3_TimeBaseInitStruct;
	
	TIM3_TimeBaseInitStruct.TIM_Period = 65535; // us?
	TIM3_TimeBaseInitStruct.TIM_Prescaler = 0;
	TIM3_TimeBaseInitStruct.TIM_ClockDivision = 0;
	
	TIM_TimeBaseInit(TIM3, &TIM3_TimeBaseInitStruct);
	
	uint16_t PrescalerValue = 52;
	
	TIM_PrescalerConfig(TIM3, PrescalerValue, TIM_PSCReloadMode_Immediate);
	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	TIM_Cmd(TIM3, ENABLE);
}


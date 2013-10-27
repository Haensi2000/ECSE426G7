/**
  ******************************************************************************
  * @file    USART/USART_HyperTerminal/main.h
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    19-September-2013
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

#if defined (USE_STM324xG_EVAL)
  #include "stm324xg_eval.h"

#elif defined (USE_STM324x7I_EVAL) 
  #include "stm324x7i_eval.h"

#elif defined (USE_STM324x9I_EVAL) 
  #include "stm324x9i_eval.h"

#else
 #error "Please select first the Evaluation board used in your application (in Project Options)"
#endif

/* Exported typedef ----------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/
#if defined (USE_STM324xG_EVAL)
     
  /* Definition for USARTx_IRQHANDLER *****************************************/
  #define USARTx_IRQHANDLER   USART3_IRQHandler
  
#endif /* USE_STM324xG_EVAL */
   
#if defined (USE_STM324x7I_EVAL)
     
  /* Definition for USARTx_IRQHANDLER *****************************************/
  #define USARTx_IRQHANDLER   USART3_IRQHandler
  
#endif /* USE_STM324x7I_EVAL */
   
#if defined (USE_STM324x9I_EVAL)
     
  /* Definition for USARTx_IRQHANDLER *****************************************/
  #define USARTx_IRQHANDLER   USART1_IRQHandler
  
#endif /* USE_STM324x9I_EVAL */
   
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
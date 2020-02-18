/******************************************
 * Includes
 ******************************************/
#include "MK64F12.h"
#include "app_PIT.h"
#include "fsl_pit.h"
#include "app_buffer.h"
#include "app_ADC.h"
#include "app_DAC.h"

/******************************************
 * Variables
 ******************************************/
//T_UBYTE	rub_PITAlarm = FALSE;

/******************************************
 * Code
 ******************************************/

/***********************************************
 * Function Name: app_PIT_Init
 * Description: Function that initializes the
 * PIT Module.
 ***********************************************/
void app_PIT_Init(void)
{
	pit_config_t ls_PitConfig;

	/* Get Default Config */
	PIT_GetDefaultConfig(&ls_PitConfig);

	/* PIT Init */
	PIT_Init(PIT, &ls_PitConfig);

	/* PIT Set Period at 1 ms*/
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(15, CLOCK_GetFreq(kCLOCK_BusClk)));
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_1, USEC_TO_COUNT(15,CLOCK_GetFreq(kCLOCK_BusClk)));

	/* Enable PIT Interrutps */
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	PIT_EnableInterrupts(PIT, kPIT_Chnl_1, kPIT_TimerInterruptEnable);

	/* Enable at the NVIC */
	EnableIRQ(PIT0_IRQn);
	EnableIRQ(PIT1_IRQn);

}

/***********************************************
 * Function Name: PIT_IRQHandler
 * Description: PIT IRQ Handler
 ***********************************************/
void PIT0_IRQHandler(void)
{
	/* Clear Interrupt Flag */
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
	/* Set PIT Alarm */
//	if(rub_PITAlarm == FALSE)
//	{
//		rub_PITAlarm = TRUE;
//		printf("1");
//	}
//	else
//	{
//		rub_PITAlarm = FALSE;
//		printf("0");
//	}
	app_buffer_put(app_ADC_Task());
}


void PIT1_IRQHandler(void)
{
	/* Clear Interrupt Flag */
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_1, kPIT_TimerFlag);
	/* Set PIT Alarm */
//	if(rub_PITAlarm == FALSE)
//	{
//		rub_PITAlarm = TRUE;
//		printf("2");
//	}
//	else
//	{
//		rub_PITAlarm = FALSE;
//		printf("3");
//	}
	app_DAC_SetValue(app_buffer_get());
}

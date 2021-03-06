/******************************************
 * Interfaces
 ******************************************/
#include "fsl_clock.h"
#include "fsl_dac.h"
#include "fsl_port.h"
#include "app_DAC.h"

/***********************************************
 * Function Name: app_DAC_Init
 * Description: TBD
 ***********************************************/
void app_DAC_Init(void)
{
	dac_config_t ls_DacConfig;

	/* Configure the DAC. */
	/*
	 * dacConfigStruct.referenceVoltageSource = kDAC_ReferenceVoltageSourceVref2;
	 * dacConfigStruct.enableLowPowerMode = false;
	 */
	DAC_GetDefaultConfig(&ls_DacConfig);
	DAC_Init(DAC0, &ls_DacConfig);
	DAC_Enable(DAC0, true);             /* Enable output. */
	DAC_SetBufferReadPointer(DAC0, 0U); /* Make sure the read pointer to the start. */
	/*
	 * The buffer is not enabled, so the read pointer can not move automatically. However, the buffer's read pointer
	 * and items can be written manually by user.
	 */


}

/***********************************************
 * Function Name: app_DAC_SetValue
 * Description: TBD
 ***********************************************/
void app_DAC_SetValue(T_UWORD luw_DacValue)
{
	DAC_SetBufferValue(DAC0, 0U, luw_DacValue);
}

/***********************************************
 * Function Name: app_DAC_Task
 * Description: TBD
 ***********************************************/
//void app_DAC_Task(void)
//{
//	app_DAC_SetValue(ruw_DacValue);
//
//	if(0xFFF > ruw_DacValue)
//	{
//		ruw_DacValue++;
//	}
//	else
//	{
//		ruw_DacValue = 0u;
//	}
//}

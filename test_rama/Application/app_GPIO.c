#include "stdio.h"
#include "MK64F12.h"
#include "app_GPIO.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_debug_console.h"
#include "fsl_common.h"
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_pit.h"

#define BLUE_LED	21U
#define RED_LED		22U

static int is_pressed = FALSE;

void app_GPIO_Init(void)
{
	/* Enable the clock for the modules needed */
	//CLOCK_EnableClock(kCLOCK_PortA); //Clock in PortA has already been enabled at BOARD_InitBootPins() >> BOARD_InitPins()
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortC);

	/* PORT Module Configuration */
	port_pin_config_t sw_config = {
			kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
			kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
			kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
			kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
			kPORT_HighDriveStrength,                                 /* High drive strength is configured */
			kPORT_MuxAsGpio,                                         /* Pin is configured as PTA4 */
			kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
	};
	port_pin_config_t ls_PinConfig;
	ls_PinConfig.mux = kPORT_MuxAsGpio;
	ls_PinConfig.pullSelect = kPORT_PullUp;

	PORT_SetPinConfig(PORTA, BOARD_SW3_GPIO_PIN, &sw_config);
	PORT_SetPinConfig(PORTC, BOARD_SW2_GPIO_PIN, &sw_config);
	PORT_SetPinConfig(PORTB, BLUE_LED, &ls_PinConfig); //Blue Led
	PORT_SetPinConfig(PORTB, RED_LED, &ls_PinConfig); //Red Led


	/* GPIO Configuration */
	gpio_pin_config_t ls_GPIOPinConfig;

	//BUTTONS
	ls_GPIOPinConfig.pinDirection = kGPIO_DigitalInput;
	//Enable Interruptions on rising edge at PTB2
	PORT_SetPinInterruptConfig(PORTA, BOARD_SW3_GPIO_PIN, kPORT_InterruptEitherEdge);
	PORT_SetPinInterruptConfig(PORTC, BOARD_SW2_GPIO_PIN, kPORT_InterruptFallingEdge);
	EnableIRQ(PORTA_IRQn);
	EnableIRQ(PORTC_IRQn);
	GPIO_PinInit(GPIOA, BOARD_SW3_GPIO_PIN, &ls_GPIOPinConfig);
	GPIO_PinInit(GPIOC, BOARD_SW2_GPIO_PIN, &ls_GPIOPinConfig);

	//LED
	ls_GPIOPinConfig.pinDirection = kGPIO_DigitalOutput;
	ls_GPIOPinConfig.outputLogic = TRUE;
	GPIO_PinInit(GPIOB, BLUE_LED, &ls_GPIOPinConfig);
	GPIO_PinInit(GPIOB, RED_LED, &ls_GPIOPinConfig);
}

//T_UBYTE app_GPIO_GetPinValue(GPIO_Type *lps_BaseAddress, T_UBYTE lub_PinNumber)
//{
//	T_UBYTE lub_PinValue;
//
//	lub_PinValue = (T_UBYTE)GPIO_PinRead(lps_BaseAddress, lub_PinNumber);
//
//	return lub_PinValue;
//}

void PORTA_IRQHandler(void)
{
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(GPIOA, 1U << BOARD_SW3_GPIO_PIN);

    if(is_pressed == FALSE){
    	PIT_StartTimer(PIT, kPIT_Chnl_0);
    	LED_BLUE_ON();
    	is_pressed = TRUE;
    }
    else{
    	PIT_StopTimer(PIT, kPIT_Chnl_0);
    	LED_BLUE_OFF();
    	is_pressed = FALSE;
    }
/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}


void PORTC_IRQHandler(void)
{
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(GPIOC, 1U << BOARD_SW2_GPIO_PIN);

    LED_RED_ON();
    PIT_StartTimer(PIT, kPIT_Chnl_1);

/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

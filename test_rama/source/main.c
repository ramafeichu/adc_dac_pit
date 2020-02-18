#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

#include "app_GPIO.h"
#include <app_ADC.h>
#include "app_PIT.h"
#include "app_DAC.h"

//Header file for Debugging purposes

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    /* PIT Module Init */
    app_PIT_Init();

    /* GPIO Module Init */
    app_GPIO_Init();

    /* DAC Module Init */
    app_DAC_Init();

    /* ADC Module Init */
    app_ADC_Init();

    int i = 0;
    /* Enter an infinite loop. */
    while(1) {
    	i++;

    }
    return 0 ;
}

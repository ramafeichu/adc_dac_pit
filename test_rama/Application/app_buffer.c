#include "app_buffer.h"
#include "app_GPIO.h"
#include "app_PIT.h"
#include "fsl_pit.h"
#include "board.h"

static T_UBYTE buffer[sizeof(T_UBYTE)*buff_size];
static unsigned int counter_in = 0;
static unsigned int counter_out = 0;

void app_buffer_put(T_UBYTE data)
{
	if(counter_in == buff_size)
	{
		return;
	}
	buffer[counter_in] = data;
	counter_in++;
}

T_UBYTE app_buffer_get(void)
{
	if(counter_out == counter_in)
	{
		counter_out = 0;
		counter_in = 0;
    	PIT_StopTimer(PIT, kPIT_Chnl_1);
    	LED_RED_OFF();
		return 0;
	}

	T_UBYTE data = buffer[counter_out];
	counter_out++;
	return data;
}


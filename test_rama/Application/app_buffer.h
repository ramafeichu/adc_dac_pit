#ifndef APP_BUFFER_H_
#define APP_BUFFER_H_

#include "stdtypedef.h"
#include <stdlib.h>

#define buff_size	100000

extern void app_buffer_put(T_UBYTE data);
extern T_UBYTE app_buffer_get(void);

#endif /* APP_BUFFER_H_ */

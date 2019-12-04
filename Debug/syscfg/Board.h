/*
 *  ======== Board.h ========
 *  Configured TI-Drivers module declarations
 *
 *  DO NOT EDIT - This file is generated for the CC3220SF_LAUNCHXL
 *  by the SysConfig tool.
 */
#ifndef Board_h
#define Board_h

#define Board_SYSCONFIG_PREVIEW

#define Board_CC3220SF_LAUNCHXL

/* Temporary define for backwards compatibility!!! */
#define __CC3220SF_LAUNCHXL_BOARD_H__

#ifndef DeviceFamily_CC3220
#define DeviceFamily_CC3220
#endif

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== GPIO ========
 */

#define Board_GPIO0                 0
#define COLOR_TASK_LED              1
#define Board_GPIO1                 2
#define Board_GPIO2                 3

/* LEDs are active high */
#define Board_GPIO_LED_ON  (1)
#define Board_GPIO_LED_OFF (0)

#define Board_LED_ON  (Board_GPIO_LED_ON)
#define Board_LED_OFF (Board_GPIO_LED_OFF)


/*
 *  ======== I2C ========
 */

#define COLOR_SENSOR_I2C0           0

/* ======== I2C Addresses and Speeds ======== */
#include <ti/drivers/I2C.h>

/* ---- COLOR_SENSOR_I2C0 I2C bus components ---- */

/* no components connected to COLOR_SENSOR_I2C0 */

/* max speed unspecified, defaulting to 100 Kbps */
#define COLOR_SENSOR_I2C0_MAXSPEED   (100U) /* Kbps */
#define COLOR_SENSOR_I2C0_MAXBITRATE ((I2C_BitRate)I2C_100kHz)


/*
 *  ======== SPI ========
 */

#define Board_NWP_SPI               0
#define Board_SPI0                  1


/*
 *  ======== Timer ========
 */

#define COLOR_SENSOR_TIMER          0


/*
 *  ======== UART ========
 */

#define UART_USB                    0


/*
 *  ======== Watchdog ========
 */

#define Board_WATCHDOG0             0


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */

/*
 * color_sensor_driver.h
 *
 */

#ifndef COLOR_SENSOR_DRIVER_H_
#define COLOR_SENSOR_DRIVER_H_

#include <ti/drivers/UART.h>
#include <ti/drivers/I2C.h>
#include "board.h"
#include <stdlib.h>

// Function return values
#define I2C_INIT_FAIL -1
#define I2C_INIT_SUCCESS 0
#define UART_INIT_FAIL -1
#define UART_INIT_SUCCESS 0
#define GET_COLORS_FAIL -1
#define GET_COLORS_SUCCESS 0
// as defined in motor controller documentation
#define INIT_UART_MSG 170

// color sensor defines
#define CSI2C_ADDR          0x29;

#define MIN_ADDRESS         0x08
#define MAX_ADDRESS         0x78

#define WBUFFER_SIZE        2
#define RBUFFER_SIZE        28

UART_Params uartColorSensorParams;
UART_Handle colorSensorUART;

uint16_t        sample;
uint16_t        temperature;
uint8_t         wxBuffer[WBUFFER_SIZE];
uint8_t         rxBuffer[RBUFFER_SIZE];
I2C_Handle      i2c;
I2C_Params      i2cParams;
I2C_Transaction i2cTransaction;

uint16_t *r, *g, *b, *c;

char UARTBuffer[20];
char echoPrompt[256];

int init_color_sensor_I2C();
int init_color_sensor_UART();
int getRGB();

// Valid inputs are speed in [0,127], direction in [0,1]
//int set_motor_0(int speed, int direction);
//int set_motor_1(int speed, int direction);
//int set_motor_2(int speed, int direction);
//int stop_all_motors();



#endif /* COLOR_SENSOR_DRIVER_H_ */

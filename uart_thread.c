/*
 * uart_thread.c
 *
 *  Created on: Oct 9, 2019
 *      Author: lukeb
 */

#include "uart_thread.h"
#include "my_callback_files/color_sensor_timer.h"
#include "my_driver_files/color_sensor_driver.h"

//#include <pthread.h>
//extern void *mainThread(void *arg0);
//#define THREADSTACKSIZE   2048

/*
 *  ======== uartThread ========
 */
void *uartThread(void *arg0)
{
    // turn usb uart
//    sleep(5);

    createUartQueue();

    if (create_ColorTaskQueue() == CREATE_QUEUE_FAILURE)
    {
//        errorRoutine(CONTROL_QUEUE_CREATE_FAILURE);
        printf("Queue creation failed.\n");
    }
    else
    {
        printf("Queue creation succeeded\n");
    }

    dbgUARTInit();

    // Command variables
    char msg[UART_QUEUE_WIDTH] = "\r\nUart thread opened\r\n\0";
    dbgUARTVal(msg);

    init_colorSensorTimer();
    init_color_sensor_I2C();


//    sleep(2);


    while (1) {
//        sendMsgToUart("blocking read in uart \r\n\0");
        // blocking read from queue
        readMsqFromUartQueue(msg);

        // write to UART
        dbgUARTVal(msg);
    }
}



/*
 *  ======== find_color_task_thread.c ========
 */

#include "find_color_task_thread.h"
#include "my_queue_files/uart_queue.h"
#include <ti/drivers/GPIO.h>

/*
 *  ======== findColorTaskThread ========
 */
void *findColorTaskThread(void *arg0)
{
//    GPIO_setConfig(COLOR_TASK_LED, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_HIGH);
    GPIO_setConfig(Board_GPIO1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_HIGH);
    GPIO_setConfig(Board_GPIO2, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_HIGH);
//    GPIO_write(COLOR_TASK_LED, 0);
    GPIO_write(Board_GPIO1, 0);
    GPIO_write(Board_GPIO2, 0);

//    GPIO_setConfig(SENSOR_LED0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
//    /* Turn of color sensor LED */
//    GPIO_write(SENSOR_LED0, Board_GPIO_LED_ON);

    sendMsgToUart("in find color thread\r\n\0");

//    // Command variables
    int msg_type;
    unsigned int msg_buffer;

    while (1) {

//        sendMsgToUart("before read message \r\n\0");

        // blocking read from queue when timer expires
        msg_type = readMsg_ColorTaskQueue(&msg_buffer);

//        sendMsgToUart("read message \r\n\0");

        if (msg_type != READ_FAILURE)
        {
//            if (msg_type == MSG_TYPE_TIMER)
//            {
//                sendMsgToUart("timer callback\r\n\0");
//
//                GPIO_toggle(COLOR_TASK_LED);
//                getRGB();
//            }
            //

            GPIO_toggle(Board_GPIO1);
//            getRGB();

//            sendMsgToUart("in RGB\r\n\0");

            if (I2C_transfer(i2c, &i2cTransaction)) {

//                sendMsgToUart("transfer worked\r\n\0");

                uint16_t clearLow = rxBuffer[20];
                uint16_t clearHigh = rxBuffer[21];
                uint16_t redLow = rxBuffer[22];
                uint16_t redHigh = rxBuffer[23];
                uint16_t greenLow = rxBuffer[24];
                uint16_t greenHigh = rxBuffer[25];
                uint16_t blueLow = rxBuffer[26];
                uint16_t blueHigh = rxBuffer[27];

                uint16_t clear = (clearHigh << 8) + clearLow;
                uint16_t red = (redHigh << 8) + redLow;
                uint16_t green = (greenHigh << 8) + greenLow;
                uint16_t blue = (blueHigh << 8) + blueLow;

                float c = (float)clear;
                float r = (float)red / c * 255;
                float g = (float)green / c * 255;
                float b = (float)blue / c *255;

                float answer;

                if (r > 65 && r < 75)
                {
                    if (g > 75 && g > 85)
                    {
                        if (b > 75 && b < 85)
                        {
                            /// it is maroon
                            answer = 0;
                        }
                    }
                }
                else if (r > 120 && r < 130)
                {
                    if (g > 55 && g < 65)
                    {
                        if (b > 50 && b < 60)
                        {
                            // it is orange
                            answer = 1;
                        }
                    }
                }
                else
                {
                    answer = 2;
                }

                char buffer[17];
                snprintf(buffer, sizeof(buffer), "%f", answer);

                sendMsg_MqttQueue("color", "color", buffer);
//
//                char buffer[15];
//                snprintf(buffer, sizeof buffer, "\nred %f", r);
//                UART_write(colorSensorUART, buffer, sizeof(buffer));
//                char buffer2[15];
//                snprintf(buffer2, sizeof buffer2, "green %f", g);
//                UART_write(colorSensorUART, buffer2, sizeof(buffer2));
//                char buffer3[15];
//                snprintf(buffer3, sizeof buffer3, "blue %f", b);
//                UART_write(colorSensorUART, buffer3, sizeof(buffer3));
//                char buffer4[15];
//                snprintf(buffer4, sizeof buffer4, "clear %f", c);
//                UART_write(colorSensorUART, buffer4, sizeof(buffer4));

            }
            else {

                sendMsgToUart("transfer didn't work\r\n\0");

            }

        }
        else
        {
            GPIO_toggle(Board_GPIO2);
        }

//        GPIO_toggle(COLOR_TASK_LED);

        //print to UART

    }
}

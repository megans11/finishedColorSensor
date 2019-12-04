/*
 * color_sensor_driver.c
 *
 */

#include "my_driver_files/color_sensor_driver.h"


/**
 * Initialize I2C used for sensor readings
 */
int init_color_sensor_I2C() {

    strcpy(echoPrompt, "Echoing characters:\r\n");
//    echoPrompt[] = "Echoing characters:\r\n";

    i2c = I2C_open(COLOR_SENSOR_I2C0, &i2cParams);
    if (i2c == NULL) {

        return I2C_INIT_FAIL;
    }
    else {

    }

    //put in values for wxbuffer
    uint8_t COMMAND = 0x80;
    uint8_t ENABLE = 0x01 | 0x02;
    uint8_t ATIME = 0xFF;

    wxBuffer[0] = COMMAND;
    wxBuffer[1] = ENABLE;
    wxBuffer[2] = ATIME;

    /* Common I2C transaction setup */
    i2cTransaction.writeBuf   = wxBuffer;
    i2cTransaction.writeCount = WBUFFER_SIZE;
    i2cTransaction.readBuf    = rxBuffer;
    i2cTransaction.readCount  = RBUFFER_SIZE;
    i2cTransaction.slaveAddress = CSI2C_ADDR;

    return I2C_INIT_SUCCESS;
}

/*
 * Initialize UART used for sensor values
 */
int init_color_sensor_UART() {

//    UART_init();
//
//    UART_Params_init(&uartColorSensorParams);
//    uartColorSensorParams.writeMode = UART_MODE_BLOCKING;
//    uartColorSensorParams.writeDataMode = UART_DATA_BINARY;
//    uartColorSensorParams.baudRate = 115200;
//    uartColorSensorParams.readEcho = UART_ECHO_OFF;

    /* Open UART with header pin selected in sysconfig i.e. UART0 */
//    colorSensorUART = UART_open(COLOR_SENSOR_UART, &uartColorSensorParams);
//    if (colorSensorUART == NULL) {
//        /* Error creating UART */
//        return UART_INIT_FAIL;
//    }
//
//    /* Block read since UART is write-only for this application */
//    UART_control(colorSensorUART, UART_CMD_RXDISABLE, NULL);

    // send baud rate init message
    char cmd = INIT_UART_MSG;

    // write message
    if (UART_write(colorSensorUART, (void *) &cmd, sizeof(cmd)) == UART_STATUS_ERROR)
        return UART_INIT_FAIL;
    return UART_INIT_SUCCESS;
}

/*
 * Generic function to write the colors to UART
 */
int getRGB() {

    sendMsgToUart("in RGB\r\n\0");

    if (I2C_transfer(i2c, &i2cTransaction)) {

        sendMsgToUart("transfer worked\r\n\0");

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

        char buffer[15];
        snprintf(buffer, sizeof buffer, "\nred %f", r);
        UART_write(colorSensorUART, buffer, sizeof(buffer));
        char buffer2[15];
        snprintf(buffer2, sizeof buffer2, "green %f", g);
        UART_write(colorSensorUART, buffer2, sizeof(buffer2));
        char buffer3[15];
        snprintf(buffer3, sizeof buffer3, "blue %f", b);
        UART_write(colorSensorUART, buffer3, sizeof(buffer3));
        char buffer4[15];
        snprintf(buffer4, sizeof buffer4, "clear %f", c);
        UART_write(colorSensorUART, buffer4, sizeof(buffer4));

    }
    else {

        sendMsgToUart("transfer didn't work\r\n\0");

//        *echoPrompt = malloc(100);
//        strcpy(echoPrompt, "I2C Bus fault.");
//        UART_write(colorSensorUART, echoPrompt, sizeof(echoPrompt));

        return GET_COLORS_FAIL;
    }

    return GET_COLORS_SUCCESS;
}





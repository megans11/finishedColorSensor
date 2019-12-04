/*
 * color_sensor_debug.h

 */

#ifndef COLOR_SENSOR_DEBUG_H_
#define COLOR_SENSOR_DEBUG_H_

// Generic success
#define FUNC_SUCCESS 0

// FUNCTIONING DEBUG STATEMENTS
//0x0X messaging
#define SENDING_TO_QUEUE_FROM_ISR 0x00
#define SENT_TO_QUEUE_FROM_ISR 0x01
#define WAITING_QUEUE_RECEIVE 0x02
#define RECEIVED_FROM_QUEUE 0x03

#define ENCODER_BUFFER_TIMER_CALLBACK 0x10

// ERROR DEBUG STATEMENTS:
#define PWM_INIT_FAILURE 0x01
#define PWM_WRITE_FAILURE 0x02

#define SPI_INIT_FAILURE 0x03


#define CONTROL_QUEUE_CREATE_FAILURE 0x13
#define READ_QUEUE_FAILED 0x14
//
#define ENCODER_BUFFER_TIMER_ERROR 0x10


#endif /* COLOR_SENSOR_DEBUG_H_ */

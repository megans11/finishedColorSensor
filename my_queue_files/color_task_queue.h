/*
 * color_task_queue.h
 *
 */

#ifndef COLOR_TASK_QUEUE_H_
#define COLOR_TASK_QUEUE_H_

#include <FreeRTOS.h>
#include <queue.h>

//#include "my_debug_files/debug.h"
#include "my_debug_files/color_sensor_debug.h"
#include "my_queue_files/basic_queue.h"

// message struct types
#define MSG_TYPE_TIMER 0
#define MSG_TYPE_GET_RED 1
#define MSG_TYPE_GET_GREEN 2
#define MSG_TYPE_GET_BLUE 3
#define MSG_TYPE_STOP 4

#define COLOR_VALUE_RED 3
#define COLOR_VALUE_BLUE 4
#define COLOR_VALUE_GREEN 5

// Collection of all queue handles in project
QueueHandle_t colorTaskQueue;

// Public queue functions
int create_ColorTaskQueue();
int getRedColor_ColorTaskQueue(int color);
int getBlueColor_ColorTaskQueue(int color);
int getGreenColor_ColorTaskQueue(int color);
int timerExpired_ColorTaskQueue(unsigned int time_elapsed);
int stop_ColorTaskQueue();
int readMsg_ColorTaskQueue(unsigned int *buffer_dist);


#endif /* COLOR_TASK_QUEUE_H_ */

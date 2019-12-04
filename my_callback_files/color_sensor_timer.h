/*
 *  Created on: Sep 29, 2019
 *      Author: Megan Salvatore
 */

#ifndef COLOR_SENSOR_TIMER_H
#define COLOR_SENSOR_TIMER_H

#include <ti/drivers/Timer.h>
#include "Board.h"
//#include "my_debug_files/debug.h"
//#include "my_debug_files/color_sensor_debug.h"
//#include "my_queue_files/color_task_queue.h"
#include <time.h>
#include <stdlib.h>

#define COLOR_SENSOR_TIMER_PERIOD 200000 // .1s
#define TIMER_FAILURE -1
#define TIMER_SUCCESS 0

Timer_Handle color_sensor_timer;
Timer_Params color_sensor_params;

int init_colorSensorTimer();
void colorSensorTimerCallback(Timer_Handle myHandle);

#endif /* COLOR_SENSOR_TIMER_H_ */

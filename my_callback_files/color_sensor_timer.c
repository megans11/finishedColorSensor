/*
    color_sensor_timer.c
 */
#include <my_callback_files/color_sensor_timer.h>
//#include <my_driver_files/color_sensor_driver.h>

/*
 * This callback sends the time since last ISR call in ms to queue 1
 */
void colorSensorTimerCallback(Timer_Handle myHandle) {

    static struct timespec current_time, last_time = {0,0};

    GPIO_toggle(COLOR_TASK_LED);

    clock_gettime(CLOCK_REALTIME, &current_time);
    long cpu_time_used = (current_time.tv_nsec - last_time.tv_nsec) / 1000000; // ms

    // handle clock rollover
    if (last_time.tv_nsec > current_time.tv_nsec) { // clock underflow
        cpu_time_used += 1000;
    }

    timerExpired_ColorTaskQueue((unsigned int) cpu_time_used);

    clock_gettime(CLOCK_REALTIME, &last_time);

}

int init_colorSensorTimer() {

//    Timer_init();
//
//    // init timer
//    Timer_Params_init(&color_sensor_params);
//    color_sensor_params.period = COLOR_SENSOR_TIMER_PERIOD;
//    color_sensor_params.periodUnits = Timer_PERIOD_US;
//    color_sensor_params.timerMode = Timer_CONTINUOUS_CALLBACK;
//    color_sensor_params.timerCallback = colorSensorTimerCallback;

//      start timer
     color_sensor_timer = Timer_open(COLOR_SENSOR_TIMER, &color_sensor_params);

     if (color_sensor_timer == NULL) {
         /* Failed to initialized timer */
//         errorRoutine(ENCODER_BUFFER_TIMER_ERROR);
         return TIMER_FAILURE;
     }

     if (Timer_start(color_sensor_timer) == Timer_STATUS_ERROR) {
         /* Failed to start timer */
//         errorRoutine(ENCODER_BUFFER_TIMER_ERROR);
         return TIMER_FAILURE;
     }

     return TIMER_SUCCESS;
}

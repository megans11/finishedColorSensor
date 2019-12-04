/*
 * colorTaskQueue.c
 *
 */

#include <my_queue_files/color_task_queue.h>



/**
 * Wrapper for createQueue to create predefined queue1
 */
int create_ColorTaskQueue(){
    return createQueue(&colorTaskQueue);
}


/**
 * Sends command to get value of sensor
 */
int getRedColor_ColorTaskQueue(int color){

    message_type msg;

    msg[MSG_TYPE] = MSG_TYPE_GET_RED;
    msg[MSG_DATA] = (unsigned int) color;

    return sendMsgToQueue(colorTaskQueue, &msg);
}

/**
 * Sends command to get value of sensor
 */
int getGreenColor_ColorTaskQueue(int color){

    message_type msg;

    msg[MSG_TYPE] = MSG_TYPE_GET_GREEN;
    msg[MSG_DATA] = (unsigned int) color;

    return sendMsgToQueue(colorTaskQueue, &msg);
}

/**
 * Sends command to get value of sensor
 */
int getBlueColor_ColorTaskQueue(int color){

    message_type msg;

    msg[MSG_TYPE] = MSG_TYPE_GET_BLUE;
    msg[MSG_DATA] = (unsigned int) color;

    return sendMsgToQueue(colorTaskQueue, &msg);
}

int timerExpired_ColorTaskQueue(unsigned int time_elapsed) {

    message_type msg;
    msg[MSG_TYPE] = MSG_TYPE_TIMER;
    msg[MSG_DATA] = time_elapsed;

    return sendMsgToQueue_ISR(colorTaskQueue, &msg);
}

/*
 * Message send from timer callback.
 */
int stop_ColorTaskQueue() {

    message_type msg;
    msg[MSG_TYPE] = MSG_TYPE_STOP;
    msg[MSG_DATA] = 0;

    return sendMsgToQueue_ISR(colorTaskQueue, &msg);
}

/**
 * Blocking read from Queue 1. Fills correct buffer, return type specifies type received.
 */
int readMsg_ColorTaskQueue(unsigned int *amount){
    message_type msg_buffer;

    // Debug before receiving from queue in ISR
    int read_status = readMsqFromQueue(colorTaskQueue, &msg_buffer);

    // Block until message, check if valid
    if (read_status == READ_SUCCESS) {

        // Fill correct buffer
        switch (msg_buffer[MSG_TYPE]){
        case MSG_TYPE_TIMER:
            *amount = msg_buffer[MSG_DATA];
            return MSG_TYPE_TIMER;
        case MSG_TYPE_GET_RED:
            *amount = msg_buffer[MSG_DATA];
            return MSG_TYPE_GET_RED;
        case MSG_TYPE_GET_GREEN:
            *amount = msg_buffer[MSG_DATA];
            return MSG_TYPE_GET_GREEN;
        case MSG_TYPE_GET_BLUE:
            *amount = msg_buffer[MSG_DATA];
            return MSG_TYPE_GET_BLUE;
        case MSG_TYPE_STOP:
            *amount = NULL;
            return MSG_TYPE_STOP;
        default:
            errorRoutine(READ_QUEUE_FAILED);
        }
    }

    //if no returns were called earlier, then read fail
    return READ_FAILURE;
}

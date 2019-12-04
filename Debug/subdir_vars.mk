################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../CC3220SF_LAUNCHXL_FREERTOS.cmd 

SYSCFG_SRCS += \
../common.syscfg 

C_SRCS += \
../client_cbs.c \
./syscfg/ti_drivers_net_wifi_config.c \
./syscfg/Board.c \
../debug.c \
../find_color_task_thread.c \
../jsonParse.c \
../main_freertos.c \
../mqtt_client_app.c \
../network_if.c \
../uart_thread.c 

GEN_FILES += \
./syscfg/ti_drivers_net_wifi_config.c \
./syscfg/Board.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./client_cbs.d \
./syscfg/ti_drivers_net_wifi_config.d \
./syscfg/Board.d \
./debug.d \
./find_color_task_thread.d \
./jsonParse.d \
./main_freertos.d \
./mqtt_client_app.d \
./network_if.d \
./uart_thread.d 

OBJS += \
./client_cbs.obj \
./syscfg/ti_drivers_net_wifi_config.obj \
./syscfg/Board.obj \
./debug.obj \
./find_color_task_thread.obj \
./jsonParse.obj \
./main_freertos.obj \
./mqtt_client_app.obj \
./network_if.obj \
./uart_thread.obj 

GEN_MISC_FILES += \
./syscfg/Board.h 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"client_cbs.obj" \
"syscfg\ti_drivers_net_wifi_config.obj" \
"syscfg\Board.obj" \
"debug.obj" \
"find_color_task_thread.obj" \
"jsonParse.obj" \
"main_freertos.obj" \
"mqtt_client_app.obj" \
"network_if.obj" \
"uart_thread.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\Board.h" 

C_DEPS__QUOTED += \
"client_cbs.d" \
"syscfg\ti_drivers_net_wifi_config.d" \
"syscfg\Board.d" \
"debug.d" \
"find_color_task_thread.d" \
"jsonParse.d" \
"main_freertos.d" \
"mqtt_client_app.d" \
"network_if.d" \
"uart_thread.d" 

GEN_FILES__QUOTED += \
"syscfg\ti_drivers_net_wifi_config.c" \
"syscfg\Board.c" 

C_SRCS__QUOTED += \
"../client_cbs.c" \
"./syscfg/ti_drivers_net_wifi_config.c" \
"./syscfg/Board.c" \
"../debug.c" \
"../find_color_task_thread.c" \
"../jsonParse.c" \
"../main_freertos.c" \
"../mqtt_client_app.c" \
"../network_if.c" \
"../uart_thread.c" 

SYSCFG_SRCS__QUOTED += \
"../common.syscfg" 



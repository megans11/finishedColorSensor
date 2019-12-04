################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
my_driver_files/%.obj: ../my_driver_files/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/megan/Documents/CLASSES/Embedded/workspace/init7_intercomponent_milestone_CC3220SF_LAUNCHXL_freertos_ccs_syscfg3" --include_path="C:/Users/megan/Documents/CLASSES/Embedded/workspace/init7_intercomponent_milestone_CC3220SF_LAUNCHXL_freertos_ccs_syscfg3/Debug" --include_path="C:/ti/simplelink_cc32xx_sdk_3_20_00_06/source" --include_path="C:/ti/simplelink_cc32xx_sdk_3_20_00_06/source/ti/posix/ccs" --include_path="C:/Users/megan/Downloads/FreeRTOSv10.2.1/FreeRTOS/Source/include" --include_path="C:/Users/megan/Downloads/FreeRTOSv10.2.1/FreeRTOS/Source/portable/CCS/ARM_CM3" --include_path="C:/Users/megan/Documents/CLASSES/Embedded/workspace/freertos_builds_CC3220SF_LAUNCHXL_release_ccs" --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="my_driver_files/$(basename $(<F)).d_raw" --include_path="C:/Users/megan/Documents/CLASSES/Embedded/workspace/init7_intercomponent_milestone_CC3220SF_LAUNCHXL_freertos_ccs_syscfg3/Debug/syscfg" --obj_directory="my_driver_files" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



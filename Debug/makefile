################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS

GEN_OPTS__FLAG := @"./device.opt" 
GEN_CMDS__FLAG := -Wl,-l"./device_linker.cmd" 

ORDERED_OBJS += \
"./main.o" \
"./ti_msp_dl_config.o" \
"./startup_mspm0g350x_ticlang.o" \
"./Drivers/ADC/ADC.o" \
"./Drivers/Blue_teeth/Blue_teeth.o" \
"./Drivers/Clock/Clock.o" \
"./Drivers/Encoder/Encoder.o" \
"./Drivers/Grayscale_Sensor/Grayscale_Sensor.o" \
"./Drivers/OLED_Software_I2C/oled_software_i2c.o" \
"./Drivers/Ultrasonic_GPIO/ultrasonic_gpio.o" \
"./Drivers/car/car.o" \
"./Drivers/pid/pid.o" \
"./Drivers/servo/servo.o" \
$(GEN_CMDS__FLAG) \
-Wl,-ldevice.cmd.genlibs \
-Wl,-llibc.a \
-Wl,-l"D:/ti/mspm0_sdk_2_05_01_00/source/ti/driverlib/lib/ticlang/m0p/mspm0g1x0x_g3x0x/driverlib.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Drivers/ADC/subdir_vars.mk
-include Drivers/Blue_teeth/subdir_vars.mk
-include Drivers/Clock/subdir_vars.mk
-include Drivers/Encoder/subdir_vars.mk
-include Drivers/Grayscale_Sensor/subdir_vars.mk
-include Drivers/OLED_Software_I2C/subdir_vars.mk
-include Drivers/Ultrasonic_GPIO/subdir_vars.mk
-include Drivers/car/subdir_vars.mk
-include Drivers/pid/subdir_vars.mk
-include Drivers/servo/subdir_vars.mk
-include subdir_rules.mk
-include Drivers/ADC/subdir_rules.mk
-include Drivers/Blue_teeth/subdir_rules.mk
-include Drivers/Clock/subdir_rules.mk
-include Drivers/Encoder/subdir_rules.mk
-include Drivers/Grayscale_Sensor/subdir_rules.mk
-include Drivers/OLED_Software_I2C/subdir_rules.mk
-include Drivers/Ultrasonic_GPIO/subdir_rules.mk
-include Drivers/car/subdir_rules.mk
-include Drivers/pid/subdir_rules.mk
-include Drivers/servo/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
mpu6050-oled-software-i2c.out 

EXE_OUTPUTS__QUOTED += \
"mpu6050-oled-software-i2c.out" 


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "mpu6050-oled-software-i2c.out"

# Tool invocations
mpu6050-oled-software-i2c.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"D:/ti/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -Wl,-m"mpu6050-oled-software-i2c.map" -Wl,-i"D:/ti/mspm0_sdk_2_05_01_00/source" -Wl,-i"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c" -Wl,-i"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Debug/syscfg" -Wl,-i"D:/ti/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/lib" -Wl,--diag_wrap=off -Wl,--display_error_number -Wl,--warn_sections -Wl,--xml_link_info="mpu6050-oled-software-i2c_linkInfo.xml" -Wl,--rom_model -o "mpu6050-oled-software-i2c.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.o" "ti_msp_dl_config.o" "startup_mspm0g350x_ticlang.o" "Drivers\ADC\ADC.o" "Drivers\Blue_teeth\Blue_teeth.o" "Drivers\Clock\Clock.o" "Drivers\Encoder\Encoder.o" "Drivers\Grayscale_Sensor\Grayscale_Sensor.o" "Drivers\OLED_Software_I2C\oled_software_i2c.o" "Drivers\Ultrasonic_GPIO\ultrasonic_gpio.o" "Drivers\car\car.o" "Drivers\pid\pid.o" "Drivers\servo\servo.o" 
	-$(RM) "main.d" "ti_msp_dl_config.d" "startup_mspm0g350x_ticlang.d" "Drivers\ADC\ADC.d" "Drivers\Blue_teeth\Blue_teeth.d" "Drivers\Clock\Clock.d" "Drivers\Encoder\Encoder.d" "Drivers\Grayscale_Sensor\Grayscale_Sensor.d" "Drivers\OLED_Software_I2C\oled_software_i2c.d" "Drivers\Ultrasonic_GPIO\ultrasonic_gpio.d" "Drivers\car\car.d" "Drivers\pid\pid.d" "Drivers\servo\servo.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


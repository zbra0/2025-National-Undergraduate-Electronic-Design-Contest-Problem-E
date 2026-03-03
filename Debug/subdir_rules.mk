################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/BNO08X_UART_RVC" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Blue_teeth" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Ultrasonic_GPIO" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/pid" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Ultrasonic_Capture" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_I2C" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/servo" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Encoder" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Clock" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_SPI" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Software_I2C" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Software_SPI" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/pid" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/ADC" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/car" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/MPU6050" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Debug" -I"D:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_05_01_00/source" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/MSPM0" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/WIT" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Grayscale_Sensor" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1093740705: ../mpu6050-oled-software-i2c.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/ti/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/mpu6050-oled-software-i2c.syscfg" -o "." -s "D:/ti/mspm0_sdk_2_05_01_00/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1093740705 ../mpu6050-oled-software-i2c.syscfg
device.opt: build-1093740705
device.cmd.genlibs: build-1093740705
ti_msp_dl_config.c: build-1093740705
ti_msp_dl_config.h: build-1093740705
Event.dot: build-1093740705

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/BNO08X_UART_RVC" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Blue_teeth" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Ultrasonic_GPIO" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/pid" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Ultrasonic_Capture" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_I2C" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/servo" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Encoder" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Clock" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_SPI" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Software_I2C" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Software_SPI" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/pid" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/ADC" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/car" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/MPU6050" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Debug" -I"D:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_05_01_00/source" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/MSPM0" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/WIT" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Grayscale_Sensor" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: D:/ti/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/BNO08X_UART_RVC" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Blue_teeth" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Ultrasonic_GPIO" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/pid" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Ultrasonic_Capture" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_I2C" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/servo" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Encoder" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Clock" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_SPI" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Software_I2C" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Software_SPI" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/pid" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/ADC" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/car" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/MPU6050" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Debug" -I"D:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_05_01_00/source" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/MSPM0" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/WIT" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Grayscale_Sensor" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



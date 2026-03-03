################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/Ultrasonic_GPIO/%.o: ../Drivers/Ultrasonic_GPIO/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/BNO08X_UART_RVC" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Blue_teeth" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Ultrasonic_GPIO" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/pid" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Ultrasonic_Capture" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_I2C" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/servo" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Encoder" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Clock" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_SPI" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Software_I2C" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/OLED_Software_SPI" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/pid" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/ADC" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/car" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/MPU6050" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Debug" -I"D:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_05_01_00/source" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/MSPM0" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/WIT" -I"D:/桌面/wzu/大二/2025电赛/ti舵机云台小车/mpu6050-oled-software-i2c/Drivers/Grayscale_Sensor" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/Ultrasonic_GPIO/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



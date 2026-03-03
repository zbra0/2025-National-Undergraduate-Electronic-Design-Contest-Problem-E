################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/MSPM0/%.o: ../Drivers/MSPM0/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"F:/TI/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/BNO08X_UART_RVC" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/Ultrasonic_GPIO" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/Ultrasonic_Capture" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_I2C" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/Encoder" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/Clock" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/OLED_Hardware_SPI" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/OLED_Software_I2C" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/OLED_Software_SPI" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/pid" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/ADC" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/car" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/MPU6050" -I"F:/TIproject/mpu6050-oled-software-i2c" -I"F:/TIproject/mpu6050-oled-software-i2c/Debug" -I"F:/TI/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"F:/TI/mspm0_sdk_2_05_01_00/source" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/MSPM0" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/WIT" -I"F:/TIproject/mpu6050-oled-software-i2c/Drivers/Grayscale_Sensor" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/MSPM0/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



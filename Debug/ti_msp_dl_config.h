/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMA0
#define PWM_0_INST_IRQHandler                                   TIMA0_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMA0_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                             80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOA
#define GPIO_PWM_0_C0_PIN                                          DL_GPIO_PIN_0
#define GPIO_PWM_0_C0_IOMUX                                       (IOMUX_PINCM1)
#define GPIO_PWM_0_C0_IOMUX_FUNC                      IOMUX_PINCM1_PF_TIMA0_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOA
#define GPIO_PWM_0_C1_PIN                                          DL_GPIO_PIN_1
#define GPIO_PWM_0_C1_IOMUX                                       (IOMUX_PINCM2)
#define GPIO_PWM_0_C1_IOMUX_FUNC                      IOMUX_PINCM2_PF_TIMA0_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX

/* Defines for servo */
#define servo_INST                                                         TIMG6
#define servo_INST_IRQHandler                                   TIMG6_IRQHandler
#define servo_INST_INT_IRQN                                     (TIMG6_INT_IRQn)
#define servo_INST_CLK_FREQ                                              1000000
/* GPIO defines for channel 0 */
#define GPIO_servo_C0_PORT                                                 GPIOA
#define GPIO_servo_C0_PIN                                         DL_GPIO_PIN_21
#define GPIO_servo_C0_IOMUX                                      (IOMUX_PINCM46)
#define GPIO_servo_C0_IOMUX_FUNC                     IOMUX_PINCM46_PF_TIMG6_CCP0
#define GPIO_servo_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_servo_C1_PORT                                                 GPIOA
#define GPIO_servo_C1_PIN                                         DL_GPIO_PIN_22
#define GPIO_servo_C1_IOMUX                                      (IOMUX_PINCM47)
#define GPIO_servo_C1_IOMUX_FUNC                     IOMUX_PINCM47_PF_TIMG6_CCP1
#define GPIO_servo_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_ULTRASONIC */
#define TIMER_ULTRASONIC_INST                                            (TIMG8)
#define TIMER_ULTRASONIC_INST_IRQHandler                        TIMG8_IRQHandler
#define TIMER_ULTRASONIC_INST_INT_IRQN                          (TIMG8_INT_IRQn)
#define TIMER_ULTRASONIC_INST_LOAD_VALUE                                (19999U)
/* Defines for TIMER_Encoder_speed */
#define TIMER_Encoder_speed_INST                                         (TIMG0)
#define TIMER_Encoder_speed_INST_IRQHandler                        TIMG0_IRQHandler
#define TIMER_Encoder_speed_INST_INT_IRQN                        (TIMG0_INT_IRQn)
#define TIMER_Encoder_speed_INST_LOAD_VALUE                                 (4999U)




/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C0
#define I2C_MPU6050_INST_IRQHandler                              I2C0_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C0_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          400000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SDA_PIN                                  DL_GPIO_PIN_28
#define GPIO_I2C_MPU6050_IOMUX_SDA                                (IOMUX_PINCM3)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                 IOMUX_PINCM3_PF_I2C0_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SCL_PIN                                  DL_GPIO_PIN_31
#define GPIO_I2C_MPU6050_IOMUX_SCL                                (IOMUX_PINCM6)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                 IOMUX_PINCM6_PF_I2C0_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART2
#define UART_0_INST_FREQUENCY                                 13333333.333333334
#define UART_0_INST_IRQHandler                                  UART2_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART2_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_24
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_23
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM54)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM53)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM54_PF_UART2_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM53_PF_UART2_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_13_MHZ_9600_BAUD                                        (86)
#define UART_0_FBRD_13_MHZ_9600_BAUD                                        (52)





/* Defines for ADC1 */
#define ADC1_INST                                                           ADC1
#define ADC1_INST_IRQHandler                                     ADC1_IRQHandler
#define ADC1_INST_INT_IRQN                                       (ADC1_INT_IRQn)
#define ADC1_ADCMEM_0                                         DL_ADC12_MEM_IDX_0
#define ADC1_ADCMEM_0_REF                        DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC1_ADCMEM_0_REF_VOLTAGE_V                                          3.3
#define GPIO_ADC1_C0_PORT                                                  GPIOA
#define GPIO_ADC1_C0_PIN                                          DL_GPIO_PIN_15



/* Port definition for Pin Group GPIO_MPU6050 */
#define GPIO_MPU6050_PORT                                                (GPIOB)

/* Defines for PIN_INT: GPIOB.1 with pinCMx 13 on package pin 48 */
// groups represented: ["GPIO_Encoder_Left","GPIO_MPU6050"]
// pins affected: ["PIN_Aphase","PIN_Bphase","PIN_INT"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_MPU6050_PIN_INT_IIDX                            (DL_GPIO_IIDX_DIO1)
#define GPIO_MPU6050_PIN_INT_PIN                                 (DL_GPIO_PIN_1)
#define GPIO_MPU6050_PIN_INT_IOMUX                               (IOMUX_PINCM13)
/* Port definition for Pin Group GPIO_OLED */
#define GPIO_OLED_PORT                                                   (GPIOB)

/* Defines for PIN_SCL: GPIOB.2 with pinCMx 15 on package pin 50 */
#define GPIO_OLED_PIN_SCL_PIN                                    (DL_GPIO_PIN_2)
#define GPIO_OLED_PIN_SCL_IOMUX                                  (IOMUX_PINCM15)
/* Defines for PIN_SDA: GPIOB.3 with pinCMx 16 on package pin 51 */
#define GPIO_OLED_PIN_SDA_PIN                                    (DL_GPIO_PIN_3)
#define GPIO_OLED_PIN_SDA_IOMUX                                  (IOMUX_PINCM16)
/* Port definition for Pin Group GPIO_Motor */
#define GPIO_Motor_PORT                                                  (GPIOB)

/* Defines for ain1: GPIOB.11 with pinCMx 28 on package pin 63 */
#define GPIO_Motor_ain1_PIN                                     (DL_GPIO_PIN_11)
#define GPIO_Motor_ain1_IOMUX                                    (IOMUX_PINCM28)
/* Defines for ain2: GPIOB.12 with pinCMx 29 on package pin 64 */
#define GPIO_Motor_ain2_PIN                                     (DL_GPIO_PIN_12)
#define GPIO_Motor_ain2_IOMUX                                    (IOMUX_PINCM29)
/* Defines for bin1: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_Motor_bin1_PIN                                      (DL_GPIO_PIN_9)
#define GPIO_Motor_bin1_IOMUX                                    (IOMUX_PINCM26)
/* Defines for bin2: GPIOB.10 with pinCMx 27 on package pin 62 */
#define GPIO_Motor_bin2_PIN                                     (DL_GPIO_PIN_10)
#define GPIO_Motor_bin2_IOMUX                                    (IOMUX_PINCM27)
/* Port definition for Pin Group Gray_Address */
#define Gray_Address_PORT                                                (GPIOB)

/* Defines for PIN_0: GPIOB.0 with pinCMx 12 on package pin 47 */
#define Gray_Address_PIN_0_PIN                                   (DL_GPIO_PIN_0)
#define Gray_Address_PIN_0_IOMUX                                 (IOMUX_PINCM12)
/* Defines for PIN_1: GPIOB.14 with pinCMx 31 on package pin 2 */
#define Gray_Address_PIN_1_PIN                                  (DL_GPIO_PIN_14)
#define Gray_Address_PIN_1_IOMUX                                 (IOMUX_PINCM31)
/* Defines for PIN_2: GPIOB.15 with pinCMx 32 on package pin 3 */
#define Gray_Address_PIN_2_PIN                                  (DL_GPIO_PIN_15)
#define Gray_Address_PIN_2_IOMUX                                 (IOMUX_PINCM32)
/* Port definition for Pin Group GPIO_Encoder_Left */
#define GPIO_Encoder_Left_PORT                                           (GPIOB)

/* Defines for PIN_Aphase: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_Encoder_Left_PIN_Aphase_IIDX                   (DL_GPIO_IIDX_DIO13)
#define GPIO_Encoder_Left_PIN_Aphase_PIN                        (DL_GPIO_PIN_13)
#define GPIO_Encoder_Left_PIN_Aphase_IOMUX                       (IOMUX_PINCM30)
/* Defines for PIN_Bphase: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_Encoder_Left_PIN_Bphase_IIDX                   (DL_GPIO_IIDX_DIO16)
#define GPIO_Encoder_Left_PIN_Bphase_PIN                        (DL_GPIO_PIN_16)
#define GPIO_Encoder_Left_PIN_Bphase_IOMUX                       (IOMUX_PINCM33)
/* Port definition for Pin Group GPIO_Encoder_Right */
#define GPIO_Encoder_Right_PORT                                          (GPIOA)

/* Defines for PIN_Aphase_r: GPIOA.12 with pinCMx 34 on package pin 5 */
// pins affected by this interrupt request:["PIN_Aphase_r","PIN_Bphase_r"]
#define GPIO_Encoder_Right_INT_IRQN                             (GPIOA_INT_IRQn)
#define GPIO_Encoder_Right_INT_IIDX             (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_Encoder_Right_PIN_Aphase_r_IIDX                (DL_GPIO_IIDX_DIO12)
#define GPIO_Encoder_Right_PIN_Aphase_r_PIN                     (DL_GPIO_PIN_12)
#define GPIO_Encoder_Right_PIN_Aphase_r_IOMUX                    (IOMUX_PINCM34)
/* Defines for PIN_Bphase_r: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_Encoder_Right_PIN_Bphase_r_IIDX                (DL_GPIO_IIDX_DIO13)
#define GPIO_Encoder_Right_PIN_Bphase_r_PIN                     (DL_GPIO_PIN_13)
#define GPIO_Encoder_Right_PIN_Bphase_r_IOMUX                    (IOMUX_PINCM35)
/* Port definition for Pin Group GPIO_ULTRASONIC */
#define GPIO_ULTRASONIC_PORT                                             (GPIOB)

/* Defines for PIN_TRIG: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_ULTRASONIC_PIN_TRIG_PIN                             (DL_GPIO_PIN_8)
#define GPIO_ULTRASONIC_PIN_TRIG_IOMUX                           (IOMUX_PINCM25)
/* Defines for PIN_ECHO: GPIOB.7 with pinCMx 24 on package pin 59 */
#define GPIO_ULTRASONIC_PIN_ECHO_PIN                             (DL_GPIO_PIN_7)
#define GPIO_ULTRASONIC_PIN_ECHO_IOMUX                           (IOMUX_PINCM24)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_servo_init(void);
void SYSCFG_DL_TIMER_ULTRASONIC_init(void);
void SYSCFG_DL_TIMER_Encoder_speed_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_ADC1_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */

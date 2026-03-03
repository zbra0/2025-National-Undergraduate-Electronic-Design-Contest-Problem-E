#include "Encoder.h"
#include "ti_msp_dl_config.h"
#include "oled_software_i2c.h"
#include "stdio.h"
#include "string.h"
/*编码器*/
extern int L_Distance,R_Distance,L_Encoder_speed,R_Encoder_speed,L_Distance_last,R_Distance_last;

void GROUP1_IRQHandler(void)
{
    #if defined GPIO_Encoder_Left_PORT
        #if defined GPIO_Encoder_Right_PORT
    uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_Left_PORT,GPIO_Encoder_Left_PIN_Aphase_PIN | GPIO_Encoder_Left_PIN_Bphase_PIN);
    uint32_t gpioA = DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_Right_PORT,GPIO_Encoder_Right_PIN_Aphase_r_PIN | GPIO_Encoder_Right_PIN_Bphase_r_PIN);
    if((gpioB & GPIO_Encoder_Left_PIN_Aphase_PIN) == GPIO_Encoder_Left_PIN_Aphase_PIN )
    {
        if(DL_GPIO_readPins(GPIO_Encoder_Left_PORT,GPIO_Encoder_Left_PIN_Bphase_PIN) == 1)
            L_Distance --;
        else if(DL_GPIO_readPins(GPIO_Encoder_Left_PORT,GPIO_Encoder_Left_PIN_Bphase_PIN) == 0)
            L_Distance++;
        DL_GPIO_clearInterruptStatus(GPIO_Encoder_Left_PORT, GPIO_Encoder_Left_PIN_Aphase_PIN);

    }
    else if((gpioB & GPIO_Encoder_Left_PIN_Bphase_PIN) == GPIO_Encoder_Left_PIN_Bphase_PIN )
    {
        if(DL_GPIO_readPins(GPIO_Encoder_Left_PORT,GPIO_Encoder_Left_PIN_Aphase_PIN) == 0)
            L_Distance --;
        else if(DL_GPIO_readPins(GPIO_Encoder_Left_PORT,GPIO_Encoder_Left_PIN_Aphase_PIN) == 1)
             L_Distance ++;
        DL_GPIO_clearInterruptStatus(GPIO_Encoder_Left_PORT, GPIO_Encoder_Left_PIN_Bphase_PIN);

    }
    else if((gpioA & GPIO_Encoder_Right_PIN_Aphase_r_PIN) == GPIO_Encoder_Right_PIN_Aphase_r_PIN )
    {
        if(DL_GPIO_readPins(GPIO_Encoder_Right_PORT,GPIO_Encoder_Right_PIN_Bphase_r_PIN) == 1)
            R_Distance --;
        else if(DL_GPIO_readPins(GPIO_Encoder_Right_PORT,GPIO_Encoder_Right_PIN_Bphase_r_PIN) == 0)
            R_Distance++;
        DL_GPIO_clearInterruptStatus(GPIO_Encoder_Right_PORT, GPIO_Encoder_Right_PIN_Aphase_r_PIN);
    }
    else if((gpioA & GPIO_Encoder_Right_PIN_Bphase_r_PIN) == GPIO_Encoder_Right_PIN_Bphase_r_PIN )
    {
        if(DL_GPIO_readPins(GPIO_Encoder_Right_PORT,GPIO_Encoder_Right_PIN_Aphase_r_PIN) == 0)
            R_Distance --;
        else if(DL_GPIO_readPins(GPIO_Encoder_Right_PORT,GPIO_Encoder_Right_PIN_Aphase_r_PIN) == 1)
            R_Distance ++;
        DL_GPIO_clearInterruptStatus(GPIO_Encoder_Right_PORT, GPIO_Encoder_Right_PIN_Bphase_r_PIN);
    }
    #endif
        #endif
    // else
    // {
    //     switch (DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) {
    //     /* MPU6050 INT */
    //     #if defined GPIO_MPU6050_PORT
    //         #if defined GPIO_MPU6050_INT_IIDX
    //         case GPIO_MPU6050_INT_IIDX:
    //         #elif (GPIO_MPU6050_PORT == GPIOA) && (defined GPIO_MULTIPLE_GPIOA_INT_IIDX)
    //         case GPIO_MULTIPLE_GPIOA_INT_IIDX:
    //         #elif (GPIO_MPU6050_PORT == GPIOB) && (defined GPIO_MULTIPLE_GPIOB_INT_IIDX)
    //         case GPIO_MULTIPLE_GPIOB_INT_IIDX:
    //         #endif
    //             Read_Quad();
    //             break;
    //     #endif
    //     }
    // }
}


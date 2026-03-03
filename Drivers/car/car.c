#include "ti_msp_dl_config.h"
#include "car.h"
#include "pid.h"
#include "Clock.h"

#include "mpu6050.h"
#include "oled_software_i2c.h"
#include "oled_hardware_i2c.h"
#include "oled_software_spi.h"
#include "oled_hardware_spi.h"
#include "ultrasonic_capture.h"
#include "ultrasonic_gpio.h"
#include "bno08x_uart_rvc.h"
#define first_car 1
#define Judge_method 1
//#define PID_method 1
//#define OLD_car 1

#if defined (first_car)
/*first car*/
#define speed_MMAX 25
#define speed_MAX 20
#define speed_MID 15
#define speed_MIN 1
#define speed_MICRO 1
#elif defined (second_car)
/*second car*/
#define speed_MAX 16
#define speed_MID 14
#define speed_MIN 12
#define speed_MICRO 10
#endif

#define forward 0
#define backward 1
extern unsigned short Normal[8];
extern uint8_t SP_buffer[32];
int flag_circle=1;
int flag_stop=1;
extern int L_Distance,R_Distance,L_Encoder_speed,R_Encoder_speed,L_Distance_last,R_Distance_last,encoder_dis;
#if defined(Judge_method)
int flag_judge=0;
void Motor_LeftSpeed(unsigned long int speed,unsigned long int angle)
{
    DL_TimerA_setCaptureCompareValue(PWM_0_INST, (100-speed)*10, DL_TIMER_CC_0_INDEX);
    if(angle==0)
    {
        DL_GPIO_setPins(GPIO_Motor_PORT,GPIO_Motor_ain2_PIN);
        DL_GPIO_clearPins(GPIO_Motor_PORT,GPIO_Motor_ain1_PIN);
    }
    else  
    {
        DL_GPIO_setPins(GPIO_Motor_PORT,GPIO_Motor_ain1_PIN);
        DL_GPIO_clearPins(GPIO_Motor_PORT,GPIO_Motor_ain2_PIN);
    }
}

void Motor_RightSpeed(unsigned long int speed,unsigned long int angle)
{
    DL_TimerA_setCaptureCompareValue(PWM_0_INST, (100-speed)*10, DL_TIMER_CC_1_INDEX);
    if(angle==0)
    {
        DL_GPIO_setPins(GPIO_Motor_PORT,GPIO_Motor_bin1_PIN);
        DL_GPIO_clearPins(GPIO_Motor_PORT,GPIO_Motor_bin2_PIN);
    }
    else 
    {
        DL_GPIO_setPins(GPIO_Motor_PORT,GPIO_Motor_bin2_PIN);
        DL_GPIO_clearPins(GPIO_Motor_PORT,GPIO_Motor_bin1_PIN);
    }
}
#elif defined (PID_method)
int flag_getin=1;
int angle_turn = 0;
int speed_Dilta_wu = 0;
int speed_Base_wu = -8;
void Motor_LeftSpeed(unsigned long int speed,unsigned long int direct)
{
    DL_TimerA_setCaptureCompareValue(PWM_0_INST, (100-speed)*10, DL_TIMER_CC_0_INDEX);
    if(direct == forward)
    {
        DL_GPIO_setPins(GPIO_Motor_PORT,GPIO_Motor_ain1_PIN);
        DL_GPIO_clearPins(GPIO_Motor_PORT,GPIO_Motor_ain2_PIN);
    }
    else if(direct==backward) 
    {
        DL_GPIO_setPins(GPIO_Motor_PORT,GPIO_Motor_ain2_PIN);
        DL_GPIO_clearPins(GPIO_Motor_PORT,GPIO_Motor_ain1_PIN);
    }
}

void Motor_RightSpeed(unsigned long int speed,unsigned long int direct)
{
    DL_TimerA_setCaptureCompareValue(PWM_0_INST, (100-speed)*10, DL_TIMER_CC_1_INDEX);
    if(direct == forward)
    {
        DL_GPIO_setPins(GPIO_Motor_PORT,GPIO_Motor_bin1_PIN);
        DL_GPIO_clearPins(GPIO_Motor_PORT,GPIO_Motor_bin2_PIN);
    }
    else if(direct==backward)
    {
        DL_GPIO_setPins(GPIO_Motor_PORT,GPIO_Motor_bin2_PIN);
        DL_GPIO_clearPins(GPIO_Motor_PORT,GPIO_Motor_bin1_PIN);
    }
}
#endif
int left_speed;
int right_speed;


#if defined (second_car)
/*old car*/
void Go_Ahead(){
	Motor_LeftSpeed(20,0);
	Motor_RightSpeed(20,0);
}
void Go_Back(){
	Motor_LeftSpeed(20,1);
	Motor_RightSpeed(20,1);
}
void Turn_ssLeft(){
	Motor_LeftSpeed(16,0);
	Motor_RightSpeed(18,0);
}
void Turn_ssRight(){
	Motor_RightSpeed(16,0);
	Motor_LeftSpeed(18,0);
}
void Turn_sLeft(){
	Motor_LeftSpeed(15,0);
	Motor_RightSpeed(18,0);
}
void Turn_sRight(){
	Motor_RightSpeed(15,0);
	Motor_LeftSpeed(18,0);
}

void Turn_Left(){
	Motor_LeftSpeed(13,0);
	Motor_RightSpeed(20,0);
}
void Turn_Right(){
	Motor_RightSpeed(13,0);
	Motor_LeftSpeed(20,0);
}

void Turn_bLeft(){
	Motor_LeftSpeed(1,0);
	Motor_RightSpeed(13,0);
}
void Turn_bRight(){
	Motor_RightSpeed(1,0);
	Motor_LeftSpeed(13,0);
}

void Turn_bbLeft(){
	Motor_LeftSpeed(1,1);
	Motor_RightSpeed(16,0);
}
void Turn_bbRight(){
	Motor_RightSpeed(1,1);
	Motor_LeftSpeed(16,0);
}

void Car_stop(){
	Motor_LeftSpeed(1,1);
	Motor_RightSpeed(1,1);
}
void track_line(void)
{
    if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000)
    {
        Car_stop();
    }
    else if(Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]<=1000 &&Normal[5]<=1000 && Normal[6]<=1000) 
    {   
        if(flag_stop==1)
        {
            Car_stop(); 
            delay_cycles(40000000);
            flag_circle=-flag_circle;
            encoder_dis=0;
            L_Distance=0;
            R_Distance=0;
        }
        Go_Ahead();
        flag_stop=0;
    } 
    else if (encoder_dis<=900 && encoder_dis>=800)
        //(Normal[0]>1000 && Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            if(flag_circle==1)
            {
                 Turn_Left();
                delay_cycles(8000000); 
            }
            else
            {
                Go_Ahead();
                delay_cycles(20000000);
            }
        }
    else if(flag_judge==0)
    {   
        flag_stop=1;
        if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]<=1000 && Normal[4]<=1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000)
        {
            Go_Ahead();
        }
        // else if (Normal[0]<=1000 && Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        // {
        //     if(flag_circle==1)
        //     {
        //         Turn_Left();
        //         delay_cycles(20000000);
        //     }
        //     else
        //     {
        //         Go_Ahead();
        //         delay_cycles(20000000);
        //     }
        // }
        // else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]<=1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        // {
        //     if(flag_circle==1)
        //     {
        //          Turn_Left();
        //         delay_cycles(20000000); 
        //     }
        //     else
        //     {
        //         Go_Ahead();
        //         delay_cycles(20000000);
        //     }
        // }
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]<=1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            Turn_ssLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]<=1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000)
        {
            Turn_ssRight();
        } 
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            Turn_sLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]<=1000 &&Normal[5]<=1000 && Normal[6]>1000 && Normal[7]>1000)
        {
            Turn_sRight();
        }
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            flag_judge=1;
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]<=1000 && Normal[6]>1000 && Normal[7]>1000)
        {
            flag_judge=1;
        }
        else if (Normal[0]>1000 && Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>0 && Normal[7]>1000) 
        {
            //Turn_bbLeft();
            flag_judge=1;
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]<=1000 && Normal[6]<=1000 && Normal[7]>1000)
        {
            //Turn_bbRight();
            flag_judge=1;
        }
        else if ( Normal[1]<=1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            //Turn_bbLeft();
            flag_judge=1;
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>0 &&Normal[5]>1000 && Normal[6]<=1000)
        {
            //Turn_bbRight();
            flag_judge=1;
        }
    }
    else if(flag_judge==1)
    {
        flag_stop=1;
        if (Normal[0]>1000 && Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>0 && Normal[7]>1000) 
        {//01100000
            Turn_bLeft();
        }
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {//00100000
            Turn_bLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]<=1000 && Normal[6]>1000 && Normal[7]>1000)
        {//
            Turn_bRight();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]<=1000 && Normal[6]<=1000 && Normal[7]>1000)
        {
            Turn_bRight();
        }
        else if (Normal[0]<=1000 && Normal[1]<=1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {//11000000
            Turn_bbLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>0 &&Normal[5]>1000 && Normal[6]<=1000 && Normal[7]<=1000)
        {
            Turn_bbRight();
        }
        else if (Normal[0]<=1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {//10000000
            Turn_bbLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>0 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]<=1000)
        {
            Turn_bbRight();
        }        
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {   
            Car_stop();
            delay_cycles(100000);
            if (Normal[0]>1000 && Normal[1]>1000 && Normal[6]>1000 && Normal[7]>1000)
            {
                flag_judge=0;
            } 
        }
    }
    else 
    {
        Go_Ahead();
    }
}
#elif defined (first_car)
/*new car*/
#if defined(Judge_method)
void Go_Ahead(){
	Motor_LeftSpeed(25,0);
	Motor_RightSpeed(25,0);
}
void Go_Back(){
	Motor_LeftSpeed(20,1);
	Motor_RightSpeed(20,1);
}
void Turn_ssLeft(){
	Motor_LeftSpeed(22,0);
	Motor_RightSpeed(25,0);
}
void Turn_ssRight(){
	Motor_RightSpeed(22,0);
	Motor_LeftSpeed(25,0);
}
void Turn_sLeft(){
	Motor_LeftSpeed(18,0);
	Motor_RightSpeed(23,0);
}
void Turn_sRight(){
	Motor_RightSpeed(18,0);
	Motor_LeftSpeed(23,0);
}

void Turn_Left(){
	Motor_LeftSpeed(13,0);
	Motor_RightSpeed(20,0);
}
void Turn_Right(){
	Motor_RightSpeed(13,0);
	Motor_LeftSpeed(20,0);
}

void Turn_bLeft(){
	Motor_LeftSpeed(1,0);
	Motor_RightSpeed(18,0);
}
void Turn_bRight(){
	Motor_RightSpeed(1,0);
	Motor_LeftSpeed(18,0);
}

void Turn_bbLeft(){
	Motor_LeftSpeed(1,1);
	Motor_RightSpeed(20,0);
}
void Turn_bbRight(){
	Motor_RightSpeed(1,1);
	Motor_LeftSpeed(20,0);
}

void Car_stop(){
	Motor_LeftSpeed(1,1);
	Motor_RightSpeed(1,1);
}
void track_line(void)
{
    if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000)
    {
        Car_stop();
    }
    else if(Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]<=1000 &&Normal[5]<=1000 && Normal[6]<=1000) 
    {   
        if(flag_stop==1)
        {
            Car_stop(); 
            delay_cycles(40000000);
            flag_circle=-flag_circle;
            encoder_dis=0;
            L_Distance=0;
            R_Distance=0;
        }
        Go_Ahead();
        flag_stop=0;
    } 
    else if (encoder_dis<=900 && encoder_dis>=850)
    {
            if(flag_circle==1)
            {
                 Turn_Left();
                delay_cycles(8000000); 
            }
            else
            {
                Go_Ahead();
                delay_cycles(20000000);
            }
    }
    else if(flag_judge==0)
    {   
        flag_stop=1;
        if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]<=1000 && Normal[4]<=1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000)
        {
            Go_Ahead();
        }
        // else if (Normal[0]<=1000 && Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        // {
        //     if(flag_circle==1)
        //     {
        //         Turn_Left();
        //         delay_cycles(20000000);
        //     }
        //     else
        //     {
        //         Go_Ahead();
        //         delay_cycles(20000000);
        //     }
        // }
        // else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]<=1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        // {
        //     if(flag_circle==1)
        //     {
        //          Turn_Left();
        //         delay_cycles(20000000); 
        //     }
        //     else
        //     {
        //         Go_Ahead();
        //         delay_cycles(20000000);
        //     }
        // }
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]<=1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            Turn_ssLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]<=1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000)
        {
            Turn_ssRight();
        } 
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            Turn_sLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]<=1000 &&Normal[5]<=1000 && Normal[6]>1000 && Normal[7]>1000)
        {
            Turn_sRight();
        }
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            Turn_sLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]<=1000 && Normal[6]>1000 && Normal[7]>1000)
        {
            Turn_sRight();
        }
        else if (Normal[0]>1000 && Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>0 && Normal[7]>1000) 
        {
            //Turn_bbLeft();
            flag_judge=1;
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]<=1000 && Normal[6]<=1000 && Normal[7]>1000)
        {
            //Turn_bbRight();
            flag_judge=1;
        }
        else if ( Normal[1]<=1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            //Turn_bbLeft();
            flag_judge=1;
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>0 &&Normal[5]>1000 && Normal[6]<=1000)
        {
            //Turn_bbRight();
            flag_judge=1;
        }
    }
    else if(flag_judge==1)
    {
        flag_stop=1;
        if (Normal[0]>1000 && Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>0 && Normal[7]>1000) 
        {
            Turn_bLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]<=1000 && Normal[6]<=1000 && Normal[7]>1000)
        {
            Turn_bRight();
        }
        else if (Normal[0]<=1000 && Normal[1]<=1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            Turn_bbLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>0 &&Normal[5]>1000 && Normal[6]<=1000 && Normal[7]<=1000)
        {
            Turn_bbRight();
        }
        else if (Normal[0]<=1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            Turn_bbLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>0 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]<=1000)
        {
            Turn_bbRight();
        }        
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {
            flag_judge=0;
        }
    }
    else 
    {
        Go_Ahead();
    }
    
}
#elif defined (PID_method)
void Go_Ahead(){
	Motor_LeftSpeed(speed_MAX,forward);
	Motor_RightSpeed(speed_MAX,forward);
}
void Go_Back(){
	Motor_LeftSpeed(speed_MAX,backward);
	Motor_RightSpeed(speed_MAX,backward);
}

void Turn_ssLeft(){
	Motor_LeftSpeed(speed_MID,forward);
	Motor_RightSpeed(speed_MAX,forward);
}
void Turn_ssRight(){
	Motor_RightSpeed(speed_MID,forward);
	Motor_LeftSpeed(speed_MAX,forward);
}

void Turn_sLeft(){
	Motor_LeftSpeed(speed_MID,forward);
	Motor_RightSpeed(speed_MAX,forward);
}
void Turn_sRight(){
	Motor_RightSpeed(speed_MID,forward);
	Motor_LeftSpeed(speed_MAX,forward);
}

void Turn_Left(){
	Motor_LeftSpeed(speed_MICRO,forward);
	Motor_RightSpeed(speed_MAX,backward);
}
void Turn_Right(){
	Motor_RightSpeed(speed_MICRO,forward);
	Motor_LeftSpeed(speed_MAX,backward);
}

void Turn_bLeft(){
	Motor_LeftSpeed(speed_MIN,forward);
	Motor_RightSpeed(speed_MMAX,backward);
}
void Turn_bRight(){
	Motor_RightSpeed(speed_MIN,forward);
	Motor_LeftSpeed(speed_MMAX,backward);
}

void Turn_bbLeft(){
	Motor_LeftSpeed(speed_MIN,forward);
	Motor_RightSpeed(speed_MMAX,backward);
}
void Turn_bbRight(){
	Motor_RightSpeed(speed_MIN,forward);
	Motor_LeftSpeed(speed_MMAX,backward);
}

void Car_stop(){
	Motor_LeftSpeed(1,backward);
	Motor_RightSpeed(1,backward);
}
void track_line(void)//零没扫到，一扫到了,左正右负
{
	if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000)
    {
        Car_stop();//右00000000左
    }
    // else if(Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]<=1000 &&Normal[5]<=1000 && Normal[6]<=1000) 
    // {   
    //     if(flag_stop==1)
    //     {
    //         Car_stop(); 
    //         delay_cycles(40000000);
    //         flag_circle=-flag_circle;
    //         flag_getin = 1;
    //     }
    //     Go_Ahead();
    //     flag_stop=0;
    // } 
    else
    {   
        flag_stop=1;
        if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]<=1000 && Normal[4]<=1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000)
        {//右00011000左
           // Go_Ahead();
            angle_turn = 0;
        }
        // else if (flag_getin && Normal[0]>1000 && Normal[1]<=1000 && Normal[3]<=1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        // {//右01110000左和右01010000右进线
        //     flag_getin = 0;
        //     if(flag_circle==1)
        //     {
        //         Turn_bLeft();
        //         delay_cycles(20000000); 
        //     }
        //     else
        //     {
        //         Go_Ahead();
        //         delay_cycles(20000000);
        //     }
        // }
        // else if (flag_getin && Normal[0]<=1000 && Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        // {//右01100000右进线
        //     flag_getin = 0;
        //     if(flag_circle==1)
        //     {
        //         Turn_bLeft();
        //         delay_cycles(20000000);
        //     }
        //     else
        //     {
        //         Go_Ahead();
        //         delay_cycles(20000000);
        //     }
        // }
        // else if (flag_getin && Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]<=1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        // {//右00111000右进线
        //     flag_getin = 0;
        //     if(flag_circle==1)
        //     {
        //         Turn_bLeft();
        //         delay_cycles(20000000); 
        //     }
        //     else
        //     {
        //         Go_Ahead();
        //         delay_cycles(20000000);
        //     }
        // }
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]<=1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {//右00010000左
            angle_turn = -7;
            //Turn_ssLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]<=1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000)
        {   //右00001000左
            angle_turn = 7;
            //Turn_ssRight();
        } 
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]<=1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {   //右00110000左
            angle_turn = -15;
            //Turn_sLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]<=1000 &&Normal[5]<=1000 && Normal[6]>1000 && Normal[7]>1000)
        {   //右00001100左
            angle_turn = 15;
            //Turn_sRight();
        }
        else if (Normal[0]>1000 && Normal[1]>1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {   //右00100000左
            angle_turn = -20;
            //Turn_Left();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]<=1000 && Normal[6]>1000 && Normal[7]>1000)
        {   //右00000100左
            angle_turn = 20;
            //Turn_Right();
        }
        else if (Normal[0]>1000 && Normal[1]<=1000 && Normal[2]<=1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>0 && Normal[7]>1000) 
        {   //右01100000左
            angle_turn = -30;
            //Turn_bLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]<=1000 && Normal[6]<=1000 && Normal[7]>1000)
        {   //右00000110左
            angle_turn = 30;
            //Turn_bRight();
        }
        else if (Normal[0]>1000 && Normal[1]<=1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {   //右01000000左
            angle_turn = -32;
            //Turn_bLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>0 &&Normal[5]>1000 && Normal[6]<=1000 && Normal[7]>1000)
        {   //右00000010左
            angle_turn = 32;
            //Turn_bRight();
        }
                else if (Normal[0]<=1000 && Normal[1]<=1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {   //右11000000左
            angle_turn = -34;
            //Turn_bbLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>0 &&Normal[5]>1000 && Normal[6]<=1000 && Normal[7]<=1000)
        {   //右00000011左
            angle_turn = 34;
            //Turn_bbRight();
        }
                else if (Normal[0]<=1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>1000 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]>1000) 
        {   //右10000000左
            angle_turn = -35;
            //Turn_bbLeft();
        }
        else if(Normal[0]>1000 && Normal[1]>1000 && Normal[2]>1000 && Normal[3]>1000 && Normal[4]>0 &&Normal[5]>1000 && Normal[6]>1000 && Normal[7]<=1000)
        {   //右00000001左
            angle_turn = 35;
            //Turn_bbRight();
        }
        speed_Dilta_wu=Position_PID(0,angle_turn);
         load_limit_correct(speed_Base_wu-speed_Dilta_wu,speed_Base_wu+speed_Dilta_wu);
    }
}
#endif

#endif

/*pid输出装载*/
void load_limit_correct(int rate1,int rate2)
{
    volatile int direct1,direct2;
    /*取得方向和绝对值并限幅*/
    if(rate1>0)
    {
        direct1 = 1;  
    }
    else 
    {
        direct1 = 0;
        rate1 = -rate1;
    }
    if(rate1>40)
        rate1 = 40;
    // if(rate1<10)
    //     rate1 = 10;
    left_speed  =  (unsigned long int)(rate1+1);//避开电机0~1死区满转
    /*取得方向和绝对值并限幅*/
    if(rate2>0)
    {
        direct2 = 1;  
    }
    else 
    {
        direct2 = 0;
        rate2 = -rate2;
    }
    if(rate2>40)
        rate2 = 40;
    // if(rate2<10)
    //     rate2 = 10;
    right_speed  =  (unsigned long int)(rate2+1);//避开电机0~1死区满转
    Motor_LeftSpeed(left_speed,direct2);
    Motor_RightSpeed(right_speed,direct1);
}









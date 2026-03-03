#include <string.h>
#include "ti_msp_dl_config.h"
#include "main.h"
#include "stdio.h"
#include "car.h"
#include "pid.h"
#include "Blue_teeth.h"
#include "Grayscale_Sensor.h"
#include "servo.h"
 /*pid滤波*/
#define factorp 0.5
#define factori 0.0
#define factord 0.002
#define filter_factor 0.7

/*小车速度*/
#define SPEED_BASE 20
#define forward 0
#define backward 1
/*灰度*/
#define BLACK 600
#define WHITE 1000

uint8_t oled_buffer[32],SP_buffer[32];//oled
extern uint16_t RX_NUM;//蓝牙传来的值

volatile uint8_t gEchoData = 0;//串口收
extern char re_str[100];
extern char* stt;

extern int angle_turn;//蓝牙传出的值 偏向角PIDmethod
extern int Blue_teeth_Kp;//蓝牙接收的值
extern int left_speed,right_speed;//装载电机左右轮的速度

float  yaw_base = 0.0,yaw_exp = 0.0,yaw_bias = 31.0;//角度 speed_dita
pid_t* angle_pid;//角度pid,要开启MPU6050
float speed_exp = 0, speed_dita= 0;//速度pid
int pwm_left,pwm_right;//速度pid输出给电机
float expect_flag = 0,yaw_last = 100.0;//确定基准角
int routflag = 0;//FLAG
extern int flag_circle,flag_stop,flag_judge;//FLAG
int L_Distance,R_Distance,L_Encoder_speed,R_Encoder_speed,L_Distance_last,R_Distance_last,encoder_dis;//编码器速度和距离
uint8_t ch;//串口重定向
uint16_t disVal;//超声波距离distance value
/*八路灰度*/
unsigned short Anolog[8]={0};
//unsigned short white[8]={WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE};
//unsigned short black[8]={600,600,500,500,600,600,500,500};
unsigned short white[8]={WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE};
unsigned short black[8]={BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK};

unsigned short Normal[8];
int main(void)
{
    SysTick_Init();//滴答时钟
    NVIC_EnableIRQ(SysTick_IRQn);
    SYSCFG_DL_init();
    DL_TimerG_startCounter(PWM_0_INST);//电机速度PWM模块
    DL_TimerA_startCounter(servo_INST);//舵机PWM模块
    //MPU6050_Init();
    OLED_Init();//OLED屏幕
    //Ultrasonic_Init();//超声波模块
    //pid_init( angle_pid, DELTA_PID, factorp, factori, factord);//DELTA_PID、POSITION_PID可修改,pid模块初始化

    // NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);//UART串口
    // NVIC_EnableIRQ(UART_0_INST_INT_IRQN);

    //NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);//MPU6050INTB1口触发中断和编码电机中断PortB
    //NVIC_EnableIRQ(TIMER_Encoder_speed_INST_INT_IRQN);//定时器100ms触发Zero_event
    /*八路灰度初始化*/
    No_MCU_Sensor sensor;
	unsigned char Digtal;
    No_MCU_Ganv_Sensor_Init(&sensor,white,black);

    //OLED_ShowString(0,0,(uint8_t *)"base",8);
    // OLED_ShowString(0,2,(uint8_t *)"exp",8);
    // OLED_ShowString(0,4,(uint8_t *)"Yaw",8);
    // OLED_ShowString(0,6,(uint8_t *)"RF",8);、

        
       // DL_TimerA_setCaptureCompareValue(PWM_0_INST, 500, DL_TIMER_CC_0_INDEX);
    while (1) 
    {
        /*舵机角度设置*/
        Servo_SetUpAngle(20);
        Servo_SetDownAngle(180);
        /*循环八路灰度获取Anolog，Normal，Digital*/
         No_Mcu_Ganv_Sensor_Task_Without_tick(&sensor);
		 Digtal=Get_Digtal_For_User(&sensor);
		 Get_Anolog_Value(&sensor,Anolog);
		 Get_Normalize_For_User(&sensor,Normal);
         delay_cycles(80000);




        /*OLED打印值*/
         sprintf((char *)oled_buffer, "%d    ", Normal[0]);
         OLED_ShowString(15*6,0,oled_buffer,8);
         sprintf((char *)oled_buffer, "%d    ", Normal[1]);
         OLED_ShowString(15*6,1,oled_buffer,8);
         sprintf((char *)oled_buffer, "%d    ", Normal[2]);
         OLED_ShowString(15*6,2,oled_buffer,8);
         sprintf((char *)oled_buffer, "%d    ", Normal[3]);
         OLED_ShowString(15*6,3,oled_buffer,8);
         sprintf((char *)oled_buffer, "%d    ", Normal[4]);
         OLED_ShowString(15*6,4,oled_buffer,8);
         sprintf((char *)oled_buffer, "%d    ", Normal[5]);
         OLED_ShowString(15*6,5,oled_buffer,8);
         sprintf((char *)oled_buffer, "%d    ", Normal[6]);
         OLED_ShowString(15*6,6,oled_buffer,8);
         sprintf((char *)oled_buffer, "%d    ", Normal[7]);
         OLED_ShowString(15*6,7,oled_buffer,8);
         //sprintf((char *)oled_buffer, "%d  ", Blue_teeth_Kp);//显示蓝牙传的值
         //OLED_ShowString(3*6,0,oled_buffer,8);
        //  sprintf((char *)oled_buffer, "%d  ", L_Distance);
        //  OLED_ShowString(3*6,1,oled_buffer,8);
        //  sprintf((char *)oled_buffer, "%d  ", R_Distance);
        //  OLED_ShowString(3*6,2,oled_buffer,8);
        // sprintf((char *)oled_buffer, "%d  ", L_Encoder_speed);
        // OLED_ShowString(3*6,3,oled_buffer,8);
        // sprintf((char *)oled_buffer, "%d  ", R_Encoder_speed);
        // OLED_ShowString(3*6,4,oled_buffer,8);
        // sprintf((char *)oled_buffer, "%d  ", disVal);
        // OLED_ShowString(3*6,5,oled_buffer,8);

        /*等待解决MPU6050零漂问题*/
        // if((yaw-yaw_last)<0.001 && (yaw-yaw_last)>-0.001 && expect_flag <=1)
        // {
        //     yaw_base = yaw;
        //     expect_flag ++;
        // }
        // else if(expect_flag <=1) 
        // {
        //     yaw_last = yaw;
        // }


        /*超声波取值*/
        // disVal = Read_Ultrasonic();
        // sprintf((char*)oled_buffer,"%4u",disVal);
        // OLED_ShowString(6*8,0,oled_buffer,16);
        // delay_ms(100);
        
        /*小车巡线超声波防撞*/
        // if(Read_Ultrasonic()>=100 && Read_Ultrasonic()==0)
        // {
             track_line();
        // }
        // else
        // {
        //    Car_stop(); 
        // }

         encoder_dis =( L_Distance + R_Distance)/2;
        // track_line();//屏蔽untrasonic
        
        

        /*角度pid，循环赋值target和now*/
        // angle_pid->target = yaw_exp;
        // angle_pid->now = yaw;
        // pid_cal(angle_pid);
        // speed_dita = angle_pid->out;//speed_dita 土 SPEED_BASE作为速度PID的期望值

        /*速度pid*/
        // L_Encoder_speed = L_Distance - L_Distance_last;
        // pwm_left = Position_PID(L_Encoder_speed,speed_dita+SPEED_BASE);//pid的赋值在函数内
        // R_Encoder_speed = R_Distance - R_Distance_last;
        // pwm_right = Position_PID(R_Encoder_speed,SPEED_BASE-speed_dita);//pid的赋值在函数内
        // L_Distance_last = L_Distance;
        // R_Distance_last = R_Distance;

        /*装载速度pid输出*/
        // load_limit_correct(pwm_left, pwm_right);

    } 
}
/*打印*/
        // sprintf((char *)oled_buffer, "%d", routflag);
        // OLED_ShowString(5*8,6,oled_buffer,16);
        // sprintf((char *)oled_buffer, "%.1f", yaw_exp);
        // OLED_ShowString(5*8,2,oled_buffer,16);
        // sprintf((char *)oled_buffer, "%-6.1f", yaw);
        // OLED_ShowString(5*8,4,oled_buffer,16);
        // sprintf((char *)oled_buffer, "%-6.1f", yaw_base);
        // OLED_ShowString(5*8,0,oled_buffer,16);


/*串口重定向*/
// int fputc(int ch, FILE *f) 
// {
//     uint8_t c = (uint8_t)ch;
//     DL_UART_Main_transmitData(UART_0_INST,ch);   // 发送单个字符
//     while (DL_UART_isBusy(UART_0_INST));
//     return ch;
// }
// void TIMER_Encoder_speed_INST_IRQHandler(void)// 100ms定时器，发送蓝牙
// {
//     switch(DL_TimerG_getPendingInterrupt(TIMER_Encoder_speed_INST))
//     {
//         case DL_TIMER_IIDX_ZERO:
            // L_Encoder_speed = L_Distance-L_Distance_last;
            // R_Encoder_speed = R_Distance-R_Distance_last;
            // L_Distance_last = L_Distance;
            // R_Distance_last = R_Distance;
            // sprintf((char *)SP_buffer, "%d", encoder_dis);
            // printf("%s\r\n",SP_buffer);
            
//             break;
//         default:
//             break;
//     }
// }



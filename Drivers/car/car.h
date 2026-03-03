#ifndef  __CAR_H
#define  __CAR_H
/*转向函数、电机赋值函数*/
void Go_Ahead();
void Go_Back();
void Turn_ssLeft();
void Turn_ssRight();
void Turn_sLeft();
void Turn_sRight();
void Turn_Left();
void Turn_Right();
void Turn_bLeft();
void Turn_bRight();
void Turn_bbLeft();
void Turn_bbRight();
void Car_stop();
void Motor_LeftSpeed(unsigned long int speed,unsigned long int direct);
void Motor_RightSpeed(unsigned long int speed,unsigned long int direct);
void track_line(void);
void load_limit_correct(int rate1,int rate2);
#endif

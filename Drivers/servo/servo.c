#include "ti_msp_dl_config.h"

void Servo_SetUpAngle(float Angle)
{
	DL_TimerG_setCaptureCompareValue(servo_INST,Angle/180*2000+500,DL_TIMER_CC_0_INDEX);

}

void Servo_SetDownAngle(float Angle)
{
	DL_TimerG_setCaptureCompareValue(servo_INST,Angle/180*2000+500,DL_TIMER_CC_1_INDEX);
}

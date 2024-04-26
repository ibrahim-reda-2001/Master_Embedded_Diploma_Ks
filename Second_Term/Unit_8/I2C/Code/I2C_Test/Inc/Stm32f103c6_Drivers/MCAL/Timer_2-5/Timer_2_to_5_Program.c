#include "Timer_2_to_5_Interface.h"

void TIM2_voidInit(){
#if SELECTED_TIMER==TIMER2
TIMER_2->TIM_PSC|=PRESCALER-1;
TIMER_2->TIM_CCMR1_OC|=TIM2_CCMR1_PWM_MASK;
TIMER_2->TIM_CCMR2_OC|=TIM2_CCMR2_PWM_MASK;
TIMER_2->TIM_CR1|=TIM2_CR1_PWM_MASK;
TIMER_2->TIM_CCER|=TIM2_CCER_PWM_MASK;
TIMER_2->TIM_ARR=0xFFFF;//this auto reload value


#elif SELECTED_TIMER==TIMER3

#elif SELECTED_TIMER==TIMER4

#elif SELECTED_TIMER==TIMER5

#endif

}

void TIM2_voidStart(){
SET_BIT(TIMER_2->TIM_CR1,COUNTER_EN_BIT);
}

void TIM2_voidStop(){
	CLR_BIT(TIMER_2->TIM_CR1,COUNTER_DISABLE_BIT);

}

void TIM2_voidSetTimerValue(u16 value){
TIMER_2->TIM_CNT&=0x0000;
TIMER_2->TIM_CNT|=value;
}

u16 TIM2_u16GetTimerValue(){
return TIMER_2->TIM_CNT;
}

void TIM2_voidGeneratePwm(u8 channel, f32 dutyCycle){
	u16 compare_value =65336*(1-dutyCycle)-1;
	switch (channel){

	case PWM_CHANNEL_1 :TIMER_2->TIM_CCR1|=compare_value;  break;
	case PWM_CHANNEL_2 : TIMER_2->TIM_CCR2|=compare_value;  break;
	case PWM_CHANNEL_3 : TIMER_2->TIM_CCR3|=compare_value;  break;
	case PWM_CHANNEL_4 : TIMER_2->TIM_CCR4|=compare_value;  break;
	}

}

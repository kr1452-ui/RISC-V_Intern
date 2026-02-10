#include "ch32v00x.h"
#include "timer_driver.h"
#include "gpio_driver.h"

/*
 * PWM configuration:
 * Timer tick = 100 µs
 * PWM steps  = 100
 * PWM freq   = 100 Hz
 */

static volatile uint8_t pwm_counter = 0;

/* Clearly separated duty values (VERY IMPORTANT) */
static volatile uint8_t duty[3] = {20, 80, 0};   // LED2 dim, LED3 bright

void timer_init_100us(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseInitTypeDef timer;
    timer.TIM_Prescaler = 24 - 1;   // 24 MHz / 24 = 1 MHz
    timer.TIM_Period    = 100 - 1;  // 100 µs tick
    timer.TIM_CounterMode = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM2, &timer);

    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    NVIC_EnableIRQ(TIM2_IRQn);

    TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void) __attribute__((interrupt));
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        pwm_counter++;
        if (pwm_counter >= 100)
            pwm_counter = 0;

        /* LED on PD3 → LED index 2 */
        if (pwm_counter < duty[0])
            gpio_set_led(2);
        else
            gpio_clear_led(2);

        /* LED on PD4 → LED index 3 */
        if (pwm_counter < duty[1])
            gpio_set_led(3);
        else
            gpio_clear_led(3);

        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}

#include "inc/tm4c1294ncpdt.h"

// Function initializes I2C0
void I2C0_Init()
{
    SYSCTL_RCGCI2C_R|=(1<<0);

    SYSCTL_RCGCGPIO_R|=(1<<1);

    GPIO_PORTB_AHB_PUR_R|=(1<<2)|(1<<3);
    GPIO_PORTB_AHB_DEN_R|=(1<<2)|(1<<3);
    GPIO_PORTB_AHB_AFSEL_R|=(1<<2)|(1<<3);
    GPIO_PORTB_AHB_PCTL_R =0x2200;
    GPIO_PORTB_AHB_ODR_R|= (1<<3);
    I2C0_MTPR_R =7;
    I2C0_MCR_R = (1<<4);
}

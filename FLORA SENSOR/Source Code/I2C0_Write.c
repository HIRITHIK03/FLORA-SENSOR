#include "inc/tm4c1294ncpdt.h"

// Function writes data to Master data register
void I2C0_Write(char slave_address,char slave_memory_address,char data)
{
    I2C0_MSA_R=slave_address<<1;
    I2C0_MDR_R=(0x80|slave_memory_address);
    I2C0_MCS_R=3;
    while(I2C0_MCS_R&(0x01));
    while(I2C0_MCS_R&(0x02));
    I2C0_MDR_R=data;
    I2C0_MCS_R=5;
    while(I2C0_MCS_R&(0x01));
    while(I2C0_MCS_R&(0x02));
}

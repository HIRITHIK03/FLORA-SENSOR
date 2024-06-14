#include "inc/tm4c1294ncpdt.h"

//Function returns the Master received Data
char I2C0_Read(char slave_address,char slave_memory_address)
{
    char datab;

    I2C0_MSA_R = slave_address << 1;
    I2C0_MDR_R = (0x80|slave_memory_address);
    I2C0_MCS_R = 7;
    while(I2C0_MCS_R&(0x01));
    while(I2C0_MCS_R&(0x02));
    I2C0_MSA_R = ((slave_address << 1)+1);
    I2C0_MCS_R = 7;
    while(I2C0_MCS_R&(0x01));
    while(I2C0_MCS_R&(0x02));
    datab=I2C0_MDR_R ;

    return datab;
}

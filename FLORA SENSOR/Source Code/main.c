#include "inc/tm4c1294ncpdt.h"
#include <stdint.h>
#include "Delay.h"
#include "I2C0_Init.h"
#include "I2C0_Read.h"
#include "I2C0_Write.h"

// L --> LSB
// H --> MSB

 volatile  uint8_t Red_L;
 volatile  uint8_t Green_L;
 volatile  uint8_t Blue_L;
 volatile  uint16_t Red_H;
 volatile  uint16_t Green_H;
 volatile  uint16_t Blue_H;

int main()
{
    // Function initializes I2C0
    I2C0_Init();

    // Function writes data to Master data register
    I2C0_Write(0x29,0x00,0x03);

while(1) // Infinite Loop
{
  Red_L = I2C0_Read(0x29,0x16);
  Red_H = (I2C0_Read(0x29,0x17) << 8);
  Red_H = (Red_H + Red_L) / 128;

  Delay();

  Green_L = I2C0_Read(0x29,0x18);
  Green_H = (I2C0_Read(0x29,0x19) << 8);
  Green_H = (Green_H + Green_L) / 128;

  Delay();

  Blue_L = I2C0_Read(0x29,0x1A);
  Blue_H = (I2C0_Read(0x29,0x1B) << 8);
  Blue_H = (Blue_H + Blue_L) / 128;

  Delay();
}
}

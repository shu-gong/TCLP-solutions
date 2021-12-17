#include<stdio.h>
/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount. */

/*Answer: 
x            0X75     01110101     x has five 1-bits
x-1          0X74     01110100     flipping the last bit
x &= x-1     0X74     01110100     zeroing the last bit

x            0X74     01110100     x now has four 1-bits
x-1          0X73     01110011     flipping the three last bits
x &= x-1     0X70     01110000     zeroing the three last bits

x            0X70     01110000     x now has three 1-bits
x-1          0X6F     01101111     flipping the five last bits
x &= x-1     0X60     01100000     zeroing the five last bits

x            0X60     01100000     x now has two 1-bits
x-1          0X5F     01011111     flipping the six last bits
x &= x-1     0X40     01000000     zeroing the six last bits

x            0X40     01000000     x now has one 1-bit
x-1          0X3F     00111111     flipping the seven last bits
x &= x-1     0X00     00000000     zeroing the seven last bits

x            0X00     00000000     x now has zero 1-bit*/


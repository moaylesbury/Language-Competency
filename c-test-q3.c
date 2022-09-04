#include <stdio.h>
#include <string.h>
#include <stdlib.h>


uint32_t reverseBits(uint32_t n) {

    uint32_t reverse = 0;
    // reverse will be 0000.....0000
    // thus 0 bits do not need to be set, only 1
    // this function traverses n from left to right
    // if bit i in n is 1, then the corresponding (right to left) bit
    // bit (i-1) is flipped to a 1 in reverse
    uint32_t ith_bit;
    uint32_t one_bit = 1; // to prevent "runtime error: left shift of 1 by 31 places cannot be represented in type 'int'"
    int i = 0;


    while (i < 32){

        ith_bit = n >> i;
        // if bit is 1 then flip corresponding bit in reverse
        if (ith_bit & 1) reverse |= one_bit << (31 - i);

        i++;
    }

    return reverse;

}

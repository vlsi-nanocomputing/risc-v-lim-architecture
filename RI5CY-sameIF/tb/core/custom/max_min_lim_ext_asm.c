/*Max-Min research program*/
//Search max and min values in a user-defined vector of 10 elements

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{    
    /* variable declaration */
    int N = 10, zero = 0;
    int i;
    volatile int (*vector)[N];
    volatile int (*max);
    volatile int (*min);

    //define variable addresses
    vector = (volatile int(*)[N]) 0x030000, 
    max = (volatile int(*))0x3002C; 
    min= (volatile int(*))0x30030;

    //configuration address, where the config of the memory is stored.
    int cnfAddress = 0x1fffc;


    
    /* fill vector */
    for(i=0; i<N; i++){    
    	(*vector)[i] = i*13467;
    }

    //program LiM for max operation
    asm volatile("sw_active_max %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (cnfAddress), "[result]" (N)
    );

    /* MAX operation */

    //use sw to active sw_max (max searched in all vector elements)
    (*max) = (*vector)[0];

    //program LiM for min operation
    asm volatile("sw_active_min %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (cnfAddress), "[result]" (N)
    );

    /* MIN operation */
    //use sw to active sw_min (min searched in all vector elements)
    (*min) = (*vector)[0];

    //restore standard operations
    asm volatile("sw_active_none %[result], %[input_i], 0"
    : [result] "=r" (zero)
    : [input_i] "r" (cnfAddress), "[result]" (zero)
    );

  
       
    return EXIT_SUCCESS;
}


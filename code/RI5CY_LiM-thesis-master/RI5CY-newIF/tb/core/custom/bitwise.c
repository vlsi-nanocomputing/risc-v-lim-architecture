#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{    
    /* variable declaration */
    int N = 5, i, mask_or, mask_and, mask_xor;
    int *vector = 0x030000, *stand_alone = 0x30040, *final_result = 0x30080;

    /* fill vector */
    for(i=0; i<N; i++){    
    	vector[i] = i*13467;
    }
    *stand_alone = vector[1]+0x768;

    /* OR operation */
    mask_or = 0xF1;
    for(i=0; i<N; i++){
    	vector[i] = vector[i] | mask_or;
    }
    *stand_alone = *stand_alone | mask_or;

    /* AND operation */
    mask_and = vector[N-1] & 0x8F;
    for(i=0; i<N; i++){
    	vector[i] = vector[i] & mask_and;
    }
    *stand_alone = *stand_alone & mask_and;
  
    /* XOR operation */
    mask_xor = vector[N-2] ^ 0xF0;
    for(i=0; i<N; i++){
    	vector[i] = vector[i] ^ mask_xor;
    }
    *stand_alone = *stand_alone ^ mask_xor;

    *final_result = ~vector[N-3] + ~(*stand_alone);
     
    return EXIT_SUCCESS;
}


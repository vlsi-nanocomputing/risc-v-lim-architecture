/*Bitwise-inv custom program*/
//Compute different inverting bitwise logic operations on a user-defined vector 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{    

    int mask_nor, mask_nand, mask_xnor, N = 5, i, sum_a = 0x0, sum_b = 0x0;
    volatile int (*vector)[N];
    volatile int (*stand_alone);
    volatile int (*final_result);
	
    //define variables' addresses
    vector = (volatile int(*)[N]) 0x030000, 
    stand_alone = (volatile int(*))0x30040, 
    final_result= (volatile int(*))0x30044;

    register unsigned int x0 asm("x0");

    //configuration address, where the config of the memory is stored.
    int cnfAddress = 0x1fffc;
	//configure vector[N-1] address
	int andAddress = 0x030010;
	//configure vector[N-2] address
	int xorAddress  = 0x03000C;
    //configure vector[N-3] address
	int opAddress  = 0x30008;

    //initialize mask values
    mask_nand  = 0x8F;
    mask_nor   = 0xF1;
    mask_xnor  = 0xF0;

	
	
    /* fill vector */
    for(i=0; i<N; i++){    
    	(*vector)[i] = i*13467;
    }

    (*stand_alone) = (*vector)[1]+0x768;

	
	
	

    /* NOR operation */

    //program LiM for range operation
    asm volatile("sw_active_nor %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (cnfAddress), "[result]" (N)
    );
	
    //sw operation to active NOR LiM
    (*vector)[0] = mask_nor;

    //program LiM for stand-alone operation
    asm volatile("sw_active_nor %[result], %[input_i], 0"
    : [result] "=r" (x0)
    : [input_i] "r" (cnfAddress), "[result]" (x0)
    );

    (*stand_alone) = mask_nor;

    /* NAND operation */


    //program LiM for stand-alone operation
    asm volatile("sw_active_nand %[result], %[input_i], 0"
    : [result] "=r" (x0)
    : [input_i] "r" (cnfAddress), "[result]" (x0)
    );
	

    //lw_mask operation for mask_nand computation
    asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
    : [result] "=r" (mask_nand)
    : [input_s] "r" (andAddress), [input_t] "r"  (mask_nand), "[result]" (mask_nand)
    );

    //program LiM for range operation
    asm volatile("sw_active_nand %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (cnfAddress), "[result]" (N)
    );
    
    //sw operation to active NAND LiM
    (*vector)[0] = mask_nand;

    //program LiM for stand-alone operation
    asm volatile("sw_active_nand %[result], %[input_i], 0"
    : [result] "=r" (x0)
    : [input_i] "r" (cnfAddress), "[result]" (x0)
    );
	
    (*stand_alone) = mask_nand;


    /* XNOR operation*/

    //program LiM for stand-alone operation
    asm volatile("sw_active_xnor %[result], %[input_i], 0"
    : [result] "=r" (x0)
    : [input_i] "r" (cnfAddress), "[result]" (x0)
    );


    //lw_mask operation for mask_xnor computation
    asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
    : [result] "=r" (mask_xnor)
    : [input_s] "r" (xorAddress), [input_t] "r"  (mask_xnor), "[result]" (mask_xnor)
    );


    //program LiM for range operation
    asm volatile("sw_active_xnor %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (cnfAddress), "[result]" (N)
    );
	
    (*vector)[0] = mask_xnor;

    //program LiM for stand-alone operation
    asm volatile("sw_active_xnor %[result], %[input_i], 0"
    : [result] "=r" (x0)
    : [input_i] "r" (cnfAddress), "[result]" (x0)
    );
	
    (*stand_alone) = mask_xnor;


    //lw_mask operation for ~(*vector)[N-3] computation exploting xnor
    asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
    : [result] "=r" (sum_a)
    : [input_s] "r" (opAddress), [input_t] "r"  (sum_a), "[result]" (sum_a)
    );

    //lw_mask operation for ~(*stand_alone) computation exploting xnor
    asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
    : [result] "=r" (sum_b)
    : [input_s] "r" (&(*stand_alone)), [input_t] "r"  (sum_b), "[result]" (sum_b)
    );


    //restore standard operations
    asm volatile("sw_active_none %[result], %[input_i], 0"
    : [result] "=r" (x0)
    : [input_i] "r" (cnfAddress), "[result]" (x0)
    );

    (*final_result) = sum_a + sum_b;
	


    return EXIT_SUCCESS;
}


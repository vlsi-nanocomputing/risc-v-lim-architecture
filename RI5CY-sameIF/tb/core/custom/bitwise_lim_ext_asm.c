#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{    

	int mask_or, mask_and, mask_xor, s_alone = 1, zero = 0, N = 5, i, sum_a = 0xFFFFFFFF, sum_b = 0xFFFFFFFF;
	volatile int (*vector)[N];
	volatile int (*stand_alone);
	volatile int (*final_result);
	
	//define variables' addresses
	vector = (volatile int(*)[N]) 0x030000, 
	stand_alone = (volatile int(*))0x30040, 
	final_result= (volatile int(*))0x30044;

	//configuration address, where the config of the memory is stored = 0x1fffc
	//configure vector[N-1] address = 0x030010
	//configure vector[N-2] address = 0x03000C
    //configure vector[N-3] address = 0x30008
    

	//initialize mask values
	mask_and  = 0x8F;
	mask_or   = 0xF1;
	mask_xor  = 0xF0;
   

	
	
	/* fill vector */
    for(i=0; i<N; i++){    
    	(*vector)[i] = i*13467;
    }

	(*stand_alone) = (*vector)[1]+0x768;

	
	
	

	/* OR operation */

	//program LiM for range operation
	asm volatile("sw_active_or %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (0x1fffc), "[result]" (N)
    );
	
	//sw operation to active OR LiM
	(*vector)[0] = mask_or;

	//program LiM for stand-alone operation
	asm volatile("sw_active_or %[result], %[input_i], 0"
    : [result] "=r" (s_alone)
    : [input_i] "r" (0x1fffc), "[result]" (s_alone)
    );
	(*stand_alone) = mask_or;

	/* AND operation */


	//program LiM for stand-alone operation
	asm volatile("sw_active_and %[result], %[input_i], 0"
    : [result] "=r" (s_alone)
    : [input_i] "r" (0x1fffc), "[result]" (s_alone)
    );
	

	//lw_mask operation for mask_and computation
	asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	: [result] "=r" (mask_and)
	: [input_s] "r" (0x030010), [input_t] "r"  (mask_and), "[result]" (mask_and)
	);

	//program LiM for range operation
	asm volatile("sw_active_and %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (0x1fffc), "[result]" (N)
    );
	//sw operation to active AND LiM
	(*vector)[0] = mask_and;

	//program LiM for stand-alone operation
	asm volatile("sw_active_and %[result], %[input_i], 0"
    : [result] "=r" (s_alone)
    : [input_i] "r" (0x1fffc), "[result]" (s_alone)
    );
	(*stand_alone) = mask_and;


	/* XOR operation*/

	//program LiM for stand-alone operation
	asm volatile("sw_active_xor %[result], %[input_i], 0"
    : [result] "=r" (s_alone)
    : [input_i] "r" (0x1fffc), "[result]" (s_alone)
    );


	//lw_mask operation for mask_xor computation
	asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	: [result] "=r" (mask_xor)
	: [input_s] "r" (0x03000C), [input_t] "r"  (mask_xor), "[result]" (mask_xor)
	);


	//program LiM for range operation
	asm volatile("sw_active_xor %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (0x1fffc), "[result]" (N)
    );
	(*vector)[0] = mask_xor;

	//program LiM for stand-alone operation
	asm volatile("sw_active_xor %[result], %[input_i], 0"
    : [result] "=r" (s_alone)
    : [input_i] "r" (0x1fffc), "[result]" (s_alone)
    );
	(*stand_alone) = mask_xor;

    //lw_mask operation for ~(*vector)[N-3] computation exploting xor
	asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	: [result] "=r" (sum_a)
	: [input_s] "r" (0x30008), [input_t] "r"  (sum_a), "[result]" (sum_a)
	);

    //lw_mask operation for ~(*stand_alone) computation exploting xor
	asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	: [result] "=r" (sum_b)
	: [input_s] "r" (0x30040), [input_t] "r"  (sum_b), "[result]" (sum_b)
	);


	//restore standard operations
	asm volatile("sw_active_none %[result], %[input_i], 0"
    : [result] "=r" (zero)
    : [input_i] "r" (0x1fffc), "[result]" (zero)
    );

	(*final_result) = sum_a + sum_b;


    return EXIT_SUCCESS;
}


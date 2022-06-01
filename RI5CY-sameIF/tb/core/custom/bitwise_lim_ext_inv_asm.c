#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{    

	int mask_nor, mask_nand, mask_xnor, s_alone = 1, zero = 0, N = 5, i, dummyvar;
	volatile int (*vector)[N];
	volatile int (*stand_alone);
	volatile int (*final_result);
	
	vector = (volatile int(*)[N]) 0x030000, 
	stand_alone = (volatile int(*))0x30040, 
	final_result= (volatile int(*))0x30044;

	//configuration address, where the config of the memory is stored.
    int cnfAddress = 0x1fffc;
	//configure vector[N-1] address
	int nandAddress = 0x030010;
	//configure vector[N-2] address
	int xnorAddress  = 0x03000C;

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
    : [result] "=r" (s_alone)
    : [input_i] "r" (cnfAddress), "[result]" (s_alone)
    );
	(*stand_alone) = mask_nor;

	/* NAND operation */


	//program LiM for stand-alone operation
	asm volatile("sw_active_nand %[result], %[input_i], 0"
    : [result] "=r" (s_alone)
    : [input_i] "r" (cnfAddress), "[result]" (s_alone)
    );
	

	//lw_mask operation for mask_nand computation
	asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	: [result] "=r" (mask_nand)
	: [input_s] "r" (nandAddress), [input_t] "r"  (mask_nand), "[result]" (mask_nand)
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
    : [result] "=r" (s_alone)
    : [input_i] "r" (cnfAddress), "[result]" (s_alone)
    );
	(*stand_alone) = mask_nand;


	/* XNOR operation*/

	//program LiM for stand-alone operation
	asm volatile("sw_active_xnor %[result], %[input_i], 0"
    : [result] "=r" (s_alone)
    : [input_i] "r" (cnfAddress), "[result]" (s_alone)
    );


	//lw_mask operation for mask_xnor computation
	asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	: [result] "=r" (mask_xnor)
	: [input_s] "r" (xnorAddress), [input_t] "r"  (mask_xnor), "[result]" (mask_xnor)
	);


	//program LiM for range operation
	asm volatile("sw_active_xnor %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (cnfAddress), "[result]" (N)
    );
	(*vector)[0] = mask_xnor;

	//program LiM for stand-alone operation
	asm volatile("sw_active_xnor %[result], %[input_i], 0"
    : [result] "=r" (s_alone)
    : [input_i] "r" (cnfAddress), "[result]" (s_alone)
    );
	(*stand_alone) = mask_xnor;


	//restore standard operations
	asm volatile("sw_active_none %[result], %[input_i], 0"
    : [result] "=r" (zero)
    : [input_i] "r" (cnfAddress), "[result]" (zero)
    );

	(*final_result) = ~(*vector)[N-3] + ~(*stand_alone);

	


    return EXIT_SUCCESS;
}


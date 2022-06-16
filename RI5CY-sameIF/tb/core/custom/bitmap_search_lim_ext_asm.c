#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    /* variable declaration */
    int i, N=1, mask=0, partial, res, operand, target16 = 0x30000, target17 = 0x30018, target19 = 0x30048, target20 = 0x30060, target_v_gender = 0x30078, zero = 0; 
    int Nr = 7; //number of rows
    volatile int (*result_M_over19)[Nr];
    volatile int (*result_over18)[Nr];
    volatile int (*v_age16)[Nr];
    volatile int (*v_age17)[Nr];
    volatile int (*v_age18)[Nr];
    volatile int (*v_age19)[Nr];
    volatile int (*v_age20)[Nr];
    volatile int (*v_genderM)[Nr];
    volatile int (*v_genderF)[Nr];
    
    
    /* Initialize bitmap */

    result_M_over19 = (volatile int(*)[Nr]) 0x300B0;
    result_over18   = (volatile int(*)[Nr]) 0x300D0;
    v_age16         = (volatile int(*)[Nr]) 0x30000;
    v_age17         = (volatile int(*)[Nr]) 0x30018;
    v_age18         = (volatile int(*)[Nr]) 0x30030;
    v_age19         = (volatile int(*)[Nr]) 0x30048;
    v_age20         = (volatile int(*)[Nr]) 0x30060;
    v_genderM       = (volatile int(*)[Nr]) 0x30078;
    v_genderF       = (volatile int(*)[Nr]) 0x30090;
  
    (*v_genderM)[0]=0x00000000; (*v_genderM)[1]=0x00000000; (*v_genderM)[2]=0x00000000; (*v_genderM)[3]=0xFFFFFFFF; (*v_genderM)[4]=0xFFFFFFFF; (*v_genderM)[5]=0xFFFFFFFF;
    (*v_genderF)[0]=0xFFFFFFFF; (*v_genderF)[1]=0xFFFFFFFF; (*v_genderF)[2]=0xFFFFFFFF; (*v_genderF)[3]=0x00000000; (*v_genderF)[4]=0x00000000; (*v_genderF)[5]=0x00000000;
    (*v_age16)[0]  =0x00000000; (*v_age16)[1]  =0x00000000; (*v_age16)[2]  =0x0000FFFF; (*v_age16)[3]  =0x00000000; (*v_age16)[4]  =0x00000000; (*v_age16)[5]  =0x0000FFFF;
    (*v_age17)[0]  =0x00000000; (*v_age17)[1]  =0x00000000; (*v_age17)[2]  =0xFFFF0000; (*v_age17)[3]  =0x00000000; (*v_age17)[4]  =0x00000000; (*v_age17)[5]  =0xFFFF0000;
    (*v_age18)[0]  =0x00000000; (*v_age18)[1]  =0x0000FFFF; (*v_age18)[2]  =0x00000000; (*v_age18)[3]  =0x00000000; (*v_age18)[4]  =0x0000FFFF; (*v_age18)[5]  =0x00000000;
    (*v_age19)[0]  =0x00000000; (*v_age19)[1]  =0xFFFF0000; (*v_age19)[2]  =0x00000000; (*v_age19)[3]  =0x00000000; (*v_age19)[4]  =0xFFFF0000; (*v_age19)[5]  =0x00000000;
    (*v_age20)[0]  =0xFFFFFFFF; (*v_age20)[1]  =0x00000000; (*v_age20)[2]  =0x00000000; (*v_age20)[3]  =0xFFFFFFFF; (*v_age20)[4]  =0x00000000; (*v_age20)[5]  =0x00000000;

    /* Initialise results to 0 */
    for(i=0; i<Nr-1; i++) {
        (*result_M_over19)[i] = 0;
        (*result_over18)[i]   = 0;
    }


    /* Query: identify male people that are 19 or 20 */

	//program LiM for stand-alone OR operation
	asm volatile("sw_active_or %[result], %[input_i], 0"
    : [result] "=r" (N)
    : [input_i] "r" (0x1fffc), "[result]" (N)
    );

    for(i=0; i<Nr-1; i++) {

        partial = 0x00000000; //initialize variable for standard lw
        operand = 0x00000000; //initialize variable for standard lw
        
        //lw_mask operation for OR computation
	    asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	    : [result] "=r" (partial)
	    : [input_s] "r" (target20), [input_t] "r"  (partial), "[result]" (partial)
	    );
        
        //lw_mask operation for OR computation
	    asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	    : [result] "=r" (partial)
	    : [input_s] "r" (target19), [input_t] "r"  (partial), "[result]" (partial)
	    );

        //lw_mask operation for lw 
	    asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	    : [result] "=r" (operand)
	    : [input_s] "r" (target_v_gender), [input_t] "r"  (operand), "[result]" (operand)
	    );
        
        res = operand & partial; 

        //sw operation to store results
	    (*result_M_over19)[i] = res;

        target20 = target20 + 0x00000004;  //update address
        target19 = target19 + 0x00000004;  //update address
        target_v_gender = target_v_gender + 0x00000004;  //update address
        

    }

    /* Query: identify people that are older than 18 */

   for(i=0; i<Nr-1; i++) {

        partial = 0x00000000; //initialize variable for standard lw

        //lw first operand
	    asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	    : [result] "=r" (partial)
	    : [input_s] "r" (target17), [input_t] "r"  (partial), "[result]" (partial)
	    );

       //lw_mask operation for OR computation
	    asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
	    : [result] "=r" (partial)
	    : [input_s] "r" (target16), [input_t] "r"  (partial), "[result]" (partial)
	    );

       //NOT operation
       res = ~ partial;

       //sw operation to store results
	   (*result_over18)[i] = res;

       target16 = target16 + 0x00000004;  //update address
       target17 = target17 + 0x00000004;  //update address

   }
 

   //restore standard operations
	asm volatile("sw_active_none %[result], %[input_i], 0"
    : [result] "=r" (zero)
    : [input_i] "r" (0x1fffc), "[result]" (zero)
    );


    return EXIT_SUCCESS;
}


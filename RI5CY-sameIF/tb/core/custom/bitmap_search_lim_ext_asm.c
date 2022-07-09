/* Bitmap search program*/
//This program emulates the bitmap search algorithm, students' features are distributed over 6 integer vectors.
//In this program two queries are perfomed
// 1. Which students are male and older than 19?
// 2. Which students are older than 18?

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    /* variable declaration */
    int i, N=0, mask=0, partial, res, operand; 
    int Nr = 7; //number of rows
    volatile int (*result_M_over19)[Nr];    //declare memory variables as volatile int
    volatile int (*result_over18)[Nr];
    volatile int (*v_age16)[Nr];
    volatile int (*v_age17)[Nr];
    volatile int (*v_age18)[Nr];
    volatile int (*v_age19)[Nr];
    volatile int (*v_age20)[Nr];
    volatile int (*v_genderM)[Nr];
    volatile int (*v_genderF)[Nr];

    register unsigned int x0 asm("x0");
    
    //Define variable addresses
    result_M_over19 = (volatile int(*)[Nr]) 0x300B0;
    result_over18   = (volatile int(*)[Nr]) 0x300D0;
    v_age16         = (volatile int(*)[Nr]) 0x30000;
    v_age17         = (volatile int(*)[Nr]) 0x30018;
    v_age18         = (volatile int(*)[Nr]) 0x30030;
    v_age19         = (volatile int(*)[Nr]) 0x30048;
    v_age20         = (volatile int(*)[Nr]) 0x30060;
    v_genderM       = (volatile int(*)[Nr]) 0x30078;
    v_genderF       = (volatile int(*)[Nr]) 0x30090;
  
    /* Initialize bitmap */
    (*v_genderM)[0]=0x00000000; (*v_genderM)[1]=0x00000000; (*v_genderM)[2]=0x00000000; (*v_genderM)[3]=0xFFFFFFFF; (*v_genderM)[4]=0xFFFFFFFF; (*v_genderM)[5]=0xFFFFFFFF;
    (*v_genderF)[0]=0xFFFFFFFF; (*v_genderF)[1]=0xFFFFFFFF; (*v_genderF)[2]=0xFFFFFFFF; (*v_genderF)[3]=0x00000000; (*v_genderF)[4]=0x00000000; (*v_genderF)[5]=0x00000000;
    (*v_age16)[0]  =0x00000000; (*v_age16)[1]  =0x00000000; (*v_age16)[2]  =0x0000FFFF; (*v_age16)[3]  =0x00000000; (*v_age16)[4]  =0x00000000; (*v_age16)[5]  =0x0000FFFF;
    (*v_age17)[0]  =0x00000000; (*v_age17)[1]  =0x00000000; (*v_age17)[2]  =0xFFFF0000; (*v_age17)[3]  =0x00000000; (*v_age17)[4]  =0x00000000; (*v_age17)[5]  =0xFFFF0000;
    (*v_age18)[0]  =0x00000000; (*v_age18)[1]  =0x0000FFFF; (*v_age18)[2]  =0x00000000; (*v_age18)[3]  =0x00000000; (*v_age18)[4]  =0x0000FFFF; (*v_age18)[5]  =0x00000000;
    (*v_age19)[0]  =0x00000000; (*v_age19)[1]  =0xFFFF0000; (*v_age19)[2]  =0x00000000; (*v_age19)[3]  =0x00000000; (*v_age19)[4]  =0xFFFF0000; (*v_age19)[5]  =0x00000000;
    (*v_age20)[0]  =0xFFFFFFFF; (*v_age20)[1]  =0x00000000; (*v_age20)[2]  =0x00000000; (*v_age20)[3]  =0xFFFFFFFF; (*v_age20)[4]  =0x00000000; (*v_age20)[5]  =0x00000000;

    // Initialize results to 0 (useful for neutral lw_or operation)
    for(i=0; i<Nr-1; i++) {
        (*result_M_over19)[i] = 0;
        (*result_over18)[i]   = 0;
    }

    //program LiM for stand-alone OR operation
    asm volatile("sw_active_or %[result], %[input_i], 0"
    : [result] "=r" (x0)
    : [input_i] "r" (0x1fffc), "[result]" (N)
    );

    /* Query: identify male people that are 19 or 20 */
    for(i=0; i<Nr-1; i++) {

        //load first operand with neutral load
        asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
        : [result] "=r" (partial)
        : [input_s] "r" (&(*v_age20)[i]), [input_t] "r"  (x0), "[result]" (partial)
        );

        //lw_mask operation for OR computation, use previous operand as mask (equivalent to v_age19[i] | v_age20[i])
        asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
        : [result] "=r" (partial)
        : [input_s] "r" (&(*v_age19)[i]), [input_t] "r"  (partial), "[result]" (partial)
        );

        //load last operand with neutral load
        asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
        : [result] "=r" (operand)
        : [input_s] "r" (&(*v_genderM)[i]), [input_t] "r"  (x0), "[result]" (operand)
        );
        res = operand & partial; //compute AND operation inside the core

        //sw operation to store results (neutral store)
        (*result_M_over19)[i] = res;
    }

    /* Query: identify people that are older than 18 */
   for(i=0; i<Nr-1; i++) {

        //lload first operand with neutral load
        asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
        : [result] "=r" (partial)
        : [input_s] "r" (&(*v_age17)[i]), [input_t] "r"  (x0), "[result]" (partial)
        );

        //lw_mask operation for OR computation, use previous operand as mask (equivalent to v_age17[i] | v_age16[i])
        asm volatile("lw_mask %[result], %[input_s], %[input_t], 0 "
        : [result] "=r" (partial)
        : [input_s] "r" (&(*v_age16)[i]), [input_t] "r"  (partial), "[result]" (partial)
        );
        res = ~ partial; //compute AND operation inside the core
        
       //sw operation to store results (neutral store)
	   (*result_over18)[i] = res;
   }
 

    //restore standard operations
    asm volatile("sw_active_none %[result], %[input_i], 0"
    : [result] "=r" (x0)
    : [input_i] "r" (0x1fffc), "[result]" (x0)
    );


    return EXIT_SUCCESS;
}


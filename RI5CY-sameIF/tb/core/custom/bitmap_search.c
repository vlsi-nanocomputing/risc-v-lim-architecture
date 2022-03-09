#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    /* variable declaration */
    int i; 
    int *result_M_over19=0x300B0;
    int *result_over18  =0x300D0;
    
    /* Initialize bitmap */
    int *v_age16   = 0x30000;
    int *v_age17   = 0x30018;
    int *v_age18   = 0x30030;
    int *v_age19   = 0x30048;
    int *v_age20   = 0x30060;
    int *v_genderM = 0x30078;
    int *v_genderF = 0x30090;

    v_genderM[0]=0x00000000; v_genderM[1]=0x00000000; v_genderM[2]=0x00000000; v_genderM[3]=0xFFFFFFFF; v_genderM[4]=0xFFFFFFFF; v_genderM[5]=0xFFFFFFFF;
    v_genderF[0]=0xFFFFFFFF; v_genderF[1]=0xFFFFFFFF; v_genderF[2]=0xFFFFFFFF; v_genderF[3]=0x00000000; v_genderF[4]=0x00000000; v_genderF[5]=0x00000000;
    v_age16[0]  =0x00000000; v_age16[1]  =0x00000000; v_age16[2]  =0x0000FFFF; v_age16[3]  =0x00000000; v_age16[4]  =0x00000000; v_age16[5]  =0x0000FFFF;
    v_age17[0]  =0x00000000; v_age17[1]  =0x00000000; v_age17[2]  =0xFFFF0000; v_age17[3]  =0x00000000; v_age17[4]  =0x00000000; v_age17[5]  =0xFFFF0000;
    v_age18[0]  =0x00000000; v_age18[1]  =0x0000FFFF; v_age18[2]  =0x00000000; v_age18[3]  =0x00000000; v_age18[4]  =0x0000FFFF; v_age18[5]  =0x00000000;
    v_age19[0]  =0x00000000; v_age19[1]  =0xFFFF0000; v_age19[2]  =0x00000000; v_age19[3]  =0x00000000; v_age19[4]  =0xFFFF0000; v_age19[5]  =0x00000000;
    v_age20[0]  =0xFFFFFFFF; v_age20[1]  =0x00000000; v_age20[2]  =0x00000000; v_age20[3]  =0xFFFFFFFF; v_age20[4]  =0x00000000; v_age20[5]  =0x00000000;

    /* Initialise results to 0 */
    for(i=0; i<6; i++) {
        result_M_over19[i] = 0;
        result_over18[i]   = 0;
    }

    /* Query: identify male people that are 19 or 20 */
    for(i=0; i<6; i++) {
        result_M_over19[i] = v_genderM[i] & (v_age19[i] | v_age20[i]);
    }

    /* Query: identify people that are older than 18 */
    for(i=0; i<6; i++) {
        result_over18[i] = ~v_age16[i] & ~v_age17[i] ;
    }

    return EXIT_SUCCESS;
}


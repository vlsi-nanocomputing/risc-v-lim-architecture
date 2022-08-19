/*CUSTOM PROGRAM*/
//Test built-in logic functions (NAND-NOR-XNOR)



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{    
    /* variable declaration */
    int N = 5, i, mask_nor, mask_nand, mask_xnor;  //define useful variables
    int *vector = 0x030000, *stand_alone = 0x30040, *final_result = 0x30080;    //define memory addresses

    /* fill vector */
    for(i=0; i<N; i++){    
    	vector[i] = i*13467;
    }
    //initialize stand alone value
    *stand_alone = vector[1]+0x768;

    /* NOR operation */
    mask_nor = 0xF1; //NOR mask definition
    for(i=0; i<N; i++){
    	vector[i] = ~(vector[i] | mask_nor);    //compute NOR operation on each vector element
    }
    *stand_alone = ~(*stand_alone | mask_nor);  //compute NOR on stand alone element

    /* NAND operation */
    mask_nand = ~(vector[N-1] & 0x8F);   //NAND mask computation
    for(i=0; i<N; i++){
    	vector[i] = ~(vector[i] & mask_nand);    //compute NAND on each vector element
    }
    *stand_alone = ~(*stand_alone & mask_nand);  //compute NAND on stand alone element
  
    /* XNOR operation */
    mask_xnor = ~(vector[N-2] ^ 0xF0);   //XNOR mask computation
    for(i=0; i<N; i++){
    	vector[i] = ~(vector[i] ^ mask_xnor);    //compute XNOR on each vector element
    }
    *stand_alone = ~(*stand_alone ^ mask_xnor);  //compute XNOR on stand alone element

    *final_result = ~vector[N-3] + ~(*stand_alone); //compute final result
     
    return EXIT_SUCCESS;
}


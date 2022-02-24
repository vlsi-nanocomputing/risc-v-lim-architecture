#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{    
    /* variable declaration */
    int N = 10;
    int i;
    int *vector = 0x30000;
    int *max = 0x300F0;
    int *min = 0x300F4;
    
    /* fill vector */
    for(i=0; i<N; i++){    
    	vector[i] = i*13467;
    }

    /* MAX operation */
    *max = vector[0];

    for(i=1; i<N; i++){
    	if(vector[i]>*max){
		*max = vector[i];
        }    	
    }

   /* MIN operation */
    *min = vector[0];

    for(i=1; i<N; i++){
    	if(vector[i]<*min){
		*min = vector[i];
        }    	
    }
       
    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 28
#define W_F 2

int sign_function(int x)
{
    if(x > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int main()
{
    // //initialize srand function
    // srand(time(NULL));
    //weight matrix
    volatile int (*weight)[W_F][W_F];
    //image matrix
    volatile int (*image)[N][N];
    //store location
    weight =  (volatile int(*)[W_F][W_F]) 0x3000;
    image =  (volatile int(*)[N][N]) 0x30800;
    //the of-map is stored from 0x20000 address and so on.
    volatile int (*ofmap)[N][N];
    ofmap = (volatile int(*)[N][N]) 0x20000;
    int zero = 0;
    //configuration address, where the config of the memory is stored.
    int cnfAddress = 0x1fffc;

    //indexes definition.
    int i,j,c,m,t;

    for(i = 0; i < W_F; i++)
    {
        for(j = 0; j < W_F; j++)
        {
            (*weight)[i][j] = sign_function(0);
        }
    }
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            (*image)[i][j] = sign_function(0);
            (*ofmap)[i][j] = 0;
        }
    }

    //number of channels
    int n_channels = 1;
    //stride
    int stride = 1;
    //size of the kernel
    int wf = W_F;
    //dimension of the output
    int w_out = (N-wf)/stride + 1;
    //dimension squared of the output
    int w_out2 = w_out*w_out + 1;
    //index A and B
    int A = 0;
    int B = 0;
    //flag indicating if the weight has been already binarized or not.
    int flag = 0;
    //binarized weight
    unsigned int bWeight = 0;
    //counting zeros
    int countZeros;
    for(c = 0; c < n_channels; c++)
    {
        for(j = 0; j < w_out; j++)
        {
            for(i = 0; i < w_out; i++)
            {
                for(m = 0; m < wf; m++)
                {
                    for(t = 0; t < wf; t++)
                    {
                        A = j+m+j*(stride-1);
                        B = i+t+i*(stride-1);
                        (*ofmap)[j][i] = ((*image)[A][B]) | ((*ofmap)[j][i] << 1);
                        if (flag == 0) 
                        {
                            bWeight = ( (*weight)[m][t] ) | (bWeight << 1);
                        }
                    }
                }
                flag = 1;
            }
        }
        //activate the xor operation on W_FxW_F rows
        asm volatile("sw_active_xor %[result], %[input_i], 0"
        : [result] "=r" (w_out2)
        : [input_i] "r" (cnfAddress), "[result]" (w_out2)
        );
        //store operation to run the xor in-memory
        (*ofmap)[0][0] = bWeight;
        //restore the normal function of the memory.
        asm volatile("sw_active_none %[result], %[input_i], 0"
        : [result] "=r" (zero)
        : [input_i] "r" (cnfAddress), "[result]" (zero)
        );
        
        // //now popcounting operation is performed outside memory.
        // for(j = 0; j < w_out; j++)
        // {
        //     for(i = 0; i < w_out; i++)
        //     {
        //         countZeros = 0;
        //         for(m = 0; m < wf; m++)
        //         {
        //             for(t = 0; t < wf; t++)
        //             {
        //                 //shift right and AND with 1 (mask)
        //                 if( (((*ofmap)[j][i] >> (m*wf+t)) & (1)) == 0)
        //                 {
        //                     countZeros += 1;
        //                 }
        //                 else
        //                 {
        //                     countZeros -= 1;
        //                 }
        //             }
        //         }
        //         //store pop-counting result inside the ofmap.
        //         (*ofmap)[j][i] = countZeros;
        //     }
            
        // }
    }

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//parallelism
#define PARALLELISM 65536 //2^16
#define PARALLELISM_BIT 16
#define MAX_SAMPLES 32 //max samples (32), because the memory row is on 32 bits

//input neurons
volatile int *image = 0x20000;

//weights
volatile int *weights = 0x0;

void SNG(int x, int sample)
{
    int randomNumber = 0;
    for(int i = 0; i < PARALLELISM; i++)
    {
        randomNumber = rand()%10;
        if(randomNumber < x)
        {
            image[i] = image[i] | (1 << sample);
        }
        else
        {
            image[i] = image[i] | (0 << sample);
        }
    }
}



int main()
{
    //initialize srand function
    srand(time(NULL));
    int randomN = 0;
    //fill weights vector
    for(int i = 0; i < MAX_SAMPLES; i++)
    {
        weights[i] = rand()%10;
    }
    //fill memory and convert to stochastic representation
    for(int i = 0; i < MAX_SAMPLES; i++)
    {
        randomN = rand()%10;
        SNG(randomN, i);
    }




    return EXIT_SUCCESS;
}
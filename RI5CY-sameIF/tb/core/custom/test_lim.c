#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vector = 0x30000;
    int dummy_val=15;
    int ciao = 0x1fffc;
    int zero = 0;

    asm volatile("sw_active_or %[result], %[input_i], 0"
    : [result] "=r" (dummy_val)
    : [input_i] "r" (ciao), "[result]" (dummy_val)
    );
    vector[0] = 3;
    // asm volatile("sw_active_or %[result], %[input_i], 0"
    // : [result] "=r" (zero)
    // : [input_i] "r" (ciao), "[result]" (zero)
    // );
    asm volatile("sw_active_none %[result], %[input_i], 0"
    : [result] "=r" (zero)
    : [input_i] "r" (ciao), "[result]" (zero)
    );
    asm volatile("ecall");
    printf("Hello world!\n");
    return 0;
}
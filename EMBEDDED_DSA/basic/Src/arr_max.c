#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

uint32_t sig[] = { 23, 567, 0, 12, 144, 134, 13, 4, 230};
void arr_2_max(uint32_t *src_array, uint32_t *dest_array, uint32_t src_len);
uint32_t output[4];

int main(void)
{
    system_init();
    printf("\n");

    arr_2_max(sig, output, 9);

    printf("max 1 = %ld\n\r", output[0]);
    printf("max 2 = %ld\n\r", output[2]);

    while (1);
}

void arr_2_max(uint32_t *src_array, uint32_t *dest_array, uint32_t src_len)
{
    uint32_t max1, max2, max1_idx, max2_idx;

    max1 = src_array[0];
    for(int i = 1; i < src_len; i++)
    {
        if(src_array[i] > max1)
        {
            max1 = src_array[i];
            max1_idx = 1;
        }
    }

    max2 = src_array[0];
    for(int i = 0; i < src_len; i++)
    {
        // skip largest value
        if(src_array[i] != max1)
        {
            if(src_array[i] > max2)
            {
                max2 = src_array[i];
                max2_idx = i;
            }

        }
    }

    dest_array[0] = max1;
    dest_array[1] = max1_idx;
    dest_array[2] = max2;
    dest_array[3] = max2_idx;
}
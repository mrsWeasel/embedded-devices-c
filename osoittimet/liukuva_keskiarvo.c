#include <stdint.h>
#include <stdio.h>

void movavg(float *array, uint8_t array_size, uint8_t window_size);

int main()
{
    float data[] = {1.0, 2.0, 4.0, 6.0, 9.0};

    movavg(data, 5, 3);
    return 0;
}

void movavg(float *array, uint8_t array_size, uint8_t window_size)
{
    for (int i = 0; i <= array_size - window_size; i++)
    {
        float avg = 0;
        for (int j = 0; j < window_size; j++)
        {
            avg += array[i + j];
        }
        printf("%.2f", avg / window_size);
        if (i < array_size - window_size)
        {
            printf(",");
        }
    }
}
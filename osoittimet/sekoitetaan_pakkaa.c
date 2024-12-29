#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LIST_SIZE 0xFFFF

void shuffle(uint8_t *list, uint16_t list_size);

int main()
{
    // siemenarvo rand-funktiolle
    srand(time(NULL));
    uint8_t list[LIST_SIZE] = {10, 20, 30, 40, 25, 35};
    shuffle(list, LIST_SIZE);

    printf("Lista:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", list[i]);
    }

    return 0;
}

void shuffle(uint8_t *list, uint16_t list_size)
{
    uint16_t counter = 0;

    while (counter < list_size)
    {
        uint8_t max = list_size - counter;

        // random-indeksi
        uint8_t temp = rand() % max;
        uint8_t current_item = list[temp];

        // siirrä taulukon alkiot vasemmalle alkaen satunnaistetusta alkiosta
        for (int i = 0; i < list_size; i++)
        {
            if (i < temp)
            {
                continue;
            }
            list[i] = list[i + 1];
        }

        // aseta satunnaisesti listasta poimittu alkio listan viimeiseksi
        list[list_size - 1] = current_item;

        counter++;
    }
}
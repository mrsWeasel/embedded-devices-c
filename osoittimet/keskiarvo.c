#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

float keskiarvo(char *lista);

float keskiarvo(char *lista)
{
    const char erotin[] = ",";
    int16_t summa = 0;
    uint8_t pituus = 0;

    char *osa = strtok(lista, erotin);
    summa += atoi(osa);
    pituus++;

    while (osa != NULL)
    {

        osa = strtok(NULL, erotin);
        if (osa != NULL)
        {
            summa += atoi(osa);
            pituus++;
        }
    }
    return (float)summa / pituus;
}

int main()
{
    char lista[] = "201,53,12,31,5";
    float ka = keskiarvo(lista);
    printf("%f\n", ka);
    return 0;
}
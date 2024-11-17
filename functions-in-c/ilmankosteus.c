#include <stdint.h>
#include <stdio.h>

// Prototyyppi
float kosteus(uint16_t rekisteri);

// Funktion toteutus
float kosteus(uint16_t rekisteri)
{
    return (float)rekisteri / 0x10000 * 100;
}

int main()
{
    float kosteus50 = kosteus(0x8000);
    printf("%f", kosteus50);
    return 0;
}
#include <inttypes.h>
#include <stdio.h>

uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb);

uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb)
{
    uint32_t msb32 = msb << 16;
    uint32_t lsb32 = lsb << 8;
    uint32_t xlsb32 = xlsb;

    uint32_t ilmanpaine = msb32 | lsb32 | xlsb32;
    ilmanpaine = ilmanpaine >> 4;

    return ilmanpaine;
}

int main()
{
    uint32_t paine = ilmanpaine(-34, -68, 24);
    printf("%d", paine);
    return 0;
}
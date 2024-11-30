#include <inttypes.h>
#include <stdio.h>
#include <math.h>

float valoisuus(uint16_t rekisteri);

float valoisuus(uint16_t rekisteri)
{
    // rekisterissä on bitit 0..15, R0-R11 (0-11) ja E0-E3 (12-15), jotka pitää erottaa
    uint16_t eksponentti_maski = 0xf000;
    uint16_t tulos_maski = 0x0fff;

    uint16_t eksponentti = eksponentti_maski & rekisteri;
    eksponentti = eksponentti >> 12;

    uint16_t tulos = tulos_maski & rekisteri;

    return 0.01 * pow(2, eksponentti) * tulos;
}

int main()
{
    float valoisuus2000 = valoisuus(0b0110110000110101);
    printf("%f", valoisuus2000);
}
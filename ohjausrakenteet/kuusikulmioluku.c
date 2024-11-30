#include <inttypes.h>
#include <stdio.h>
#include <math.h>

uint8_t kuusikulmio(uint32_t luku);

uint8_t kuusikulmio(uint32_t luku)
{
    // kuusikulmiokaava, jossa n on positiivinen kokonaisluku ("sivun pituus")
    // n(2n -1)
    // n saadaan siis ratkaisemalla yhtälö 2n^2 - n - <luku> = 0
    double n = (1 + sqrt(1 - 8 * (luku * (-1)))) / 4;

    if (n < 0)
    {
        return 0;
    }
    else if ((int)n != n)
    {
        return 0;
    }
    return 1;
}

int main()
{
    printf("%d", kuusikulmio(6)); // 1
    printf("\n");
    printf("%d", kuusikulmio(15)); // 1
    printf("\n");
    printf("%d", kuusikulmio(66)); // 1
    printf("\n");
    printf("%d", kuusikulmio(16)); // 0
    printf("\n");
    printf("%d", kuusikulmio(95)); // 0
    return 0;
}
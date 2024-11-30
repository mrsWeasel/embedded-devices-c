#include <inttypes.h>
#include <stdio.h>

int64_t laske_kertoma(int8_t n);

int64_t laske_kertoma(int8_t n)
{
    if (n > 20)
    {
        return -1;
    }

    int8_t i;
    int64_t kertoma = 1;

    for (i = 1; i < (n + 1); i += 1)
    {
        kertoma = kertoma * i;
    }
    return kertoma;
}

int main()
{
    printf("%lld", laske_kertoma(28));
    printf("\n");
    printf("%lld", laske_kertoma(5));
}

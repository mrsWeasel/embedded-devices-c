#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void merkkilaskuri(char *str, uint8_t *tulos);
bool vokaali(char m);

bool vokaali(char m)
{
    if (m == 'a' || m == 'e' || m == 'i' || m == 'o' || m == 'u')
    {
        return true;
    }
    if (m == 'A' || m == 'E' || m == 'I' || m == 'O' || m == 'U')
    {
        return true;
    }

    return false;
}

void merkkilaskuri(char *str, uint8_t *tulos)
{
    printf("%s\n", str);

    for (int i = 0; str[i] != 0; i++)
    {
        if (!isalpha(str[i]))
        {
            continue;
        }
        else if (vokaali(str[i]))
        {
            tulos[0]++;
        }
        else
        {
            tulos[1]++;
        }
    }
}

int main()
{
    uint8_t tulos[] = {0, 0};
    char str[] = "esimerkki!3";

    merkkilaskuri(str, tulos);

    printf("Vokaalit: %d\n", tulos[0]);
    printf("Konsonantit: %d\n", tulos[1]);

    return 0;
}
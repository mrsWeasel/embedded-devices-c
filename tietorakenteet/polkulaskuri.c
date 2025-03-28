#include <math.h>
#include <stdio.h>

struct piste
{
    int koordinaatit[3];
    struct piste *seuraava;
};

struct polku
{
    double matka;
    struct piste *pisteet;
};

void laske_kuljettu_matka(struct polku *polku);

void laske_kuljettu_matka(struct polku *polku)
{
    while (polku->pisteet->seuraava != NULL)
    {
        int erotus1 = polku->pisteet->koordinaatit[0] - polku->pisteet->seuraava->koordinaatit[0];
        int erotus2 = polku->pisteet->koordinaatit[1] - polku->pisteet->seuraava->koordinaatit[1];
        int erotus3 = polku->pisteet->koordinaatit[2] - polku->pisteet->seuraava->koordinaatit[2];

        polku->matka += sqrt(pow(erotus1, 2) + pow(erotus2, 2) + pow(erotus3, 2));

        polku->pisteet = polku->pisteet->seuraava;
    }
}

int main()
{
    struct piste piste3 = {{4, 4, 4}};
    struct piste piste2 = {{3, 4, 6}, &piste3};
    struct piste piste1 = {{1, 2, 3}, &piste2};

    struct polku polku = {0.0, &piste1};
    laske_kuljettu_matka(&polku);

    printf("%f", polku.matka);
    return 0;
}
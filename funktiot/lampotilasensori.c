#include <inttypes.h>
#include <stdio.h>

float lampotila(uint16_t rekisteri);

float lampotila(uint16_t rekisteri)
{
    // rekisterissä on bitit 0..15, lämpötila on tallennettu bitteihin 2..15
    // nämä bitit "irroitetaan" rekisteristä bittioperaatiolla
    // saatu arvo kerrotaan kertoimella 0.03125, jolloin saadaan lämpötila Celsius-asteina

    // bittien siirto oikealle tiputtaa pois 2 "ylimääräistä" bittiä
    rekisteri = rekisteri >> 2;

    return rekisteri * 0.03125;
}

int main()
{
    float testilampotila = lampotila(0b0011001000000000);
    printf("%f", testilampotila);
    return 0;
}

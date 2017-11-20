#include <stdio.h>
#include <stdlib.h>

int czy_pierwsza(int liczba)
{
    int  dzielnik;
    for(dzielnik = 2; dzielnik <= liczba; dzielnik++)
    {
        if (dzielnik == liczba)
        {
            return 1;
        }
        if (liczba % dzielnik == 0)
        {
            return 0;
        }

    }
}




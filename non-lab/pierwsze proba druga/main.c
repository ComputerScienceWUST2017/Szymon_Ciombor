#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, cntr, a;
    cntr=0;
    a=2;


    printf("Podaj liczbe naturalna: ");
    scanf("%d",&n);
    printf("Liczby zydowskie to : ");
    // int tab[]={0}; TABLICA JEST SPIERDOLONA
    while (cntr<n)
    {
        if (czy_pierwsza(a)==1)
        {

            cntr=cntr+1;
            printf("%d\n",a);


        }
        a=a+1;
    }


    return 0;
}

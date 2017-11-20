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
    int tab[n];
    while (cntr<n)
    {
        if (czy_pierwsza(a)==1)
        {
            tab[cntr]=a;

            printf("%d\n",tab[cntr]);
            cntr=cntr+1;

        }
        a=a+1;
    }


    return 0;
}

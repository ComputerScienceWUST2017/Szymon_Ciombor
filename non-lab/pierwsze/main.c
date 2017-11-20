#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int b=5;
    int dzielnik;
    int lista_zboru[]= {0};
    int licznik=0;
    printf("Podaj przedzial gorny b: \n");
    //scanf("%d",&b);//
    for(int liczba=2; liczba<=5; liczba++)
    {
        dzielnik=2;
        while(dzielnik<=liczba)
        {
            printf("dzielnik %d\n",dzielnik);
            printf("liczba %d\n",liczba);
            if (liczba==dzielnik)
            {
                lista_zboru[licznik]=liczba;
                 printf("Lista zboru 1 xd: ");
                for (int k=0; k<=licznik; k++)
    {
            printf(" %d ",lista_zboru[k]);
    }
                licznik=licznik+1;
                break;
            }
            if (liczba % dzielnik == 0)
            {
                break;
            }

            dzielnik=dzielnik+1;
        }
        printf("Lista zboru 2 xd: ");
        for (int k=0; k<=licznik; k++)
    {
            printf(" %d ",lista_zboru[k]);
    }
    }
    for (int k=0; k<=licznik; k++)
    {
            printf("%d ",lista_zboru[k]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int number)
{
    int i;
    for (i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void countPrimes(int x)
{
    int i;
    int arrayOfNumbers[x];
    arrayOfNumbers[0] = 0;
    for (i = 2;i<=x;i++)
    {
        if (isPrime(i) == 1)
        {
            arrayOfNumbers[i-1] = arrayOfNumbers[i-2]+1;
        }
        else arrayOfNumbers[i-1] = arrayOfNumbers[i-2];
    }
    int n;
    float result;
    FILE *fp;
    fp = fopen("C:\\programy\\non-lab\\PrimeNumbers\\out.txt","r+");
    for (n = 2; n <= x; n++)
    {
        result = arrayOfNumbers[n-1]/(n/logf(n));
        fprintf(fp, "%d;%.10f\n",n,result);
    }
    fclose(fp);
}
/*int numberOfPrimes(int x)
{
    int counter = 0;
    int i;
    for (i = 2; i <= x; i++)
    {
        if (isPrime(i) == 1)
        {
            counter++;
        }
    }
    return counter;
}
*/

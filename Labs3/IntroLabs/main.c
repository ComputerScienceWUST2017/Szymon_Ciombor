#include <stdio.h>
#include <stdlib.h>
#include "TokenFunctions.h"

int main()
{
    int len = 256;
    char string[len];
    if (nextWord(string,len) == 1)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
    if (nextName(string,len) == 1)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
    if (nextIntNumber(string,len) == 1)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
    if (nextFpNumber(string,len) == 1)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
    if (nextTelNumber(string,len) == 1)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
    return 0;
}

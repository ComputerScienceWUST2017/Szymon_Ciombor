#include <stdio.h>
#include <stdlib.h>
#include "TokenFunctions.h"

int main()
{
    int len = 256;
    char buffer[len];
    while (scanf("%s",buffer) == 1)
    {
        if (nextWord(buffer,len) == 1)
        {
            printf("The string is a word!\n");
        }
        if (nextName(buffer,len) == 1)
        {
            printf("The string is a name!\n");
        }
        if (nextIntNumber(buffer,len) == 1)
        {
            printf("The string is an integer number!\n");
        }
        if (nextFpNumber(buffer,len) == 1)
        {
            printf("The string is a floating point number!\n");
        }
        if (nextTelNumber(buffer,len) == 1)
        {
            printf("The string is a telephone number!\n");
        }
    }
    return 0;
}

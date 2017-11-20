#include <stdio.h>
#include <stdlib.h>
#include "TokenFunctions.h"

int main()
{
    int len = 256;
    char string[len];
    if (nextIntNumber(string,len) == 1)
    {
        printf("TRUE");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CharOccurence.h"
int mostOften(int allChars[256])
{
    int result;
    int k;
    for (k = 0; k < sizeof(allChars)/sizeof(int); k++)
    {
        if (allChars[k] > result)
        {
            result = allChars[k];
        }
    }
    return result;
}

#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
static int len = 255;

int main()
{
    char line[len];
    char* result;
    while (fgets(line,len,stdin) != '\0')
    {
        result = lineCalc(line, len);
        printf("%s\n",result);
    }
    return 0;
}

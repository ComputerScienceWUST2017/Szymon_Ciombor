#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "RangeSelection.h"
int main (int argc, char* argv[])
{
    int len = 255;
    int i, filterPos;
    int optionalArgCount = 0, ignoreCase = 0, minusPos = 0, isError = 0;
    char line[len], filter1[len], filter2[len];
    filter1[0] = '\0';
    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i],"/I") == 0)
        {
            ignoreCase = 1;
            optionalArgCount++;
        }
        else if (strcmp(argv[i],"-") == 0)
        {
            minusPos = i;
        }
        else
        {
            if (filter1[0] == '\0')
            {
                strcpy(filter1, argv[i]);
            }
            else
            {
                strcpy(filter2, argv[i]);
            }
            filterPos = i;
        }
    }
    while (fgets(line, sizeof(line), stdin) != '\0')
    {
        switch((argc-optionalArgCount))
        {
        case 2:
            lineStartingWith(filter1, line,ignoreCase);
            break;
        case 3:
            if (minusPos != 0)
            {
                if (minusPos < filterPos)
                {
                    linePrecede(filter1,line,ignoreCase);
                }
                if (minusPos > filterPos)
                {
                    lineFollow(filter1,line,ignoreCase);
                }
            }
            else
            {
                lineRange(filter1,filter2,line,ignoreCase);
            }
            break;
        default:
            if (isError == 0)
            {
                fprintf(stderr,"Please provide proper parameters!");
                isError = 1;
            }
        }
    }
    return 0;
}

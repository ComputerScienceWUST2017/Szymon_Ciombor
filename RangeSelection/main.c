#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RangeSelection.h"
int main (int argc, char* argv[])
{
    int len = 255;
    int i, filterPos;
    int optionalArgCount = 0, endMode = 0, ignoreCase = 0, mode999 = 0, minusPos = 0;
    char line[len], filter1[len], filter2[len];
    filter1[0] = '\0';
    filter2[0] = '\0';
    FILE *fp;
    fp = fopen("InputLines.txt", "r");
    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i],"/E") == 0)
        {
            endMode = 1;
            optionalArgCount++;
        }
        else if (strcmp(argv[i],"/I") == 0)
        {
            ignoreCase = 1;
            optionalArgCount++;
        }
        else if (strcmp(argv[i],"/999") == 0)
        {
            mode999 = 1;
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
    switch((argc-optionalArgCount))
    {
    case 2:
        while (fgets(line, sizeof(line), fp) != '\0')
        {
            lineStartingWith(filter1, line);
        }
        break;
    case 3:
        if (minusPos != 0)
        {
            if (minusPos < filterPos)
            {
                linePrecede(filter1,line);
            }
            if (minusPos > filterPos)
            {
                lineFollow(filter1,line);
            }
        }
        else
        {
            while (fgets(line, sizeof(line), fp) != '\0')
            {
                lineRange(filter1,filter2,line);
            }
        }
        break;
    default:
        printf("usage: %s filter/lowerRange/- [upperRange/-]",argv[0]);
    }
    return 0;
}

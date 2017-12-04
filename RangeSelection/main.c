#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RangeSelection.h"
int main (int argc, char* argv[])
{
    int len = 255;
    char line[len];
    FILE *fp;
    fp = fopen("InputLines.txt", "r");
    switch(argc)
    {
    case 2:
        while (fgets(line, sizeof(line), fp) != '\0')
        {
            lineStartingWith(argv[1], line);
        }
        break;
    case 3:
        if (*argv[1] == '-')
        {

        }
        if (*argv[2] == '-')
        {

        }
        else
        {
            while (fgets(line, sizeof(line), fp) != '\0')
            {

                lineRange(argv[1],argv[2],line);
            }
        }
        break;
    default:
        printf("usage: %s filter/lowerRange/- [upperRange/-]",argv[0]);
    }
    return 0;
}

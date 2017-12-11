#include <stdio.h>
#include <stdlib.h>
#include "WordTools.h"

int main(int argc, char* argv[])
{
    int len = 255;
    char text[len];
    if (argc == 2)
    {
        if (argv[1][0] == '/')
        {
            while (fgets(text, len, stdin) != '\0')
            {
                switch(argv[1][1])
                {
                case 'l':
                    change2LowerCase(text);
                    break;
                case 'L':
                    change2LowerCase(text);
                    break;
                case 'u':
                    change2UpperCase(text);
                    break;
                case 'U':
                    change2UpperCase(text);
                    break;
                case 'c':
                    switchCase(text);
                    break;
                case 'C':
                    switchCase(text);
                    break;
                case 'n':
                    makeNames(text);
                    break;
                case 'N':
                    makeNames(text);
                    break;
                default:
                    change2UpperCase(text);
                }
                puts(text);
            }
        }
        else
        {
            printf("Use proper switches!");
        }
    }
    else
    {
        printf("Please use only one switch!");
    }
    return 0;
}

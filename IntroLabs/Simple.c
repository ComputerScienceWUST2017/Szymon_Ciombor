#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void linesWith(int c)
{
    char buffer[100];
    int j = 0;
    char hasVar[j][sizeof(buffer)];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        for (int i = 0; (i<strlen(buffer)); i++)
        {
            if (buffer[i] == c)
            {
                strcpy(hasVar[j], buffer);
                j++;
                break;
            }
        }
    }
    printf("The lines containing %c are :\n",'c');
    int k;
    for (k = 0; k < j; k++)
    {
        puts(hasVar[k]);
    }
}


/* Redundant solution done to practice using arrays
void linesWith(int c)
{
    char text[5][50];
    for (int i = 0; i<5; i++)
    {
        fgets(text[i],50,stdin);
        for (int j = 0; j < sizeof(text[i]);j++)
        {
            if (text[i][j] == c)
            {
                puts(text[i]);
                break;
            }
        }
    }
}
*/

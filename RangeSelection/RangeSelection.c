#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RangeSelection.h"

void lineStartingWith(char* param, char* text)
{
    if (strncmp(param, text, strlen(param)) == 0)
    {
        printf(text);
    }
}
void lineRange(char* param1, char* param2, char* text)
{
 //   char word[strlen(text)];
  //  sscanf(text, "%s", word);
  // printf("%s\n", word);
    if ((strncmp(text,param1,strlen(param1)) >= 0) && (strncmp(text,param2,strlen(param2)) <= 0))
    {
        printf(text);
    }
}

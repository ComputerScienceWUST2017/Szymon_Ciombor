#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "WordTools.h"

void change2LowerCase(char* s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        s[i] = tolower(s[i]);
    }
}
void change2UpperCase(char* s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        s[i] = toupper(s[i]);
    }
}
void switchCase(char* s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (isupper(s[i]) != 0)
        {
            s[i] = tolower(s[i]);
        }
        else
        {
            s[i] = toupper(s[i]);
        }
    }
}
void makeNames(char* s)
{
    int i;
    s[0] = toupper(s[0]);
    for (i = 0; i <strlen(s)-1; i++)
    {
        s[i+1] = tolower(s[i+1]);
        if (s[i] == ' ')
        {
            s[i+1] = toupper(s[i+1]);
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RangeSelection.h"

void lineStartingWith(char* param, char* text,int ignoreCase)
{
    if (ignoreCase == 0)
    {
        if (strncmp(param, text, strlen(param)) == 0)
        {
            puts(text);
        }
    }
    else
    {
        if (strnicmp(param, text, strlen(param)) == 0)
        {
            puts(text);
        }
    }
}
void lineRange(char* param1, char* param2, char* text, int ignoreCase)
{
    if (ignoreCase == 0)
    {
        if ((strncmp(text,param1,strlen(param1)) >= 0) && (strncmp(text,param2,strlen(param2)) <= 0))
        {
            puts(text);
        }
    }
    else
    {
        if ((strnicmp(text,param1,strlen(param1)) >= 0) && (strnicmp(text,param2,strlen(param2)) <= 0))
        {
            puts(text);
        }
    }
}
void linePrecede(char* param, char* text, int ignoreCase)
{
    if (ignoreCase == 0)
    {
        if (strncmp(param, text, strlen(param)) >= 0)
        {
            puts(text);
        }
    }
    else
    {
        if (strnicmp(param, text, strlen(param)) >= 0)
        {
            puts(text);
        }
    }
}
void lineFollow(char* param, char* text, int ignoreCase)
{
    if (ignoreCase == 0)
    {
        if (strncmp(param, text, strlen(param)) <= 0)
        {
            puts(text);
        }
    }
    else
    {
        if (strnicmp(param, text, strlen(param)) <= 0)
        {
            puts(text);
        }
    }
}

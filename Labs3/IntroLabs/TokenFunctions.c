#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TokenFunctions.h"



int nextWord(char* buffer, int len)
{
    char token[len];
    fgets(buffer, len, stdin);
    int i = 0;
    int j = 0;
BEGIN:
    while (buffer[j] != '\0')
    {

        sscanf(buffer + j, "%s", token);
        for (i = 0; i < strlen(token); i++)
        {
            if (((token[i] >= 'A') && (token[i] <= 'Z')) || ((token[i] >= 'a') && (token[i] <= 'z'))) //check whether the character belongs to the alphabet
            {
                continue;
            }
            else
            {
                j = j + strlen(token) + 1;
                goto BEGIN;
            }

        }
        return 1;
    }
    return EOF;
}


int nextName(char* buffer, int len)
{
    char token[len];
    fgets(buffer, len, stdin);
    int i = 0;
    int j = 0;
BEGIN:
    while (buffer[j] != '\0')
    {

        sscanf(buffer + j, "%s", token);
        for (i = 1; i < strlen(token); i++)
        {
            if (((token[0] >= 'A') && (token[0] <= 'Z')) && ((token[i] >= 'a') && (token[i] <= 'z'))) //check whether the character belongs to the alphabet and if the first character is uppercase
            {
                continue;
            }
            else
            {
                j = j + strlen(token) + 1;
                goto BEGIN;
            }

        }
        return 1;
    }
    return EOF;
}

int nextIntNumber(char* buffer, int len)
{
    char token[len];
    fgets(buffer, len, stdin);
    int i = 0;
    int j = 0;
BEGIN:
    while (buffer[j] != '\0')
    {

        sscanf(buffer + j, "%s", token);
        for (i = 1; i < strlen(token); i++)
        {
            if (((token[0] == '+') || (token[0] == '-')) || (((token[0] >= '0') && (token[0] <= '9')) && ((token[i] >= '0') && (token[i] <= '9')))) //check whether the first character is a - sign, + sign or a digit and if the remaining characters are digits
            {
                continue;
            }
            else
            {
                j = j + strlen(token) + 1;
                goto BEGIN;
            }

        }
        return 1;
    }
    return EOF;
}

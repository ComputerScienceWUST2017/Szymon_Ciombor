#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TokenFunctions.h"

int isULetter(char character)
{
    if ((character >= 'A') && (character <= 'Z'))
    {
        return 1;
    }
    return 0;
}
int isLLetter(char character)
{
    if ((character >= 'a') && (character <= 'z'))
    {
        return 1;
    }
    return 0;
}
int isDigit(char character)
{
    if ((character >= '0') && (character <= '9'))
    {
        return 1;
    }
    return 0;
}
int isSign(char character)
{
    if ((character == '+') || (character == '-'))
    {
        return 1;
    }
    return 0;
}
int isPoint(char character)
{
    if (character == '.')
    {
        return 1;
    }
    return 0;
}
int isDigitOrPoint(char character)
{
    if ((isPoint(character) == 1) || (isDigit(character) == 1))
    {
        return 1;
    }
    return 0;
}

int nextWord(char* buffer, int len)
{
    int i = 0;
    scanf("%s", buffer);
    for (i = 0; i < strlen(buffer); i++)
    {
        if ((isULetter(buffer[i]) == 1) || (isLLetter(buffer[i]) == 1)) //check whether the character belongs to the alphabet
        {
            continue;
        }
        else
        {
            return 0;
        }

    }
    return 1;
}


int nextName(char* buffer, int len)
{
    int i = 0;

    scanf("%s", buffer);
    for (i = 1; i < strlen(buffer); i++)
    {
        if ((isULetter(buffer[0]) == 1) && (isLLetter(buffer[i]) == 1)) //check whether the character belongs to the alphabet and if the first character is uppercase
        {
            continue;
        }
        else
        {
            return 0;
        }

    }
    return 1;
}
int nextIntNumber(char* buffer, int len)
{
    int i = 0;
    scanf("%s", buffer);
    for (i = 1; i < strlen(buffer); i++)
    {
        if (((isSign(buffer[0]) == 1) || (isDigit(buffer[0]) == 1)) && (isDigit(buffer[i]) == 1)) //check whether the first character is a - sign, + sign or a digit and if the remaining characters are digits
        {
            continue;
        }
        else
        {
            return 0;
        }

    }
    return 1;
}
int nextFpNumber(char* buffer, int len)
{
    int i = 0;
    int containsPoint = 0;
    scanf("%s", buffer);
    for (i = 1; i < strlen(buffer); i++)
    {
        if (isPoint(buffer[i]) == 1)
        {
            containsPoint++;
        }
    }
    for (i = 1; i < strlen(buffer); i++)
    {
        if (containsPoint == 1)
        {
            if (((isSign(buffer[0]) == 1) || (isDigit(buffer[0]) == 1)) && (isDigitOrPoint(buffer[i]) == 1)) //check whether character is a - sign, + sign or a digit and if the remaining characters are digits
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int nextTelNumber(char* buffer, int len)
{
    int i = 0;
    int numberAmount = 0;
    int slashAmount = 0;

    scanf("%s", buffer);
    for (i = 0; i < strlen(buffer); i++)
    {
        if (isDigit(buffer[i]) == 1)
        {
            if (( i != 3) && (i != 7))
            {
                numberAmount++;
            }
        }
        else
        {
            if (((i == 3) || (i == 7)) && (buffer[i] == '/'))
            {
                slashAmount++;
            }
        }
    }
    if (strlen(buffer) == 11)
    {
        if ((numberAmount == 9) && (slashAmount == 2))
        {
            return 1;
        }
    }
    return 0;
}

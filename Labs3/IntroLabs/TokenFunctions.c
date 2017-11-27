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
int isDigitOrPoint(char character)
{
    if ((isDigit(character) == 1) || (character == '.'))
    {
        return 1;
    }
    return 0;
}
int isPunctuation(char character)
{
    if ((character == '.') || (character == ',') || (character == ';') || (character == ':') || (character == '!') || (character == '?') || (character == '"') || (character == 39 ))
    {
        return 1;
    }
    return 0;
}
void cutPunctuation(char* buffer)
{
    while (isPunctuation(buffer[strlen(buffer)-1]) == 1)
    {
        buffer[strlen(buffer)-1] = '\0';
    }
}

int nextWord(char* buffer, int len)
{
    int i = 0;
    cutPunctuation(buffer);
    for (i = 0; i < strlen(buffer)-1; i++)
    {
        if ((isULetter(buffer[i]) == 1) || (isLLetter(buffer[i]) == 1))
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
    cutPunctuation(buffer);
    if (isULetter(buffer[i]) == 0)
    {
        return 0;
    }
    for (i = 1; i < strlen(buffer)-1; i++)
    {
        if (isLLetter(buffer[i]) == 0)
        {
            return 0;
        }
    }
    return 1;

}
int nextIntNumber(char* buffer, int len)
{
    int i = 0;
    cutPunctuation(buffer);
    if ((isDigit(buffer[0]) == 0) && (isSign(buffer[0]) == 0))
    {
        return 0;
    }
    for (i = 1; i < strlen(buffer); i++)
    {
        if (isDigit(buffer[i]) == 1)
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
    cutPunctuation(buffer);
    if ((isDigit(buffer[0]) == 0) && (isSign(buffer[0]) == 0))
    {
        return 0;
    }
    for (i = 1; i < strlen(buffer); i++)
    {
        if (buffer[i] == '.')
        {
            containsPoint++;
        }
    }
    if (containsPoint != 1)
    {
        return 0;
    }
    for (i = 1; i < strlen(buffer); i++)
    {
        if (isDigitOrPoint(buffer[i]) == 1)
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

int nextTelNumber(char* buffer, int len)
{
    int i = 0;
    int numberAmount = 0;
    int slashAmount = 0;
    cutPunctuation(buffer);
    for (i = 0; i < 3; i++)
    {
        if (isDigit(buffer[i]) == 1)
        {
            numberAmount++;
        }
    }
    for (i = 4; i < 7; i++)
    {
        if (isDigit(buffer[i]) == 1)
        {
            numberAmount++;
        }
    }
    for (i = 8; i < 11; i++)
    {
        if (isDigit(buffer[i]) == 1)
        {
            numberAmount++;
        }
    }
    if ((buffer[3] == '/') && (buffer[7] == '/'))
    {
        slashAmount = 2;
    }
    if (strlen(buffer) != 11)
    {
        return 0;
    }
    if ((numberAmount == 9) && (slashAmount == 2))
    {
        return 1;
    }
    return 0;
}

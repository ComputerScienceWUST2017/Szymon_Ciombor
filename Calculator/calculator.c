#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculator.h"

int nextIntNumber(char* tk, int len)
{
    int i = 0;
    if ((isdigit(tk[0]) == 0) && ((tk[0] != '-') && (tk[0] != '+')))
    {
        return 0;
    }
    for (i = 1; i < strlen(tk); i++)
    {
        if (isdigit(tk[i]) != 0)
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
int nextFpNumber(char* tk, int len)
{
    int i = 0;
    int containsPoint = 0;
    if ((isdigit(tk[0]) == 0) && ((tk[0] != '-') && (tk[0] != '+')))
    {
        return 0;
    }
    for (i = 1; i < strlen(tk); i++)
    {
        if (tk[i] == '.')
        {
            containsPoint++;
        }
    }
    if (containsPoint != 1)
    {
        return 0;
    }
    for (i = 1; i < strlen(tk); i++)
    {
        if ((isdigit(tk[i]) == 1) || (tk[i] == '.'))
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

int isAddition(char tk[], int len)
{
    if ((strncmp(tk,"add",len) == 0) || (strncmp(tk,"+",len) == 0))
    {
        return 1;
    }
    return 0;
}
int isEquation(char tk[], int len)
{
    if ((strncmp(tk,"equals",len) == 0) || (strncmp(tk,"=",len) == 0))
    {
        return 1;
    }
    return 0;
}
int isSubtraction(char tk[], int len)
{
    if ((strncmp(tk,"subtract",len) == 0) || (strncmp(tk,"-",len) == 0))
    {
        return 1;
    }
    return 0;
}
int isMultiplication(char tk[], int len)
{
    if ((strncmp(tk,"multiply",len) == 0) || (strncmp(tk,"*",len) == 0))
    {
        return 1;
    }
    return 0;
}
int isDivision(char tk[], int len)
{
    if ((strncmp(tk,"divide",len) == 0) || (strncmp(tk,"/",len) == 0))
    {
        return 1;
    }
    return 0;
}
int isPrev(char tk[], int len)
{
    if ((strncmp(tk,"prev",len) == 0) || (strncmp(tk,"prev_result",len) == 0))
    {
        return 1;
    }
    return 0;
}
TokenType getNextToken(char tk[], int len)
{
    if (isAddition(tk,len) == 1)
    {
        return ADD;
    }
    else if (isEquation(tk,len) == 1)
    {
        return EQUALS;
    }
    else if (isSubtraction(tk,len) == 1)
    {
        return SUBTRACT;
    }
    else if (isMultiplication(tk,len) == 1)
    {
        return MULTIPLY;
    }
    else if (isDivision(tk,len) == 1)
    {
        return DIVIDE;
    }
    else if (isPrev(tk,len) == 1)
    {
        return PREV;
    }
    else if ((nextIntNumber(tk,len) == 1) || (nextFpNumber(tk,len) == 1))
    {
        return NUMBER;
    }
    return WORD;
}
static char output[255];
static double prevresult = 0;

char* lineCalc(char* line, int len)
{
    int i = 0;
    double memory = 0;
    char tk[len];
    TokenType currTokenType = WORD;
    TokenType currOperation = ADD;
    while (sscanf((line + i),"%s",tk) == 1)
    {
        i = i + strlen(tk) + 1;
        currTokenType = getNextToken(tk, len);
        if (currTokenType == NUMBER)
        {
            if (currOperation == ADD)
            {
                memory = memory + atof(tk);
            }
            if (currOperation == SUBTRACT)
            {
                memory = memory - atof(tk);
            }
            if (currOperation == MULTIPLY)
            {
                memory = memory * atof(tk);
            }
            if (currOperation == DIVIDE)
            {
                if (atof(tk) == 0)
                {
                    printf("Division by 0, ");
                    break;
                }
                memory = memory / atof(tk);
            }
        }
        if (currTokenType == PREV)
        {
            if (currOperation == ADD)
            {
                memory = memory + prevresult;
            }
            if (currOperation == SUBTRACT)
            {
                memory = memory - prevresult;
            }
            if (currOperation == MULTIPLY)
            {
                memory = memory * prevresult;
            }
            if (currOperation == DIVIDE)
            {
                if (prevresult == 0)
                {
                    printf("Division by 0, ");
                    break;
                }
                memory = memory / prevresult;
            }
        }
        if (currTokenType == ADD)
        {
            currOperation = ADD;
        }
        if (currTokenType == SUBTRACT)
        {
            currOperation = SUBTRACT;
        }
        if (currTokenType == MULTIPLY)
        {
            currOperation = MULTIPLY;
        }
        if (currTokenType == DIVIDE)
        {
            currOperation = DIVIDE;
        }
        if (currTokenType == EQUALS)
        {
            sprintf(output, "%4.2f", memory);
            prevresult = memory;
            return output;
        }
    }
    return "error";
}

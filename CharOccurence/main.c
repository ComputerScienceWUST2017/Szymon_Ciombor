#include <stdio.h>
#include <stdlib.h>
#include "CharOccurence.h"

static int result = 0;

int main(int argc, char* argv[])
{
    int allChars[256] = {0};
    int character;
    do
    {
        character = getchar();
        allChars[character]++;
    }
    while (character != EOF);

    mostOften(allChars);
    printf("%d %c", result);
    return 0;
}

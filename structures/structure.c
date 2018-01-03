#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

personalData getPersonDesc(char * line)
{
    char name[20];
    char* remarks = 0;
    int age;
    float weight;
    int i = 0;
    char* token = strtok(line,";");
    while (token != NULL)
    {
        switch (i)
        {
        case 0:
            strncpy();
        case 1:
            age = atoi(token);
        case 2:
            weight = atof(token);
        case 3:
            remarks
        }



        token = strtok(NULL,";");
    }
}

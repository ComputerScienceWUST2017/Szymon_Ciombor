#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

personalData getPersonDesc(char* line)
{
    personalData person;
    person.name[0] = '\0';
    person.remarks = NULL;
    person.age = -1;
    person.weight = -1;
    strcpy(person.name,strtok(line,";"));
    person.age = atoi(strtok(NULL,";"));
    person.weight = atof(strtok(NULL,";"));
    strcpy(person.remarks = malloc(50),strtok(NULL,";"));
    realloc(person.remarks,strlen(person.remarks));
    strtok(NULL,";");
    while (strtok(NULL,";") != '\0')
    {
        person.name[0] = '\0';
        person.age = -1;
        person.weight = -1;
        person.remarks = NULL;
    }
    if (person.age == 0)
    {
        person.age = -1;
    }
    if (person.weight == 0)
    {
        person.weight = -1;
    }

    return person;
}

int readData(personalData ar[], int len)
{
    int i = 0;
    char line[255];
    while ((fgets(line,255,stdin) != '\0') && (i < len))
    {
        ar[i] = getPersonDesc(line);
        i++;
    }
    strcpy(ar[i-1].remarks,"0");
    return i;
}

int getOldestPerson(personalData data[], int len)
{
    int result, i, oldest = 0;
    if (data[0].age < 0)
    {
        return -1;
    }
    for (i = 0; i < len; i++)
    {
        if (data[i].age > oldest)
        {
            oldest = data[i].age;
            result = i;
        }
    }
    return result;
}

int getSlimmestPerson(personalData data[], int len)
{
    int result, i, slimmest = INT_MAX;
    if (data[0].weight < 0)
    {
        return -1;
    }
    for (i = 0; i < len; i++)
    {
        if (data[i].weight < slimmest && data[i].weight != -1)
        {
            slimmest = data[i].weight;
            result = i;
        }
    }
    return result;
}

void printInfo(personalData ar[], int idx, char* msgOk, char* msgBad)
{
    if (idx >= 0)
    {
        printf("\n%s\nName: %s\nAge: %d\nWeight: %.1f\nRemarks: %s\n",msgOk,ar[idx].name,ar[idx].age,ar[idx].weight,ar[idx].remarks);
    }
    else
    {
        printf(msgBad);
    }
}

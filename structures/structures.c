#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

personalData getPersonDesc(char* line)
{
    personalData person;
    char* buffer;
    buffer = strtok(line,";");
    strcpy(person.remarks,"0");
    strcpy(person.name,buffer);
    buffer = strtok(NULL,";");
    person.age = atoi(buffer);
    buffer = strtok(NULL,";");
    person.weight = atof(buffer);
    buffer = strtok(NULL,";");
    strcpy(person.remarks,buffer);
    buffer = strtok(NULL,";");
    if (strcmp(buffer,"\n") != 0)
    {
        strcpy(person.remarks,"0");
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
    strcpy(ar[i].remarks,"0");
    return i;
}

int getOldestPerson(personalData data[], int len)
{
    int result, i, oldest = 0;
    if (data[0].age <= 0)
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
    if (data[0].weight <= 0)
    {
        return -1;
    }
    for (i = 0; i < len; i++)
    {
        if (data[i].weight < slimmest)
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
        printf("\nName: %s\nAge: %d\nWeight: %f\nRemarks: %s\n",ar[idx].name,ar[idx].age,ar[idx].weight,ar[idx].remarks);
    }
    else
    {
        printf(msgBad);
    }
}

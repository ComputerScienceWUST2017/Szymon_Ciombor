#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct
{
    char name[20];
    char* remarks;
    int age;
    float weight;
} personalData;

personalData getPersonDesc(char* line);
int readData(personalData ar[], int len);
int getOldestPerson(personalData data[],int len);
int getSlimmestPerson(personalData data[], int len);
void printInfo(personalData ar[], int idx, char *msgOk, char * msgbad);

#endif // STRUCTURES_H_INCLUDED

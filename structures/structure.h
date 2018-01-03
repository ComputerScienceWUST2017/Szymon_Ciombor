#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct
{
    char name[20];
    char* remarks;
    int age;
    float weight;
} personalData;

personalData getPersonDesc(char * line);
int readData(personalData ar[], int len);
int getOldestPersen(personalData data[]);
int getSlimmestPersen(personalData data[], int len);
void printInfo(personalData ar[], int idx, char *msgOk, char * msgbad);

#endif // STRUCTURE_H_INCLUDED

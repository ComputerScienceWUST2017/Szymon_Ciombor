#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
int main()
{
    personalData data[10];
    int len = readData(data,sizeof(data)/sizeof(personalData));
    int idx;
    char *msgBad="No available data";
    idx=getOldestPersen(data);
    printInfo(data, idx, "Oldest person", msgBad);
    idx=getSlimmestPersen(data, len);
    printInfo(data, idx, "slimmest person", msgBad);
    puts("End of work!");
    return 0;
}


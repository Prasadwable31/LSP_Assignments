#include<stdio.h>

int MyStrlen(char *str)
{
    if(str == NULL)
    {
        return 0;
    }

    int iCount = 0;

    while(*str != '\0')
    {
        iCount++;
        str++;
    }

    return iCount;
}
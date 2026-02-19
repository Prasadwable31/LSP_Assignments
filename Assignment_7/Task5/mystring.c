#include<stdio.h>
#include<stdbool.h>
#include "mystring.h"

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

char *MyStrcpy(char *Src, char *Dest)
{
    if(Src == NULL || Dest == NULL)
    {
        return NULL;
    }

    char *temp = Dest;

    while(*Src != '\0')
    {
        *Dest = *Src;
        Dest++;
        Src++;
    }

    *Dest = '\0';

    return temp;
}

char *MyStrncpy(char *Src, char *Dest, int Size)
{
    if(Src == NULL || Size == 0)
    {
        return NULL;
    }

    char *temp = Dest;
    int i = 0;

    for(i = 0; i < Size && Src[i] != '\0'; i++)
    {
        Dest[i] = Src[i];
    }

    Dest[i] = '\0';

    return temp;
}

char *MyStrcat(char *Src, char *Dest)
{
    if(Dest == NULL || Src == NULL)
    {
        return NULL;
    }

    char* temp = Src;

    while(*Src != '\0')
    {
        Src++;
    }

    while(*Dest != '\0')
    {
        *Src = *Dest;
        Src++;
        Dest++;
    }

    *Src = '\0';

    return temp;
}

bool MyStrcmp(char *Src, char *Dest)
{
    bool bRet = true;

    if(Src == NULL || Dest == NULL)
    {
        return false;
    }
    
    while(*Src != '\0' && *Dest != '\0')
    {
        if(*Src != *Dest)
        {
            bRet = false;
            break;
        }

        Src++;
        Dest++;
    }

    return bRet;
}

bool MyStrncmp(char *Src, char *Dest, int Size)
{
    if(Src == NULL || Dest == NULL || Size <= 0)
    {
        return false;
    }

    bool bRet = true;
    
    for(int i = 0; i < Size; i++)
    {
        if(Src[i] != Dest[i])
        {
            bRet = false;
            break;
        }

        if(Src[i] == '\0')
        {
            return true;
        }
    }

    return bRet;
}

char *MyStrrev(char *Str)
{   
    int i = 0;
    int j = 0;
    char temp = '\0';

    while(Str[j] != '\0')
    {
        j++;
    }

    j--;

    while(i < j)
    {
        temp = Str[i];
        Str[i] = Str[j];
        Str[j] = temp;

        i++;
        j--;
    }

    return Str;
}

char *MyStrstr(char *Str1, char *Str2)
{
    if(Str1 == NULL || Str2 == NULL)
    {
        return NULL;
    }

    if(*Str2 == '\0')
    {
        return Str1; 
    }

    while(*Str1 != '\0')
    {
        char *h = Str1;
        char *n = Str2;

        while(*h == *n && *n != '\0')
        {
            h++;
            n++;
        }

        if(*n == '\0')
        {
            return Str1;  
        }

        Str1++;
    }

    return NULL;
}
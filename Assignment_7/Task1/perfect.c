#include<stdio.h>
#include<dlfcn.h>
#include<stdbool.h>
#include "perfect.h"

bool IsPerfect(int No)
{
    void *handle = NULL;
    int (*fp)(int);
    int iRet = 0;

    handle = dlopen("./libhelper.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fp = (int (*)(int))dlsym(handle, "SumOfFactor");

    iRet = fp(No);

    if(iRet == No)
    {
        return true;
    }
    else
    {
        return false;
    }

    dlclose(handle);
}
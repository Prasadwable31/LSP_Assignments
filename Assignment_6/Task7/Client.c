#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *handle = NULL;
    int iRet = 0;

    dlerror();

    void (*fp)(void);    

    handle = dlopen("./Server.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fp = (void (*)(void))dlsym(handle, "modify");
    
    if(fp == NULL)
    {
        printf("Error LAZY : %s\n", dlerror());
        dlclose(handle);
        // return -1;
    }

    fp();

    fp = (void (*)(void))dlsym(handle, "Display");

    if(fp == NULL)
    {
        printf("Error LAZY : %s\n", dlerror());
        dlclose(handle);
        // return -1;
    }

    fp();    

    fp = (void (*)(void))dlsym(handle, "Reset");

    if(fp == NULL)
    {
        printf("Error LAZY : %s\n", dlerror());
        dlclose(handle);
        // return -1;
    }

    fp();

    fp = (void (*)(void))dlsym(handle, "Display");

    if(fp == NULL)
    {
        printf("Error LAZY : %s\n", dlerror());
        dlclose(handle);
        // return -1;
    }

    fp();

    dlclose(handle);
    
    return 0;
}
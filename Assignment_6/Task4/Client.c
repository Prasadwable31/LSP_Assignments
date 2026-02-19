#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *handle = NULL;
    int iRet = 0;

    int (*fp)(int, int);

    handle = dlopen("./Server.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fp = (int (*)(int, int))dlsym(handle, "Additions");
    
    if(fp == NULL)
    {
        printf("Error : %s\n", dlerror());
        dlclose(handle);
        return -1;
    }
    
    iRet = fp(11, 21);
    
    printf("Addition is : %d\n", iRet);

    dlclose(handle);
    
    return 0;
}

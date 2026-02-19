#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *handle = NULL;
    int iRet = 0;

    dlerror();

    int (*fp)(int, int);

    handle = dlopen("./Server.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }
    
    printf("Library Loaded for RTLD_LAZY\n");
    
    fp = (int (*)(int, int))dlsym(handle, "Additions");
    
    if(fp == NULL)
    {
        printf("Error LAZY : %s\n", dlerror());
        dlclose(handle);
        // return -1;
    }

    iRet = fp(11, 21);
    
    printf("Addition is : %d\n", iRet);

    dlclose(handle);

    // ------------------------------------------------------------------------------------------------

    fp = NULL;
    dlerror();    

    handle = dlopen("./Server.so", RTLD_NOW);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    printf("Library Loaded for RTLD_NOW\n");

    fp = (int (*)(int, int))dlsym(handle, "Additions");
    
    if(fp == NULL)
    {
        printf("Error NOW : %s\n", dlerror());
        dlclose(handle);
        // return -1;
    }
    
    iRet = fp(11, 21);
    
    printf("Addition is : %d\n", iRet);

    dlclose(handle);
    
    return 0;
}

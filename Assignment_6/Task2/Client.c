#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *handle = NULL;
    int iRet = 0;

    int (*fp)(int, int);

    dlerror();          // clear the old errors

    // Step 1 : Load the library
    handle = dlopen("./Server.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Error : dlopen failed %s\n",dlerror());             // It prints the last error occur
        return -1;
    }

    dlerror();          // After use again clear old errors

    // Step 2 : Fetch the address of the function
    fp = (int (*)(int, int))dlsym(handle, "Addition");
    
    if(fp == NULL)
    {
        printf("Error : dlsym failed %s\n",dlerror());
        dlclose(handle);
        return -1;
    }
    
    // Call the function
    iRet = fp(11, 21);
    
    printf("Addition is : %d\n", iRet);

    // Step 3 : close the handle 
    dlclose(handle);
    
    return 0;
}

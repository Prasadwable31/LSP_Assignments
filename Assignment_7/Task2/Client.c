#include<stdio.h>
#include<dlfcn.h>

int main(int argc, char const *argv[])
{
    void *handle = NULL;
    int (*fp)(int,int);
    int iValue1 = 0, iValue2 = 0;
    int iRet = 0;

    dlerror();

    handle = dlopen("./Addition.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    printf("Enter the Number 1 : ");
    scanf("%d", &iValue1);

    printf("Enter the Number 2 : ");
    scanf("%d", &iValue2);

    fp = (int (*)(int, int)) dlsym(handle, "Addition");

    if(fp == NULL)
    {
        printf("Error : %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(iValue1, iValue2);

    printf("Addition is : %d\n", iRet);

    dlclose(handle);

// --------------------------------------------------------------------------------------

    dlerror();

    handle = dlopen("./Substraction.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fp = (int (*)(int, int)) dlsym(handle, "Substraction");

    if(fp == NULL)
    {
        printf("Error : %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(iValue1, iValue2);

    printf("Substraction is : %d\n", iRet);

    dlclose(handle);
    
    return 0;
}

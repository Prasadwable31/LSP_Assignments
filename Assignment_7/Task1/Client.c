#include<stdio.h>
#include<dlfcn.h>
#include<stdbool.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int);
    bool bRet = 0;
    int iValue = 0;

    handle = dlopen("./libperfect.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fp = (int (*)(int))dlsym(handle, "IsPerfect");

    printf("Enter the number : ");
    scanf("%d", &iValue);

    bRet = fp(iValue);

    if(bRet == true)
    {
        printf("Number is Perfect\n");
    }
    else
    {
        printf("Number is Not Perfect\n");
    }

    dlclose(handle);
    return 0;
}
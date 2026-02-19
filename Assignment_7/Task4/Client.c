#include<stdio.h>
#include<dlfcn.h>

int main(int argc, char const *argv[])
{
    void *handle = NULL;
    char str[100] = {'\0'};
    int (*fp)(char *);
    int iRet = 0;

    handle = dlopen("./libmystring.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    printf("Enter the string : ");
    scanf("%[^\n]", str);

    fp = (int (*) (char*)) dlsym(handle, "MyStrlen");

    if(fp == NULL)
    {
        printf("Error : %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(str);
    printf("The Length of string is : %d\n", iRet);
    
    dlclose(handle);
    
    return 0;
}

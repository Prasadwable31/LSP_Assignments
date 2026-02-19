#include<stdio.h>
#include<dlfcn.h>

int main(int argc, char const *argv[])
{
    void *handle = NULL;
    char str[100] = {'\0'};
    void (*fp)(char*);

    handle = dlopen("./libDisplay.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    printf("Enter the string : ");
    scanf("%[^\n]", str);

    fp = (void (*) (char*)) dlsym(handle, "Display");

    if(fp == NULL)
    {
        printf("Error : %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    fp(str);
    
    dlclose(handle);
    
    return 0;
}

#include<stdio.h>
#include<dlfcn.h>

int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        printf("Invalid Parameters\n");
        printf("./Myexe pathoflibrary functionname\n");
        return -1;
    }

    dlerror();

    void *handle = NULL;
    int (*fp)(int, int);

    handle = dlopen(argv[1], RTLD_LAZY);

    if(handle == NULL) 
    { 
        printf("Unable to load the library\n"); 
        return -1; 
    }

    fp = (int (*) (int, int)) dlsym(handle, argv[2]);

    if(fp == NULL)
    {
        printf("Error : %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    printf("Function Name is : %s\n", argv[2]);
    printf("Address of function : %p\n", &fp);

    dlclose(handle);
    
    return 0;
}

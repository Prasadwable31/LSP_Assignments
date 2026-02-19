#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *handle = NULL;
    int iRet = 0;

    dlerror();

    int (*fp)(int, int);

    handle = dlopen("Server.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }
    
    printf("Library Loaded for RTLD_LAZY\n");
    
    fp = (int (*)(int, int))dlsym(handle, "Addition");
    
    if(fp == NULL)
    {
        printf("Error LAZY : %s\n", dlerror());
        dlclose(handle);
        // return -1;
    }

    iRet = fp(11, 21);
    
    printf("Addition is : %d\n", iRet);

    dlclose(handle);
    
    return 0;
}

// export LD_LIBRARY_PATH=/home/prasad/Desktop/LSP/Assignments/Assignment_6:$LD_LIBRARY_PATH
// ./Myexe

// OR

// LD_LIBRARY_PATH=/home/prasad/Desktop/LSP/Assignments/Assignment_6 ./Myexe
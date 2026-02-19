#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int call_function(void *handle, char **Arr, char *str)
{
    int (*functions[3])(char *);
    char *error;
    
    for(int i = 0; i < 3; i++)
    {
        dlerror();
        functions[i] = (int (*)(char *)) dlsym(handle, Arr[i]);
        
        if((error = dlerror()) != NULL)
        {
            printf("Error loading %s: %s\n", Arr[i], error);
            return -1;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        printf("Function %s : Address %p : result: %d\n",Arr[i], (void *)functions[i], functions[i](str));
    }
}

int main()
{
    void *handle = NULL;
    char str[100];

    char *Arr[3] = {"CountLower", "CountUpper", "CountDigit"};

    handle = dlopen("./Server.so", RTLD_LAZY); 
    if(handle == NULL) 
    { 
        printf("Unable to load the library\n"); 
        return -1; 
    }

    printf("Enter the String : ");
    scanf(" %99[^\n]", str);

    call_function(handle, Arr, str);

    dlclose(handle);
    
    return 0;
}
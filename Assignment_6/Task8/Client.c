#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int call_function(void *handle, const char *name, char *str)
{
    int (*fp)(char *);
    char *error;

    dlerror();
    fp = (int (*)(char *)) dlsym(handle, name);

    if((error = dlerror()) != NULL)
    {
        printf("Error loading %s: %s\n", name, error);
        return -1;
    }

    return fp(str);
}

int main()
{
    void *handle = NULL;
    char str[100];

    handle = dlopen("./Server.so", RTLD_LAZY); if(handle == NULL) 
    { 
        printf("Unable to load the library\n"); 
        return -1; 
    }

    printf("Enter the String : ");
    scanf(" %99[^\n]", str);

    printf("Lower: %d\n", call_function(handle, "CountLower", str));

    printf("Upper: %d\n", call_function(handle, "CountUpper", str));
    
    printf("Digit: %d\n", call_function(handle, "CountDigit", str));

    
    return 0;
}
#include<stdio.h>
#include<dlfcn.h>

int main(int argc, char const *argv[])
{
    void *handle = NULL;
    int choice = 0;
    int iRet = 0;
    int iValue1 = 0, iValue2 = 0;

    int (*fp)(int ,int);

    dlerror();

    handle = dlopen("./Server.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Error : %s\n", dlerror());
        return -1;
    }

    while(1)
    {
        printf("----------Menu--------\n");
        printf("1. Addition\n");
        printf("2. Substraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        printf("Enter the 2 value : ");
        scanf("%d %d", &iValue1, &iValue2);

        switch(choice)
        {
            case 1:
                fp = (int (*) (int, int))dlsym(handle, "Addition");       
                
                iRet = fp(iValue1, iValue2);

                printf("Addition is : %d\n", iRet);
                break;

            case 2:
                fp = (int (*) (int, int))dlsym(handle, "Substraction");       
                
                iRet = fp(iValue1, iValue2);

                printf("Substraction is : %d\n", iRet);
                break;

            case 3:
                fp = (int (*) (int, int))dlsym(handle, "Multiplication");       
                
                iRet = fp(iValue1, iValue2);

                printf("Multiplication is : %d\n", iRet);
                break;

            case 4:
                fp = (int (*) (int, int))dlsym(handle, "Division");       
                
                iRet = fp(iValue1, iValue2);

                printf("Division is : %d\n", iRet);
                break;

            case 5:
                dlclose(handle);
                return 0;
            
            default:
                printf("Enter the Valid Choice!\n");
                break;
        }
    }

    return 0;
}

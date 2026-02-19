#include<stdio.h>
#include<stdbool.h>
#include<dlfcn.h>

int main(int argc, char const *argv[])
{
    void *strHandle = NULL;
    void *mathHandle = NULL;

    int choice = 0;
    int iRet = 0;
    int no1 = 0, no2 = 0;
    int Size = 0;

    char str1[100], str2[100];

    strHandle = dlopen("./libmystring.so", RTLD_LAZY);

    if(strHandle == NULL)
    {
        printf("Unable to load libmystring.so\n");
        return -1;
    }

    mathHandle = dlopen("./libmymath.so", RTLD_LAZY);
    if(mathHandle == NULL)
    {
        printf("Unable to load libmymath.so\n");
        return -1;
    }

    while(1)
    {
        printf("\n===== MENU =====\n");
        printf("1  : Strlen\n");
        printf("2  : Strcpy\n");
        printf("3  : Strncpy\n");
        printf("4  : Strcat\n");
        printf("5  : Strcmp\n");
        printf("6  : Strncmp\n");
        printf("7  : Strrev\n");
        printf("8  : Strstr\n");
        printf("9  : Max\n");
        printf("10  : Min\n");
        printf("11  : Factorial\n");
        printf("12  : Absolute\n");
        printf("13  : Power\n");
        printf("14  : Square root\n");
        printf("15  : GCD\n");
        printf("16  : LCM\n");
        printf("0  : Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if(choice == 0)
        {
            break;
        }

        switch(choice)
        {
            case 1:
            {
                printf("Enter string: ");
                scanf("%[^\n]", str1);

                int (*fp)(char *);
                fp = (int (*)(char *)) dlsym(strHandle, "MyStrlen");

                iRet = fp(str1);
                printf("Length: %d\n", iRet);
                break;
            }

            case 2:
            {
                printf("Enter source string: ");
                scanf("%[^\n]", str1);
                getchar();

                char *(*fp)(char *, char *);
                fp = (char *(*)(char *, char *)) dlsym(strHandle, "MyStrcpy");

                fp(str2, str1);
                printf("Copied String: %s\n", str2);
                break;
            }

            case 3:
            {
                printf("Enter source string: ");
                scanf("%[^\n]", str1);
                getchar();
                
                printf("Enter the size uptil copy : ");
                scanf("%d", &Size);

                char *(*fp)(char *, char *, int);
                fp = (char *(*)(char *, char *, int)) dlsym(strHandle, "MyStrncpy");

                fp(str2, str1, Size);
                printf("Copied String: %s\n", str2);
                break;
            }

            case 4:
            {
                printf("Enter first string: ");
                scanf("%[^\n]", str1);
                getchar();

                printf("Enter second string: ");
                scanf("%[^\n]", str2);

                char *(*fp)(char *, char *);
                fp = (char *(*)(char *, char *)) dlsym(strHandle, "MyStrcat");

                fp(str1, str2);
                printf("Concatenated: %s\n", str1);
                break;
            }

            case 5:
            {
                printf("Enter first string: ");
                scanf("%[^\n]", str1);
                getchar();

                printf("Enter second string: ");
                scanf("%[^\n]", str2);

                bool (*fp)(char *, char *);
                fp = (bool (*)(char *, char *)) dlsym(strHandle, "MyStrcmp");

                if(fp(str1, str2))
                    printf("Strings are equal\n");
                else
                    printf("Strings are not equal\n");
                break;
            }

            case 6:
            {
                printf("Enter first string: ");
                scanf(" %[^\n]", str1);

                printf("Enter second string: ");
                scanf(" %[^\n]", str2);

                printf("Enter number of characters: ");
                scanf("%d", &Size);

                bool (*fp)(char *, char *, int);
                fp = (bool (*)(char *, char *, int)) dlsym(strHandle, "MyStrncmp");

                if(fp(str1, str2, Size))
                {
                    printf("First %d characters are equal\n", Size);
                }
                else
                {
                    printf("Not equal\n");
                }

                break;
            }

            case 7:
            {
                printf("Enter string: ");
                scanf(" %[^\n]", str1);

                char *(*fp)(char *);
                fp = (char *(*)(char *)) dlsym(strHandle, "MyStrrev");

                fp(str1);
                printf("Reversed string: %s\n", str1);

                break;
            }

            case 8:
            {
                printf("Enter main string: ");
                scanf(" %[^\n]", str1);

                printf("Enter substring: ");
                scanf(" %[^\n]", str2);

                char *(*fp)(char *, char *);
                fp = (char *(*)(char *, char *)) dlsym(strHandle, "MyStrstr");

                char *result = fp(str1, str2);

                if(result != NULL)
                    printf("Substring found at position: %ld\n", result - str1);
                else
                    printf("Substring not found\n");

                break;
            }

            case 9:
            {
                printf("Enter two numbers: ");
                scanf("%d%d", &no1, &no2);

                int (*fp)(int, int);
                fp = (int (*)(int,int)) dlsym(mathHandle, "MyMax");

                printf("Max: %d\n", fp(no1, no2));
                break;
            }

            case 10:
            {
                printf("Enter two numbers: ");
                scanf("%d%d", &no1, &no2);

                int (*fp)(int, int);
                fp = (int (*)(int,int)) dlsym(mathHandle, "MyMin");

                printf("Min: %d\n", fp(no1, no2));
                break;
            }

            case 11:
            {
                printf("Enter number: ");
                scanf("%d", &no1);

                int (*fp)(int);
                fp = (int (*)(int)) dlsym(mathHandle, "MyFactorial");

                printf("Factorial: %d\n", fp(no1));
                break;
            }

            case 12:
            {
                printf("Enter number: ");
                scanf("%d", &no1);

                int (*fp)(int);
                fp = (int (*)(int)) dlsym(mathHandle, "MyAbs");

                if(fp == NULL)
                {
                    printf("Error: %s\n", dlerror());
                    break;
                }

                printf("Absolute value: %d\n", fp(no1));
                break;
            }

            case 13:
            {
                printf("Enter base and exponent: ");
                scanf("%d%d", &no1, &no2);

                int (*fp)(int, int);
                fp = (int (*)(int,int)) dlsym(mathHandle, "MyPow");

                printf("Power: %d\n", fp(no1, no2));
                break;
            }

            case 14:
            {
                printf("Enter number: ");
                scanf("%d", &no1);

                int (*fp)(int);
                fp = (int (*)(int)) dlsym(mathHandle, "MySqrt");

                if(fp == NULL)
                {
                    printf("Error: %s\n", dlerror());
                    break;
                }

                int result = fp(no1);

                if(result == -1)
                    printf("Square root not defined for negative numbers\n");
                else
                    printf("Square root (integer): %d\n", result);

                break;
            }

            case 15:
            {
                printf("Enter two numbers: ");
                scanf("%d%d", &no1, &no2);

                int (*fp)(int, int);
                fp = (int (*)(int,int)) dlsym(mathHandle, "MyGCD");

                printf("GCD: %d\n", fp(no1, no2));
                break;
            }

            case 16:
            {
                printf("Enter two numbers: ");
                scanf("%d%d", &no1, &no2);

                int (*fp)(int, int);
                fp = (int (*)(int,int)) dlsym(mathHandle, "MyLCM");

                printf("LCM: %d\n", fp(no1, no2));
                break;
            }

            default:
                printf("Invalid choice\n");
        }        
    }

    dlclose(strHandle);
    dlclose(mathHandle);
    
    return 0;
}

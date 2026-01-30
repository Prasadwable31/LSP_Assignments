#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include <string.h>

int main()
{
    char dirname[10];
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    
    printf("Enter the directory name to open : ");
    scanf("%s",dirname);

    dp = opendir(dirname);

    while(ptr = readdir(dp))
    {
        if(*ptr->d_name != '.')
        {   
            printf("Name of File : %s\n",ptr->d_name);       
            printf("Inode of File : %ld\n",ptr->d_ino);
        }
    }

    return 0;
}   
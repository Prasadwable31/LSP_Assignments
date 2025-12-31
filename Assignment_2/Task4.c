#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include <string.h>
#include<sys/stat.h>

int main()
{
    char dirname[10];
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat obj;
    
    printf("Enter the directory name to open : ");
    scanf("%s",dirname);

    dp = opendir(dirname);

    while(ptr = readdir(dp))
    { 
        printf("Name of File : %s\n",ptr->d_name);       
        printf("Inode of File : %ld\n",ptr->d_ino);

        stat(ptr->d_name, &obj);

        printf("File Type : ");
        if(S_ISREG(obj.st_mode))
        {
            printf("Regular File\n");
        }
        else if(S_ISCHR(obj.st_mode))
        {
            printf("Character File\n");
        }
        else if(S_ISDIR(obj.st_mode))
        {
            printf("Directory File\n");
        }
        else if(S_ISLNK(obj.st_mode))
        {
            printf("Symbolic Link\n");
        }
        else if(S_ISFIFO(obj.st_mode))
        {
            printf("FIFO Pipe\n");
        }
        else if(S_ISBLK(obj.st_mode))
        {
            printf("Block Device\n");
        }
        else if(S_ISSOCK(obj.st_mode))
        {
            printf("Socket\n");
        }

        printf("\n\n");
    }

    return 0;
}   
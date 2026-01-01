#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>

int main()
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char DirName[20];
    char FileName[20];
    char Buffer[100];

    memset(Buffer, '\0', sizeof(Buffer));

    printf("Enter the name of Directory : ");
    scanf("%s",DirName);

    printf("Enter the name of file : ");
    scanf("%s",FileName);

    dp = opendir(DirName);

    while(ptr = readdir(dp))
    {
        if(strcmp(ptr->d_name, FileName) == 0)
        {
            printf("File Exist in Directory\n");
            chdir(DirName);
            break;  
        }
    }
    
    getcwd(Buffer, sizeof(Buffer));
    printf("Absolute Path of File is : %s/%s\n",Buffer, FileName);

    printf("%s\n",strerror(errno));
    
    return 0;
}
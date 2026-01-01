#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>

int main()
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat obj;
    char DirName[20];
    char FilePath[50];
    int iCount = 0;

    printf("Enter the name of source Directory : ");
    scanf("%s", DirName);

    dp = opendir(DirName);

    printf("Name of file deleted : \n");
    while(ptr = readdir(dp))
    {
        snprintf(FilePath, sizeof(FilePath),"./%s/%s", DirName, ptr->d_name);

        stat(FilePath, &obj);

        if(obj.st_size == 0)
        {
            if(S_ISREG(obj.st_mode))
            {
                printf("%s\n",ptr->d_name);
                unlink(FilePath);
                iCount++;
            }
        }
    }

    printf("Number of file deleted : %d\n", iCount);
    
    return 0;
}
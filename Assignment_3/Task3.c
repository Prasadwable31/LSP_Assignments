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
    char SrcDir[20];
    char DestDir[20];
    char Srcname[50];
    char Destname[50];
    int iCount = 0;

    printf("Enter the name of source Directory : ");
    scanf("%s",SrcDir);

    printf("Enter the name of destination Directory : ");
    scanf("%s",DestDir);

    dp = opendir(SrcDir);

    while(ptr = readdir(dp))
    {
        stat(ptr->d_name, &obj);

        snprintf(Srcname, sizeof(Srcname), "./%s/%s", SrcDir, ptr->d_name);
        snprintf(Destname, sizeof(Destname), "./%s/%s", DestDir, ptr->d_name);

        if(S_ISREG(obj.st_mode))
        {
            rename(Srcname, Destname);
            iCount++;
        }
    }

    printf("Number of file moved : %d\n", iCount);
    
    return 0;
}
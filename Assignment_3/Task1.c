#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFERSIZE 1024

int main()
{
    char SrcFile[20];
    char DestFile[20];
    int fd1 = 0, fd2 = 0, iRet = 0;
    char Buffer[BUFFERSIZE];

    memset(Buffer, '\0', BUFFERSIZE);

    printf("Enter the name of source file : ");
    scanf("%s",SrcFile);

    printf("Enter the name of destination file : ");
    scanf("%s",DestFile);

    fd1 = open(SrcFile, O_RDONLY);

    if(fd1 == -1)
    {
        printf("Unable to Open Source File");
        return -1;
    }

    fd2 = open(DestFile, O_WRONLY | O_TRUNC | O_CREAT, 0777);

    if(fd2 == -1)
    {
        printf("Unable to open Destination File");
        return -1;
    }

    while((iRet = read(fd1, Buffer, BUFFERSIZE)) != 0)
    {
        write(fd2, Buffer, iRet);
        memset(Buffer, '\0', BUFFERSIZE);
    }
    
    return 0;
}
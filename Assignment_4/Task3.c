#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#define BUFFSIZE 1024

int main(int argc, char const *argv[])
{
    int fd1 = 0, fd2 = 0;
    int iRet = 0;
    char Buffer[BUFFSIZE];
    int Size = 0;

    if(argc != 2)
    {
        printf("Please give the valid command line arguments\n");
        return -1;
    }

    memset(Buffer, '\0', BUFFSIZE);

    fd1 = open(argv[1], O_RDONLY);

    if(fd1 == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }
    
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if(fd2 == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    while((iRet = pread(fd1, Buffer, BUFFSIZE, Size)) != 0)
    {
        pwrite(fd2, Buffer, iRet, Size);
        Size = Size + iRet;
        
        memset(Buffer, '\0', BUFFSIZE);
    }
    
    printf("File Contents Successfully Copy\n");
    
    return 0;
}

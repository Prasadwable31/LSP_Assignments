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
    int iCnt = 0;

    if(argc != 2)
    {
        printf("Please give the valid command line arguments\n");
        return -1;
    }

    if(argc < 2)
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

    while((iRet = read(fd1, Buffer, BUFFSIZE)) != 0)
    {
        for(iCnt = iRet; iCnt >= 0; iCnt--)
        {
            printf("%c",Buffer[iCnt]);
        }

        memset(Buffer, '\0', BUFFSIZE);
    }
    
    return 0;
}

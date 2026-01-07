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

    if(argc < 2)
    {
        printf("Please give the valid command line arguments\n");
        return -1;
    }

    memset(Buffer, '\0', BUFFSIZE);
    
    fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if(fd1 == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }
    
    for(iCnt = 2; iCnt < argc; iCnt++)
    {
        fd2 = open(argv[iCnt], O_RDONLY);

        if(fd2 == -1)
        {
            printf("%s\n", strerror(errno));
            continue;
        }

        while((iRet = read(fd2, Buffer, BUFFSIZE)) != 0)
        {
            write(fd1, Buffer, iRet);

            memset(Buffer, '\0', BUFFSIZE);
        }
    }
    
    printf("Multiple Files Successfully Copied\n");
    
    return 0;
}

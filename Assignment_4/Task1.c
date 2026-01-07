#include<stdio.h>
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

    if(argc != 3)
    {
        printf("Please give the valid command line arguments\n");
        return -1;
    }

    fd1 = open(argv[1], O_RDONLY);

    if(fd1 == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }
    
    fd2 = open(argv[2], O_WRONLY | O_CREAT, 0777);

    if(fd2 == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    while((iRet = read(fd1, Buffer, BUFFSIZE)) != 0)
    {
        write(fd2, Buffer, iRet);
        memset(Buffer, '\0', BUFFSIZE);
    }
    
    printf("File Contents Successfully Copy\n");
    
    return 0;
}

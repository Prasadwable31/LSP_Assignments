#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0, iRet = 0;
    char name[10];
    char Buffer[1024];

    printf("Enter the file name to open : ");
    scanf("%s",name);

    printf("Enter the string that you want to write : ");
    scanf("\n%[^\n]s",Buffer);

    fd = open(name, O_WRONLY | O_APPEND);

    if(fd == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    iRet = write(fd, Buffer, strlen(Buffer));                                                                           

    printf("%d Bytes gets successfully written in file\n", iRet);

    return 0;
}   
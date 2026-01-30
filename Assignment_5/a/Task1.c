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
    int iCount = 0;

    memset(Buffer, '\0', sizeof(Buffer));

    printf("Enter the file name to open : ");
    scanf("%s",name);

    fd = open(name, O_RDONLY);

    if(fd == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    printf("Data form file is : \n");
    while((iRet = read(fd, Buffer, 10)) != 0)
    {
        printf("%s", Buffer);
        memset(Buffer, '\0', sizeof(Buffer));
        iCount = iCount + iRet;
    }

    printf("\nTotal Bytes read are : %d\n", iCount);

    return 0;
}   
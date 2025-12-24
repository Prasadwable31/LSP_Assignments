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
    int bytes = 0;

    memset(Buffer, '\0', sizeof(Buffer));

    printf("Enter the file name to open : ");
    scanf("%s",name);   

    printf("Enter the number of bytes want to read : ");
    scanf("%d",&bytes);

    fd = open(name, O_RDONLY);

    if(fd == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    else
    {
        printf("File Successfully opened with fd : %d\n",fd);
        printf("%s\n",strerror(errno));
    }

    iRet = read(fd, Buffer, bytes);

    printf("Data form file is : %s\n", Buffer);

    return 0;
}
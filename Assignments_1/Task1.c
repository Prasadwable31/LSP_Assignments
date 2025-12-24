#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0;
    char name[10];

    memset(name, '\0', sizeof(name));

    printf("Enter the file name to open : ");
    scanf("%s",name);   

    fd = open(name, O_RDWR);

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

    return 0;
}
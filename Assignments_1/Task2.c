#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char mode[10];
    int flag = 0;

    memset(mode, '\0', sizeof(mode));

    printf("Enter the file mode in which want to open : ");
    scanf("%s",mode);

    if(strcmp(mode, "R") == 0)
    {
        flag = O_RDONLY;
    }
    else if(strcmp(mode, "W") == 0)
    {
        flag = O_WRONLY;
    }
    else if(strcmp(mode, "WR") == 0)
    {
        flag = O_RDWR;
    }
    else if(strcmp(mode, "A") == 0)
    {
        flag = O_APPEND;
    }
    
    fd = open(argv[1], flag | O_CREAT, 0777);

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
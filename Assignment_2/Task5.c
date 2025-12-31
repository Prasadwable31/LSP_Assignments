#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <unistd.h> 
#include<fcntl.h>

int main()
{
    DIR *dp = NULL;
    char dirname[20];
    struct dirent *ptr = NULL;
    int Size = 0;
    struct stat obj;
    char *name = NULL;

    printf("Enter the directory name to open : ");
    scanf("%s",dirname);

    dp = opendir(dirname);

    if(dp != NULL)
    {
        chdir(dirname);
    }

    while(ptr = readdir(dp))
    {
        stat(ptr->d_name, &obj);

        if(S_ISREG(obj.st_mode) && obj.st_size > Size)
        {
            Size = obj.st_size;
            name = ptr->d_name;
        }
    }
    
    printf("Largest File Size is : %s\n",name);
    printf("Largest File Size is : %d\n",Size);

    return 0;
}
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char argv[])
{
    struct stat obj;
    int iRet = 0;
    char name[20];

    printf("Enter the name of file : ");
    scanf("%s",name);

    iRet = stat(name, &obj);

    printf("Inode number : %ld\n", obj.st_ino);
    printf("Number of hard links : %ld\n", obj.st_nlink);
    printf("User ID of owner : %d\n", obj.st_uid);
    printf("Group ID of owner : %d\n", obj.st_gid);
    printf("Total size of File : %ld\n", obj.st_size);
    printf("Block size for filesystem : %ld\n", obj.st_blksize);
    printf("Time of last access : %s\n", ctime(&obj.st_atime));
    printf("Time of last modification : %s\n", ctime(&obj.st_mtime));

    if(S_ISREG(obj.st_mode))
    {
        printf("Regular Filen\n");
    }
    else if(S_ISCHR(obj.st_mode))
    {
        printf("Character File\n");
    }
    else if (S_ISDIR(obj.st_mode))
    {
        printf("Directory File\n");
    }
    
    return 0;
}
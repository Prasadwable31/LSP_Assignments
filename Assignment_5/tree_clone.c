#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

void Dispaly(char *name)
{
    struct stat obj;
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char Path[255];
    int iCnt = 0;
    static int level = 0;

    dp = opendir(name);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return;
    }

    while(ptr = readdir(dp))
    {
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        {
            continue;
        }

        snprintf(Path, sizeof(Path), "%s/%s", name, ptr->d_name);
        
        lstat(Path, &obj);

        for(iCnt = 0; iCnt < level; iCnt++)
        {
            printf("    ");
        }
    
        if(S_ISDIR(obj.st_mode))
        {
            printf("%s   D\n", ptr->d_name);

            level++;
            Dispaly(Path);
            level--;
        }

        else if(S_ISREG(obj.st_mode))
        {
            printf("%s   F\n", ptr->d_name);
        }

        else if(S_ISLNK(obj.st_mode))
        {
            printf("%s   L\n", ptr->d_name);
        }
    }

    closedir(dp);
}

int main()
{
    char dirname[255];

    printf("Enter the name of Directory : ");
    scanf("%s",dirname);
    
    Dispaly(dirname);

    return 0;
}
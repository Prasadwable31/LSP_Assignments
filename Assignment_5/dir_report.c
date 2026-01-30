#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

static int CountFiles = 0;
static int CountDirectories = 0;
static int TotalSize = 0;
static int Size = 0;

void Dispaly(char *name)
{
    struct stat obj;
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char Path[255];
    
    dp = opendir(name);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return;
    }

    while(ptr = readdir(dp))
    {
        snprintf(Path, sizeof(Path), "%s/%s", name, ptr->d_name);
        
        lstat(Path, &obj);

        if(*ptr->d_name == '.')
        {
            CountDirectories++;
            continue;
        }
    
        if(S_ISDIR(obj.st_mode))
        {
            CountDirectories++;

            Dispaly(Path);
        }
        else
        {
            CountFiles++;
            TotalSize = TotalSize + obj.st_size;

            if(Size < obj.st_size)
            {
                Size = obj.st_size;
            }
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

    printf("Total Files : %d\n", CountFiles);
    printf("Total Directories : %d\n", CountDirectories);
    printf("Total Size : %d\n", TotalSize);
    printf("Largest File Size : %d\n", Size);

    return 0;
}
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
    struct stat obj;
    char dirname[255];
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char name[255];

    printf("Enter the name of Directory : ");
    scanf("%s",dirname);

    dp = opendir(dirname);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while(ptr = readdir(dp))
    {
        snprintf(name, sizeof(name), "./%s/%s", dirname, ptr->d_name);

        stat(name, &obj);

        if(*ptr->d_name != '.')
        {
            // Entry Name
            printf("Name of file : %s\n", ptr->d_name);
            
            // File Type

            printf("File Type : ");
            if(S_ISCHR(obj.st_mode))
            {
                printf("Character File\n");
            }
            else if(S_ISDIR(obj.st_mode))
            {
                printf("Directory File\n");
            }
            else if(S_ISFIFO(obj.st_mode))
            {
                printf("FIFO / Pipe File\n");
            }
            else if(S_ISLNK(obj.st_mode))
            {
                printf("Symbolic Link\n");
            }
            else if(S_ISREG(obj.st_mode))
            {
                printf("Regular File\n");
            }
            else if(S_ISBLK(obj.st_mode))
            {
                printf("Block File\n");
            }

            
            // owner permissions

            printf("Permisssions : ");
            if((obj.st_mode) & S_IRUSR)
            {   printf("r");          }
            else{   printf("-");      }
            if((obj.st_mode) & S_IWUSR)
            {   printf("w");          }
            else{   printf("-");      }
            if((obj.st_mode) & S_IXUSR)
            {   printf("x");          }
            else{   printf("-");      }

            // group permissions

            if((obj.st_mode) & S_IRGRP)
            {   printf("r");          }
            else{   printf("-");      }
            if((obj.st_mode) & S_IWGRP)
            {   printf("w");          }
            else{   printf("-");      }
            if((obj.st_mode) & S_IXGRP)
            {   printf("x");          }
            else{   printf("-");      }

            // others permissions
            
            if((obj.st_mode) & S_IROTH)
            {   printf("r");          }
            else{   printf("-");      }
            if((obj.st_mode) & S_IWOTH)
            {   printf("w");              }
            else{   printf("-");      }
            if((obj.st_mode) & S_IXOTH)
            {   printf("x");          }
            else{   printf("-");      }
            
            printf("\n");

            // Size of File
            printf("Size in Bytes : %ld\n",obj.st_size);

            // modification time
            printf("last modification time : %s",ctime(&obj.st_atime));
    
            // Absolute path
            getcwd(name, sizeof(name));
            printf("Absolute Path of File : %s/%s/%s\n", name, dirname, ptr->d_name);
            
            printf("\n\n");
        }
    }

    return 0;
}

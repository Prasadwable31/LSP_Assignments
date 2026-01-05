#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main()
{
    char name[20];
    char ch;
    int mode;
    int iRet = 0;

    printf("Enter the name of file : ");
    scanf("%s",name);

    printf("Enter the mode of file (R, W, X) : ");
    scanf(" %c",&ch);
    
    if (ch == 'R')
        mode = R_OK;
    else if (ch == 'W')
        mode = W_OK;
    else if (ch == 'X')
        mode = X_OK;
    else
        printf("Invalid Mode Entered!\n");
        return -1;

    iRet = access(name, mode);

    if(iRet == -1)
    {
        printf("ERROR : %s\n",strerror(errno));
    }
    else
    {
        printf("File is Accessibility\n");
        printf("%s\n",strerror(errno));
    }

    return 0;
}

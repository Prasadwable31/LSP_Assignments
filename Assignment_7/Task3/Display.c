#include<stdio.h>

void Display(char *str)
{
    int iCount = 0;

    while(*str != '\0')
    {   
        printf("%c", *str);
        
        if(*str != ' ')
        {
            iCount++;
        }

        str++;
    }
    
    printf("\nThe Number of Character : %d\n", iCount);
}
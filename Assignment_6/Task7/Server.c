#include<stdio.h>

int iNo = 0;    

void modify()
{
    printf("Enter the value of : ");
    scanf("%d",&iNo);
}

void Display()
{
    printf("The Value of iNo : %d\n", iNo);
}

void Reset()
{
    iNo = 0;
}
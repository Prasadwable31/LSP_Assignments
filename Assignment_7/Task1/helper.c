#include "helper.h"

int SumOfFactor(int No)
{
    int iSum = 0;

    for(int i = 1; i <= (No/2); i++)
    {
        if(No % i == 0)
        {
            iSum += i;
        }
    }

    return iSum;
}

int IsFactor(int No, int i)
{
    if(i == 0)
    {
        return 0;
    }

    return (No % i) == 0;
}
#include "mymath.h"

int MyMax(int iNo1, int iNo2)
{
    if(iNo1 >= iNo2)
    {
        return iNo1;
    }
    else
    {
        return iNo2;
    }
}

int MyMin(int iNo1, int iNo2)
{
    if(iNo1 >= iNo2)
    {
        return iNo2;
    }
    else
    {
        return iNo1;
    }
}

int MyFactorial(int iNo1)
{
    if(iNo1 < 0)
    {
        return -1;
    }

    int Fact = 1;

    for(int i = 1; i <= iNo1; i++)
    {
        Fact = Fact * i;
    }

    return Fact;
}

int MyAbs(int iNo1)
{
    if(iNo1 < 0)
    {
        return -iNo1;
    }

    return iNo1;
}

int MyPow(int base, int exp)
{
    if(exp < 0)
    {
        return -1;   
    }

    int Ans = 1;

    for(int i = 1; i <= exp; i++)
    {
        Ans = Ans * base;
    }

    return Ans;
}

int MySqrt(int iNo)
{
    if(iNo < 0)
    {
        return -1;
    }

    int i = 0;

    while(i * i <= iNo)
    {
        i++;
    }

    return i - 1;
}

int MyGCD(int iNo1, int iNo2)
{
    if(iNo1 < 0) 
    {
        iNo1 = -iNo1;
    }

    if(iNo2 < 0) 
    {
        iNo2 = -iNo2;
    }

    while(iNo2 != 0)
    {
        int temp = iNo2;
        iNo2 = iNo1 % iNo2;
        iNo1 = temp;
    }

    return iNo1;
}

int MyLCM(int a, int b)
{
    if(a == 0 || b == 0)
    {
        return 0;
    }

    int gcd = MyGCD(a, b);

    return (a / gcd) * b;
}

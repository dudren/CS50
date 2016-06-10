#include <cs50.h>
#include <stdio.h>

long long reverseNum(n)
{
    long long rn = 0;
    int r;
    
    while (n != 0)
    {
        r = n % 10;
        rn = rn * 10 + r;
        n /= 10;
    }
    
    return rn;
}

int main(void)
{
    long long cardNum;
    long long revCardNum;
    
    //get the CC Number from user and store in cardNum:
    printf ("Enter your Credit Card number: ");
    cardNum = GetLongLong();
    
    if (cardNum < 1000000000000 || cardNum > 9999999999999999)
        printf ("INVALID\n");
    
    if (cardNum > 9999999999999 && cardNum < 100000000000000)
        printf ("INVALID\n");
    
    if (cardNum > 99999999999999 && cardNum < 1000000000000000)
    {
        int first2Amex;
        first2Amex = cardNum / 10000000000000;
        
        if (cardNum == 34 || cardNum == 37)
            revCardNum = reverseNum(cardNum);
            
        else
            printf("INVALID\n");
    }
    
}
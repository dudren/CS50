#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int sum = 0;
    int initialNum;
    printf ("What number would you like to start with?\n");
    initialNum = GetInt();
    
    for (int i = 0, n = initialNum; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    printf("The sum of the multiples of 3 and 5 below %i is %i\n", initialNum, sum);
}
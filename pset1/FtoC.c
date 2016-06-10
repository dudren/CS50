#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int F = 27;
    int C = 0;
    C = (F - 32) / 1.8;
    printf ("%iF is equal to %iC\n",F ,C);
}
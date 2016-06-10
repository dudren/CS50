#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float result;
    result = (3.31e-8 * 2.01e-7) / (7.16e-6 + 2.01e-8);
    printf ("The result is %e\n", result);
}

check50 2015.fall.pset1.water water.c
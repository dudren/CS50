#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int containsNumbers(char* keyword);

int main(void)
{
    if (containsNumbers("J1oe") == 1)
        printf("True.\n");
    else
        printf("False.\n");
}


int containsNumbers(char* keyword)
{
    int x = 0;
        for (int i = 0, n = strlen(keyword); i < n; i++)
        {
            int c = keyword[i];
            if (isdigit(c) != 0)
                x = 1;
        }
    return x;
}
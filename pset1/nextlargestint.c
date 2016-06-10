#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int next_multiple;
    int i;
    int j;
    
    printf("What is i?\n");
    i = GetInt();
    
    printf("What is j?\n");
    j = GetInt();
    
    next_multiple = i + j - (i % j);
    
    printf ("The next even multple of j is %i\n", next_multiple);
    
    return 0 ;
}
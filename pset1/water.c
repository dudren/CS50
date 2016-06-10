#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How many minutes do you shower? ");
    int minutes = GetInt();
    
    while (minutes <= 0)
    {
      printf("Please give me a positive integer: ");
      minutes = GetInt();
    }
    
    int bottles = 0;
    bottles = (minutes * 192) / 16;
    
    printf("bottles: %d \n", bottles);
}
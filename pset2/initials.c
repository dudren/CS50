#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //sets space to 32 so we dont use magic number
    
    //asks user for name and stores in string
    printf("What is your name?\n");
    char* name = GetString();
    
    //prints first letter in uppercase
    printf("%c", toupper(name[0]));
    
    //loops through each letter in the string
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        //dont use magic numbers
        int space = 32;
        
        //if the char is a space, go to next letter and print in uppercase
        if (name[i] == space)
        {
            char initial = name[i + 1];
            printf("%c", toupper(initial));
        }
    }
    printf("\n");
}
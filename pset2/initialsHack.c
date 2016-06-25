#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool space(char letter);
bool capital(char letter);
bool lowerCase(char letter);

int main(void)
{
    //asks user for name and stores in string
    printf("What is your name?\n");
    char* name = GetString();
    
    //loops through each letter in the string
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        char initial;
        //if the char is a space, go to next letter and print in uppercase
        if (space(name[i]) == 1 && (capital(name[i + 1]) == 1 || lowerCase(name[i + 1]) == 1))
        {
            initial = name[i + 1];
            printf("%c", toupper(initial));
        }
    }
    printf("\n");
}

bool space(char letter)
{
    if (letter == 32)
        return 1;
    else 
        return 0;
}

bool capital(char letter)
{
    if (letter > 64 && letter < 91)
        return 1;
    else 
        return 0;
}

bool lowerCase(char letter)
{
    if (letter > 96 && letter < 123)
        return 1;
    else 
        return 0;
}
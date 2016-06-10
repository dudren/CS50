#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int shift(int alpha, int key);
bool capital(char letter);
bool lowerCase(char letter);

int main(int argc, char* argv[])
{
    //key is changed to integer
    int k = atoi(argv[1]);
    //stops the program if there are no command line arguments
    if (argc != 2 || k < 0)
    {
        printf("You must enter an argument and it must be a positive integer.\n");
        return 1;
    }
    
    else
    {
        printf("Enter a string you would like to encrypt with Caesar's cipher: \n");
        //gets the string from the user that we would like to encrypt
        char* s = GetString();
        char cipher;
        int result;
        
        //loops through each char of the string
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            //if the char is capital, it changes it to alpha and runs the cipher then converts back to ascii
            if (capital(s[i]) == 1)
            {
                int alphaCap = s[i] - 65;
                cipher = shift(alphaCap, k);
                result = cipher + 65;
            }
            
            //if the char is lowercase, it changes it to alpha and runs the cipher then converts back to ascii
            else if (lowerCase(s[i]) == 1)
            {
                int alphaLow = s[i] - 97; 
                cipher = shift(alphaLow, k);
                result = cipher + 97;
            }
            //if the char is neither cap or lowercase, it stays the same
            else
                result = s[i];
            //prints the ciphered char before moving on to next char
            printf("%c", result);
        }
        printf("\n");
        return 0;
    }
}


//runs the shift cipher C = (Pi = k) % 26
int shift(int alpha, int key)
{
    int newAlpha;
    newAlpha = (alpha + key) % 26;
    return newAlpha;
}

//determines if char is capital
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
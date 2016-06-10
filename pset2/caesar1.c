#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int cipher(int alpha, int key);
bool capital(char letter);
bool lowerCase(char letter);
char toAlpha(char asciiChar);
char toAscii(char alphaChar);

int main(int argc, char* argv[])
{
    //stops the program if there are no command line arguments
    if (argc != 2)
    {
        printf("You must enter an argument.\n");
        return 1;
    }
    
    else
    {
        //key is changed to integer
        int k = atoi(argv[1]);
        printf("Enter a string you would like to encrypt with Caesar's cipher: \n");
        //gets the string from the user that we would like to encrypt
        char* s = GetString();
        char cipheredNum;
        int result;
        
        //loops through each char of the string
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            //if the char is a capital or lowercase letter
            if (capital(s[i]) == 1 || lowerCase(s[i]) == 1)
            {
                //change to alphanumeric value, run the cipher, then change back to ascii
                int alphaNum = toAlpha(s[i]);
                cipheredNum = cipher(alphaNum, k);
                result = toAscii(cipheredNum);
            }
            //if the char is neither capital or lowercase, it stays the same
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
int cipher(int alphaNum, int key)
{
    int shiftedNum;
    shiftedNum = (alphaNum + key) % 26;
    return shiftedNum;
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

//changes alphabetical char from ascii to alpha number
char toAlpha(char asciiChar)
{
    int alphaNum = asciiChar;
    if(capital(asciiChar) == 1)
        alphaNum -= 65;
    if(lowerCase(asciiChar) == 1)
        alphaNum -= 97;
    return alphaNum;
}

//changes alphabetical char from alpha to ascii number
char toAscii(char alphaChar)
{
    int asciiChar = alphaChar;
    if(capital(alphaChar) == 1)
        asciiChar += 65;
    if(lowerCase(alphaChar) == 1)
        asciiChar += 97;
    return asciiChar;
}
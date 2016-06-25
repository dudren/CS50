#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int shift(int alpha, int key);
bool capital(char letter);
bool lowerCase(char letter);
int containsNumbers(char* keyword);

int main(int argc, char* argv[])
{
    //keyword is stored in string
    char* keyword = (argv[1]);
    int key;
    //stops the program if there are no command line arguments
    if (argc != 2)
    {
        printf("You must enter an argument.\n");
        return 1;
    }
    
    else if (containsNumbers(keyword) == 1)
    {
        printf("Argument must contain only alphabetical characters.\n");
        return 1;
    }
    else
    {
        //printf("Enter a string you would like to encrypt with Vigenere's cipher: \n");
        //gets the string from the user that we would like to encrypt
        char* plainText = GetString();
        char cipher;
        int result;
        //set j to zero to start at first char in "keyword"
        int j = 0;
        //loops through each char of the plaintext string
        for (int i = 0, n = strlen(plainText); i < n; i++)
        {
            //to find the alphabetical key if char in "keyword" is lowercase or capital:
            if (capital(keyword[j]) == 1)
                key = (keyword[j] - 65);
            if (lowerCase(keyword[j]) == 1)
                key = (keyword[j] - 97);
           //printf("%i", key);
            //if the char in plaintext is capital, it changes it to alpha number and runs the cipher then converts back to ascii
            if (capital(plainText[i]) == 1)
            {
                int alpha = plainText[i] - 65;
                cipher = shift(alpha, key);
                result = cipher + 65;
                //and then changes to the next char in "keyword"
                j++;
                j %= (strlen(keyword));
            }
            
            //if the char in plaintext is lowercase, it changes it to alpha number and runs the cipher then converts back to ascii
            else if (lowerCase(plainText[i]) == 1)
            {
                int alpha = plainText[i] - 97; 
                cipher = shift(alpha, key);
                result = cipher + 97;
                //and then changes to the next char in "keyword"
                j++;
                j %= (strlen(keyword));
            }
            //if the char is neither cap or lowercase, it stays the same
            else
                result = plainText[i];
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


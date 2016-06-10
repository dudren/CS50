#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int cipher(int alpha, int key);
bool capital(char letter);
bool lowerCase(char letter);
int toAlpha(int asciiChar);
int toAscii(int alphaChar);

int main(void)
{
    //char result;
    //char cipheredNum;
    char a = 'a';
    char alphaNum = toAlpha(a);
    //cipheredNum = cipher(alphaNum, 1);
    //result = toAscii(cipheredNum);
    printf("%c", alphaNum);
}

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
int toAlpha(int asciiChar)
{
    int alphaNum = asciiChar;
    if(capital(asciiChar) == 1)
        alphaNum -= 65;
    if(lowerCase(asciiChar) == 1)
        alphaNum -= 97;
    return alphaNum;
}

//changes alphabetical char from alpha to ascii number
int toAscii(int alphaChar)
{
    int asciiChar = alphaChar;
    if(capital(alphaChar) == 1)
        asciiChar += 65;
    if(lowerCase(alphaChar) == 1)
        asciiChar += 97;
    return asciiChar;
}
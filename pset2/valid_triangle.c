#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float a, float b, float c);

int main(void)
{
    //asks user for input and sets each side to a var
    printf("We are going to determine if your triangle is valid.\n");
    printf("Please enter the length of side A: ");
    int sideA = GetInt();
    printf("Please enter the length of side B: ");
    int sideB = GetInt();
    printf("Please enter the length of side C: ");
    int sideC = GetInt();
   
   //sets the result of valid_triangle function to a var 
    bool result = valid_triangle(sideA, sideB, sideC);
    
    //if true prints valid, if false, prints invalid
    if (result == 1)
        printf("valid\n");
    else
        printf("invalid\n");
}

bool valid_triangle(float a, float b, float c)
{
    if (a > 0 && b > 0 && c > 0)
        {
            if ((a + b) > c && (a + c) > b && (b + c) > a)
                return true;
            else 
                return false;
        }
    else
        return false;
}
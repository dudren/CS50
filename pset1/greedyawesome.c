#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int coins = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    
    do 
    {
        printf ("Enter change owed: ");
        change = GetFloat();
    }
    while (change < 0);
    
    {
        int newchange;
        newchange = (change * 100);
        
        int cents;
        cents = newchange % 100;
        
        while (cents >= 25)
        {
            coins += 1;
            quarters += 1;
            cents -= 25;
        }
        
        while (cents >= 10)
        {
            coins += 1;
            dimes += 1;
            cents -= 10;
        }
        
        while (cents >= 5)
        {
            coins += 1;
            nickels += 1;
            cents -= 5;
        }
        
        while (cents >= 1)
        {
            coins += 1;
            pennies += 1;
            cents -= 1;
        }
        
    }
    printf ("Minumum number coins back: %i\n", coins);
    printf ("Quarters: %i\n", quarters);
    printf ("Nickels: %i\n", nickels);
    printf ("Dimes: %i\n", dimes);
    printf ("Pennies: %i\n", pennies);
}
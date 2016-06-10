#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    //ask the user to pick the height until it is between 1 and 23
    do
    {
    printf ("Enter a height between 1 and 23?\n");
    height = GetInt();
    }
    while (height < 1 || height > 23);
    //when it is between 1 and 23 run this:
    {
        //determines the amount of rows
        for (int i = 0; i < height; i++)
        {
            //writes spaces until height - row + 1
            for (int j = 1; j < (height - i); j++)
            {
                printf (" ");
            }
            
            //writes 2 + row hashes per line
            for (int k = 0; k < (1 + i); k++)
            {
                printf ("#");
            }
            
            for (int l = 0; l < 2; l++)
            {
                printf ("  ");
            }
            
            for (int k = 0; k < (1 + i); k++)
            {
                printf ("#");
            }
            //newline and go to next row
            printf ("\n");
        }
    }
   
}
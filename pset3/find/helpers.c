/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int start, mid, end;
    start = 0;
    end = n - 1;
    mid = n / 2;
    while (start <= end)
    {
        if (values[mid] == value)
            return true;
        else if (values[mid] > value)
        {
            end = mid - 1;
        }
        else if (values[mid] < value)
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return false;
}

/**
 * Sorts array of n values using bubble sort
 */
void sort(int values[], int n)
{
    int swapCount = 1;
    while (swapCount != 0)
    {
        swapCount = 0;
        for (int i = 0; i < (n - 1); i++)
        {
            if (values[i] > values[i + 1])
            {
                int temp = values[i + 1];
                values[i + 1] = values[i];
                values[i] = temp;
                swapCount += 1;
            }
        }
    }
    
    return;
}
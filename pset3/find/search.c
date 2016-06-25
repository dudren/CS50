#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

bool search(int value, int values[], int n);
void sort(int values[], int n);

int main(void)
{
    int x[] = {3, 1, 10, 12, 13, 5, 14, 9, 2, 11, 4, 6, 8};
    sort(x, 13);
    for (int i = 0; i < 13; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
    
    
    if (search(5, x, 13))
    {
        printf("\nFound needle in haystack!\n\n");
        return 0;
    }
    else
    {
        printf("\nDidn't find needle in haystack.\n\n");
        return 1;
    }
    
}

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
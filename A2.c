#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int sumArr(int* arr, int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int sSum(int* arr, int size)
{
    bool is6 = false, is7 = false;
    int index6 = 0, index7 = 0, result = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == 6)
        {
            is6 = true;
            index6 = i;
            break;
        }
    }

    if (is6)
    {
        for(int i = index6; i < size; i++)
        {
            result += arr[i];
            if(arr[i] == 7)
            {
                is7 = true;
                index7 = i;
                break;
            }
        }
    }
    return is7? (sumArr(arr, size) - result) : sumArr(arr, size);
    // if (is7)
    // {
    //     return (sumArr(arr, size) - result);
    // }
    // else return sumArr(arr, size);
    
}

void main()
{
    system("cls");
    int arr[] = {10, 3, 6, 1, 2, 7, 9};
    int size = sizeof(arr) / sizeof(int);
    printf("%d\n", sumArr(arr, size));
    printf("%d\n", sSum(arr, size));
}
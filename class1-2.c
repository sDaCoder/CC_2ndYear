#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int binarySearch(int* arr, int size, int target)
{
    int mid, start = 0, end = (size - 1);
    while (start <= end)
    {
        mid = (start + end)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) start = mid + 1; 
        else end = mid - 1;
    }
    return -1;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sSort(int* arr, int size)
{
    int index;
    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[index] > arr[j])   
            {
                index = j;
            }
        }
        swap(arr + i, arr + index);
    }
}

int missing_int(int* arr, int size)
{
    sSort(arr, size);

    int range = size + 1, i;
    for(i = 1; i <= range; i++)
    {
        if (binarySearch(arr, size, i) == -1)
        {
            return i;
        }
    }
}

void main()
{
    system("cls");
    
    int arr[] = {6, 4, 8, 9, 11, 10, 1, 2, 3, 5};
    int size = sizeof(arr)/sizeof(int);

    printf("%d", missing_int(arr, size));
}
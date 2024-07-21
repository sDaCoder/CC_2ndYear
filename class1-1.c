#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* merge(int* arr1, int* arr2, int size1, int size2)
{
    int* arr = (int*)malloc(sizeof(int)*(size1+size2));
    int i = 0, j = 0, index = 0;

    while (i < size1 && j < size2)
    {
        if(arr1[i] < arr2[j])
        {
            arr[index] = arr1[i];
            i++;
        }
        else
        {
            arr[index] = arr2[j];
            j++;
        }
        index++;
    }

    while (i < size1)
    {
        arr[index] = arr1[i];
        i++;
        index++;
    }
    
    while (j < size2)
    {
        arr[index] = arr2[j];
        j++;
        index++;
    }
    
    return arr;
}

void main(){
    system("cls");
    int arr1[] = {1, 3, 5, 8, 25};
    int arr2[] = {2, 4, 6, 9, 10};

    int size1 = sizeof(arr1)/sizeof(int);
    int size2 = sizeof(arr2)/sizeof(int);

    int* arr = merge(arr1, arr2, size1, size2);
    
    printArr(arr1, size1);
    printArr(arr2, size2);
    printArr(arr, size1+size2);
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void printArr(int* arr, int size)
{
    for(int i=0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void printDuplicate(int* arr, int size)
{
    bool flag = false;
    for(int i=0; i < size; i++)
    {
        for(int j=i+1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                printf("%d ", arr[i]);
            }
        }
    }
}

void findUnique(int* arr, int size)
{
    bool duplicate = false;
    for(int i=0; i < size; i++)
    {
        for(int j=i+1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                duplicate = true;
                break;
            }
        }
        if(!duplicate)
        {
            printf("%d ", arr[i]);
        }
        duplicate = false;
    }
}

void main(){
    system("cls");
    
    // int arr[] = {2, 6, 1, 1, 2, 3, 4, 4, 5, 6, 1};
    int arr[] = {1, 2, 4, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    printArr(arr, size);
    printf("\n");
    // printDuplicate(arr, size);
    findUnique(arr, size);
}
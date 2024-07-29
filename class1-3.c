#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void indices(int* arr, int size, int sum)
{
    int start = 0, end, curr_sum = 0;

    for(end = 0; end < size; end++)
    {
        curr_sum += arr[end];

        while(curr_sum > sum && start <= end)
        {
            curr_sum -= arr[start];
            start++;
        }

        if(curr_sum == sum)
        {
            printf("%d %d\n", start, end);
            return;
        }
    }
    printf("Not found");
}

void main(){
    system("cls");
    int arr[] = {3, 4, 5, 9, 0};
    // printf("%d", indices(arr, 4, 7));
    indices(arr, 5, 0);
}
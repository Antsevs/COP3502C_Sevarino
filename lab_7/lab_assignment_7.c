#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    printf("\nUsing Bubble sort\n\n");

    int i, j, temp;
    int swaps = 0; 
    for (i = 0; i < n - 1; i++)
    {
        swaps = 0;
        printf("Iteration #%d\n", i + 1);
        
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap++;
            }
        }
        
        printArray(arr, n);
        printf("Number of swaps: %d\n", swap);
        
        if (swap == 0)
        {
            break;
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {97,16,45,63,13,22,7,58,72};
    int n = 9;

    printf("Array before sorting: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}


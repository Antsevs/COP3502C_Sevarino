#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swaps[j]++;
            }
        }
    }
}

int main() {
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int shift[n]; 
    int i;

    for (i = 0; i < n; i++) {
        shift[i] = 0;
    }

    bubbleSort(arr, n, shift);

    printf("Number of swaps for each index:\n");
    for (i = 0; i < n; i++) {
        printf("Index %d: %d swaps\n", i, shift[i]);
    }

    return 0;
}
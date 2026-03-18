#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Seed random number generator
    srand(time(0));

    // Generate random numbers
    printf("\nGenerated array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // numbers between 0–999
        printf("%d ", arr[i]);
    }

    clock_t start, end;

    start = clock();  // start time

    quickSort(arr, 0, n - 1);

    end = clock();    // end time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken: %f seconds\n", time_taken);

    return 0;
}

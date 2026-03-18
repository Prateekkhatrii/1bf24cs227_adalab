#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int temp[100000];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));

    // Fill array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("\nOriginal Array:\n");
    printArray(arr, n);

    clock_t start, end;

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    printf("\nSorted Array:\n");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to sort %d elements: %f seconds\n", n, time_taken);

    return 0;
}

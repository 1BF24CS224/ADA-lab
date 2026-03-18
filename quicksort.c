#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long comparisons = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
int randomPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]);
    return partition(arr, low, high);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid size!\n");
        return 0;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    printf("Original array:\n");
    printArray(arr, n);
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    printf("Sorted array:\n");
    printArray(arr, n);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTotal comparisons: %lld\n", comparisons);
    printf("Execution time: %f seconds\n", time_taken);
    free(arr);
    return 0;
}

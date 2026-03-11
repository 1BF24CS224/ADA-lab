#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int left, int mid, int right)
{
    int i, j, k;
    int b[100000];
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= right)
        b[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int a[100000], n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;
    printf("\nOriginal Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    start = clock();

    mergeSort(a, 0, n - 1);

    end = clock();

    printf("\n\nSorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nTime taken to sort %d elements = %f seconds\n", n, time_taken);

    return 0;
}

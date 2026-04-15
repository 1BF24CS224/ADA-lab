#include <stdio.h>

struct Item {
    int value;
    int weight;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort items by value/weight ratio (descending) - Bubble sort (simple)
void sort(struct Item arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            float r1 = (float)arr[j].value / arr[j].weight;
            float r2 = (float)arr[j+1].value / arr[j+1].weight;
            if (r1 < r2) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

float fractionalKnapsack(int W, struct Item arr[], int n) {
    sort(arr, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((float)W / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    struct Item arr[] = {{60,10}, {100,20}, {120,30}};
    int n = 3;
    int W = 50;

    printf("Maximum value: %.2f", fractionalKnapsack(W, arr, n));
    return 0;
}

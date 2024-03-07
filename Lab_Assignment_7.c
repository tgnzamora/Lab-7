#include <stdio.h>

// Function to swap elements
void swap(int *xp, int *yp, int *totalSwaps) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    (*totalSwaps)++;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n, int swapCount[], int *totalSwaps) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1], totalSwaps);
                swapCount[arr[j+1]]++; // Increment swap count for the specific value
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n, int swapCount[], int *totalSwaps) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i], totalSwaps);
            swapCount[arr[i]]++; // Increment swap count for the specific value
        }
    }
}

// Function to print swaps for each element
void printSwaps(int arr[], int n, int swapCount[]) {
    for (int i = 0; i < n; i++) {
        printf("%d: %d times swapped\n", arr[i], swapCount[arr[i]]);
    }
}

// Function to copy array
void copyArray(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(array1)/sizeof(array1[0]);
    int originalArray1[sizeof(array1)/sizeof(array1[0])]; // To keep a copy of the original array

    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(array2)/sizeof(array2[0]);
    int originalArray2[sizeof(array2)/sizeof(array2[0])]; // To keep a copy of the original array

    // Copy original array to backup before sorting
    copyArray(array1, originalArray1, n1);
    copyArray(array2, originalArray2, n2);

    int swapCount1[100] = {0}; // Assuming values do not exceed 100
    int totalSwaps1 = 0;

    // Perform Bubble Sort
    bubbleSort(array1, n1, swapCount1, &totalSwaps1);
    printf("Bubble Sort \n\n");
    printf("array1: \n");
    printSwaps(array1, n1, swapCount1);
    printf("Total # of swaps: %d\n\n", totalSwaps1);

    int swapCount2[100] = {0}; // Assuming values do not exceed 100
    int totalSwaps2 = 0;

    bubbleSort(array2, n2, swapCount2, &totalSwaps2);
    printf("array2: \n");
    printSwaps(array2, n2, swapCount2);
    printf("Total # of swaps: %d\n\n", totalSwaps2);

    // Reset the array to its original state
    copyArray(originalArray1, array1, n1);
    copyArray(originalArray2, array2, n2);

    // Reset swaps count and total swaps
    for (int i = 0; i < 100; i++) swapCount1[i] = 0;
    totalSwaps1 = 0;

    // Perform Selection Sort
    selectionSort(array1, n1, swapCount1, &totalSwaps1);
    printf("\n\nSelection Sort \n\n");
    printf("array1: \n");
    printSwaps(array1, n1, swapCount1);
    printf("Total # of swaps: %d\n", totalSwaps1);

    // Reset swaps count and total swaps
    for (int i = 0; i < 100; i++) swapCount2[i] = 0;
    totalSwaps2 = 0;

    // Perform Selection Sort
    selectionSort(array2, n2, swapCount2, &totalSwaps2);
    printf("array2: \n");
    printSwaps(array2, n2, swapCount2);
    printf("Total # of swaps: %d\n", totalSwaps2);




    return 0;
}
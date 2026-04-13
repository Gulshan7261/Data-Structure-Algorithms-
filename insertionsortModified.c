#include <stdio.h>


int keyPosition(int arr[], int key, int s, int e) {
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
            return mid + 1;   
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s;   
}

void modifiedInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int keyIndex = keyPosition(arr, key, 0, i - 1);

        int j = i - 1;
        while (j >= keyIndex) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[keyIndex] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {37, 23, 0, 17, 12, 72, 31};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    printArray(arr, n);

    modifiedInsertionSort(arr, n);

    printf("After Sorting:  ");
    printArray(arr, n);

    return 0;
}
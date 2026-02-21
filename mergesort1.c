#include <stdio.h>
void printArr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
// Merge Function
void merge(int arr[], int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = 0;

    int tempArr[r - l + 1];

    // compare element and merge

    while (i <= mid && j <= r)
    {

        if (arr[i] <= arr[j])
        {

            tempArr[k++] = arr[i++];
        }
        else
        {
            tempArr[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        tempArr[k++] = arr[i++];
    }

    while (j <= r)
    {
        tempArr[k++] = arr[j++];
    }

    for (int m = 0; m < k; m++)
    {
        arr[l + m] = tempArr[m];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {8, 3, 9, 1, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");

    printArr(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printArr(arr, n);

    return 0;
}

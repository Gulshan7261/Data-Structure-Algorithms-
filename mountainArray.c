#include <stdio.h>

int main()
{
    int arr[] = {9, 10, 11, 12, 13, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            peakIndex = i;
            break;
        }
    }

    printf("Peak Index: %d\n", peakIndex);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
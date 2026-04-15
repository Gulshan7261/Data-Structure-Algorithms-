#include <stdio.h>

int main() {
    
    int arr[] = {4,3,1,5,0};
    int n = sizeof(arr)/ sizeof(arr[0]); 

    int missing;

    for (int i = 0; i <= n; i++) {
        missing = missing ^ i;
    }

    for(int i = 0; i < n; i++) {
        missing = missing ^ arr[i];
    }

    printf("Missing: %d\n", missing );


    return 0;
}
#include <stdio.h>

void swap_arr(int *arr, int i, int j) {
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void qsort(int *arr, int left, int right) {
    int i, last;

    if ( left >= right ) {
        return;
    }

    swap_arr(arr, left, (left + right)/2);
    last = left;
    for ( i = left + 1; i <= right; i++ ) {
        if ( arr[i] < arr[left] ) {
            swap_arr(arr, ++last, i);
        }
    }
    swap_arr(arr, left, last);
    qsort(arr, left, last-1);
    qsort(arr, last+1, right);
}

int main() {
    int arr[6] = {3, 1, 5, 9, 8, 2};
    qsort(arr, 0, 5);
    for ( int i = 0; i < 6; i++ ) {
        printf("%d\n", arr[i]);
    }
}
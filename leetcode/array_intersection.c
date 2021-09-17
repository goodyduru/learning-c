#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int smallSize = ( nums1Size < nums2Size ) ? nums1Size : nums2Size;
    int bigSize = ( nums1Size > nums2Size ) ? nums1Size : nums2Size;
    int *outerArray = ( nums1Size <= nums2Size ) ? nums1 : nums2;
    int *innerArray = ( nums1Size > nums2Size ) ? nums1 : nums2;
    int *returnArray = malloc(*returnSize*sizeof(int));
    int value;
    int k = 0, valueCount = 0, keepTrack = 0;
    for (int i = 0; i < smallSize; i++) {
        value = *(outerArray + i);
        for ( int z = 0; z < k; z++ ) {
            if ( value == *(returnArray + z) ) {
                valueCount++;
            }
        }


        for ( int j = 0; j < bigSize; j++ ) {
            if ( value == *(innerArray + j) ) {
                if ( keepTrack < valueCount ) {
                    keepTrack++;
                }
                else {
                    *(returnArray + k) = value;
                    k++;
                    break;
                }
            }
        }
        valueCount = 0;
        keepTrack = 0;
    }
    return returnArray;
}

int main() {
    int first[2] = {1, 2};
    int second[2] = {1, 1};
    int x = 2, i = 0;
    int* returnSize = &x;
    int* returnArray = intersect(first, 2, second, 2, returnSize);
    while ( i < x ) {
        printf("%d\n", *(returnArray + i));
        i++;
    }
}
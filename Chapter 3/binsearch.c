#include <stdio.h>

int binsearch(int x, int v[], int n) {
	int low, mid, high;

	low = 0;
	high = n - 1;
	mid = (low + high)/2;
	while (low <= high && x != v[mid]) {
		if ( x < v[mid] ) {
			high = mid + 1;
		}
		else {
			low = mid + 1;
		}
		mid = (low + high)/2;
	}
	if ( x == v[mid] ) {
		return mid;
	}
	else {
		return -1;
	}
}

int main() {
	int v[10], i, answer;
	for (i = 0; i < 10; i++)
		v[i] = i + 1;
	answer = binsearch(2, v, 10);
       	printf("%d", answer);
}	

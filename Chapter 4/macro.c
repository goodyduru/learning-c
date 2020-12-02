#include <stdio.h>
#define swap(t, x, y) do { t temp ## x ## y = x; x = y; y = temp ## x ## y; } while(0)

int main() {
	int a = 5;
	int b = 3;
	swap(int, a, b);
	printf("%d", a);
}

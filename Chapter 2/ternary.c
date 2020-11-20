#include <stdio.h>

int lower(int c) {
	int l = ( c >= 'A' && c <= 'Z' ) ? c + 'a' - 'A' : c;
	return l;
}

int main() {
	int x = lower('M');
	printf("%c", x);
}

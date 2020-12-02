#include <stdio.h>
#include <limits.h>

int length(char s[]) {
	int i = 0;
	while ( s[i] != '\0' ) {
		i++;
	}
	return i;
}

//Reverse string inplace
void reverse(char s[]) {
	int len, mid, i;
	char temp;
	len = length(s);
	mid = len/2;
	for ( i = 0; i != mid; i++ ) {
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
	s[len] = '\0';
}

void itoa(int n, char s[]) {
	int i, remainder;
	s[0] = '\0';
	if ( n / 10 ) {
		itoa(n/10, s);
	}
	i = length(s);
	if ( n / 10 == 0 && n < 0 ) {
		s[i++] = '-';
	}
	remainder = n % 10;
	s[i++] = (( n < 0 ) ? -remainder : remainder) + '0';
	s[i++] = '\0';
}

int main() {
	char s[255];
	itoa(INT_MIN, s);
	printf("%s \n", s);
	itoa(9382, s);
	printf("%s \n", s);
}

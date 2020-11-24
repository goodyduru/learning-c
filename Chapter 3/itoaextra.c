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

void itoa(int n, char s[], int min_width) {
	int i, sign;
	unsigned int n2;

	if ((sign = n) < 0) {
		n2 = -n;
	}
	else {
	       	n2 = n;
	}	
	i = 0;
	do {
		s[i++] = n2 % 10 +'0';
	}
	while(n2 /= 10);
	if ( sign < 0 )
		s[i++] = '-';
	while ( i < min_width )
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

int main() {
	char s[255];
	itoa(INT_MIN, s, 0);
	printf("%s \n", s);
	itoa(9382, s, 8);
	printf("%s \n", s);
}

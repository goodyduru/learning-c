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

void itob(int n, char s[], int b) {
	int i, sign, rem;
	unsigned int n2;

	if ((sign = n) < 0) {
		n2 = -n;
	}
	else {
	       	n2 = n;
	}	
	i = 0;
	do {
		rem = n2 % b;
		if ( rem >= 10 ) {
			s[i++] = (rem - 10) + 'a';
		}
		else {
			s[i++] = rem + '0';
		}
	}
	while(n2 /= b);
	if ( sign < 0 )
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main() {
	char s[255];
	itob(INT_MIN, s, 10);
	printf("%s \n", s);
	itob(9382, s, 10);
	printf("%s \n", s);
	itob(255, s, 16);
	printf("%s \n", s);
	itob(10, s, 2);
	printf("%s \n", s);
}

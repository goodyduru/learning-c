#include <stdio.h>

int main() {
	int c, i, j, char_freq;
	int nchars[256];

	for (int i = 0; i < 256; i++) {
		nchars[i] = 0;
	}

	while ( (c= getchar()) != EOF ) {
		nchars[c]++;
	}

	for (int i = 0; i < 256; i++) {
		char_freq = nchars[i];
		if ( char_freq > 0 ) {
			printf("|");
			putchar(i);
			printf("|");
		}
		for ( j = 0; j < char_freq; j++ ) {
			printf("-");
		}
		if ( char_freq > 0 ) {
			printf("\n");
		}
	}
}

#include <stdio.h>

int main() {
	int c, nchars, i;
	nchars = 0;

	while ( (c = getchar()) != EOF ) {
		if ( c == ' ' || c == '\n' || c == '\t' ) {
			i = 0;
			while ( i < nchars ) {
			       	printf("-");
				i++;
		 	}
			if ( nchars > 0 )
				printf("\n");
			nchars = 0;
		}
		else {
			nchars++;
		}
	}
}	

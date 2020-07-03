#include <stdio.h>

int main() {
	int c, prev_space;
	prev_space = 0;
	while ( (c = getchar()) != EOF ) {
		if ( c == ' ' && prev_space == 0 ) {
			putchar(c);
			prev_space = 1;
		}
		else if ( c == ' ' && prev_space == 1 ) {
		       continue;
		}
		else {
			putchar(c);
			prev_space = 0;
		}
	}
}	

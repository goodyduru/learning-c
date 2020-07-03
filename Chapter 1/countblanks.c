#include <stdio.h>

int main() {
	int c, nb;

	nb = 0;
	while ( (c = getchar()) != EOF ) {
		if ( c == '\n' || c == '\t' || c == ' ' ) {
			nb++;
		}
	}
	printf("%d\n", nb);
}

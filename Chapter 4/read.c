#include <stdio.h>
#define BUFFERSIZE 100

char buf[BUFFERSIZE];
int bufp = 0;

int getch() {
	return ( bufp > 0 ) ? buf[--bufp] : getchar();
}

void ungetch(char c) {
	if ( bufp > BUFFERSIZE ) {
		printf("ungetch: too many characters");
	}
	else {
		buf[bufp++] = c;
	}
}

void ungets(char s[]) {
	int i = 0;
	while ( s[i] != '\0' ) {
		ungetch(s[i++]);
	}
}

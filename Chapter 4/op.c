#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'
int getch();
void ungetch(int);

/*getop: get next character or operand*/
int getop(char s[]) {
	int i, c, next;
	i = 0;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if ( !isdigit(c) && c != '.' && c != '-' )
		return c;
	if ( c == '-' ) {
		next = getch();
		if ( !isdigit(next) && next != '.' ) {
			return c;
		}
		c = next;
	}
	else {
		c = getch();
	}
	while (isdigit(s[++i] = c))
		c = getch();
	if (c == '.') {
		while (isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if ( c != EOF )
		ungetch(c);
	return NUMBER;
}

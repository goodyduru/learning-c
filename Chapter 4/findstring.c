#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main() {
	char line[MAXLINE];
	int found = 0;
	while (getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim) {
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
/* strindex: return rightmost index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k, line_length, pattern_length;
	line_length = strlen(s) - 1;
	pattern_length = strlen(t) - 1;
	for (i = line_length; i >= 0; i--) {
		for (j=i, k=pattern_length; k >= 0 && s[j]==t[k]; j--, k--)
			;
		if ( k == -1 ) {
			printf("%d \n", (j+1));
			return i;
		}
	}
	return -1;
}


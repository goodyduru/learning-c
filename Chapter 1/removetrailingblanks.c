#include <stdio.h>
#define MAXLINES 1000 //Acceptable maximum line
#define NUMLINES 10 //Acceptable number of lines

int getline(char line[], int maxline);
void copy(char from[], char to[]);

int getline(char s[], int limit) {
	int c, i, whitespace_index;
	whitespace_index = -1;
	for (i = 0; i < limit - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
		if ( c != ' ' && c != '\t' ) {
			whitespace_index = -1;
		}
		else if ( whitespace_index == -1 ) {
			whitespace_index = i;
		}
	}
	if ( c == '\n') {
		if ( whitespace_index > -1 ) {
			s[whitespace_index] = c;
			i = whitespace_index;
		}
		else {
			s[i] = c;
		}
		i++;
	}
	s[i] = '\0';
	return i;
}

void copy(char from[], char to[]) {
	int i;
	i = 0;
	while ( (to[i] = from[i]) != '\0') {
		i++;
	}
}

int main() {
	int len, current_index, i;
	char line[MAXLINES];
	char lines[NUMLINES][MAXLINES];

	current_index = 0;
	while ( (len = getline(line, MAXLINES)) > 0 ) {
		if ( len > 1 ) {
			copy(line, lines[current_index]);
			current_index++;
		}
	}
	if ( current_index > 0 ) {
		for( i = 0; i < current_index; i++ ) {
			printf("%s", lines[i]);
		}
	}
}



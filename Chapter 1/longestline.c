#include <stdio.h>
#define MAXLINE 1000 //Acceptable maximum line
#define NUM_LINES 10 //Acceptable number of long lines

int getline(char line[], int maxline);
void copy(char from[], char to[]);

int getline(char s[], int limit) {
	int c, i;

	for (i=0; i < limit - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

void copy(char from[], char to[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0') {
		i++;
	}
}

int main() {
	int len, is_long, current_index, i;
	char line[MAXLINE];
	char long_lines[NUM_LINES][MAXLINE];

	is_long = 10;
	current_index = 0;
	while ((len = getline(line, MAXLINE)) > 0 ) {
		if ( len > is_long && current_index < NUM_LINES) {
	 		copy(line, long_lines[current_index]);
			current_index++;
		}
	}
	if ( current_index > 0 ) {
		for( i = 0; i < current_index; i++ ) {
			printf("%s", long_lines[i]);
		}
	}
}	


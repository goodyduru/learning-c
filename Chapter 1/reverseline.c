#include <stdio.h>
#define MAXLINE 1000 //Acceptable maximum line
#define NUM_LINES 10 //Acceptable number of long lines

int getline(char line[], int maxline);
void reverse(char from[], char to[], int length);

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

void reverse(char from[], char to[], int length) {
	int i;
	i = 0;
	while ( length > 1 ) {
		to[i] = from[length - 2];
		i++;
		length--;
	}
	to[i] = '\0';
}

int main() {
	int len, is_long, current_index, i;
	char line[MAXLINE];
	char long_lines[NUM_LINES][MAXLINE];
	char line_length[NUM_LINES];

	is_long = 10;
	current_index = 0;
	while ((len = getline(line, MAXLINE)) > 0 ) {
		if ( current_index < NUM_LINES ) {
	 		reverse(line, long_lines[current_index], len);
			current_index++;
		}
	}
	if ( current_index > 0 ) {
		for( i = 0; i < current_index; i++ ) {
			printf("%s\n", long_lines[i]);
		}
	}
}	


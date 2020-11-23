#include <stdio.h>

#define IN 0
#define OUT 1
#define LENGTH 255
void expand(char s[], char t[]){
	int i, j, state;
	char c, prev;
	for ( i = 0, j = 0; s[i] != '\0'; i++ ) {
		if ( i != 0 && s[i] == '-' ) {
			prev = s[i-1];
			state = IN;
		}
		else if ( i == 0 && s[i] == '-' ) {
			t[j++] = s[i];
		}
		else {
			if ( state == IN ) {
				for ( c = prev + 1; c > prev && c <= s[i]; c++ ) {
			       		t[j++] = c;
				}
		 	}
			else {
				t[j++] = s[i];
			}
			state = OUT;
		}
	}
	if ( s[i-1] == '-' ) {
		t[j++] = '-';
	}
	t[j] = '\0';
}

int main() {
	char s[] = "-a-g-t-x0-6-8-";
	char t[LENGTH];
	expand(s, t);
	printf("%s", t);
}


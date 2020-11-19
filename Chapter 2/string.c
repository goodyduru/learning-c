#include <stdio.h>

void single_squeeze(char s[], int c) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++) {
		if ( s[i] != c ) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

void squeeze(char s1[], char s2[]) {
	int i = 0;
	while (s2[i] != '\0') {
		single_squeeze(s1, s2[i++]);
	}
}

int single_any(char s[], int c) {
	int i, j;
	j = -1;
	for ( i = 0; s[i] != '\0'; i++ ) {
		if ( s[i] == c ) {
			j = i;
			break;
		}
	}
	return j;
}

int any(char s1[], char s2[]) {
	int i = 0;
	int j = -1;
	while (s2[i] != '\0') {
		j = single_any(s1, s2[i++]);
		if ( j > -1 ) {
			break;
		}
	}
	return j;
}

int main() {
	int j = 0;
	char s1[] = "Any way we go";
	char s2[] = "wo";
	squeeze(s1, s2);
	printf("%s \n", s1);
	char s3[] = "Any way we go";
	j = any(s3, s2);
	printf("%d", j);	
}


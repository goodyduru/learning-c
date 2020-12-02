#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j) {
	int temp;
	if ( i < j ) {
		reverse(s, i+1, j-1);
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}	
}

int main() {
	char s[] = "Many money";
	reverse(s, 0, strlen(s)-1);
	printf("%s", s);
}

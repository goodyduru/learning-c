#include <stdio.h>

int mystrlen(char s[]) {
	int i = 0;
	while ( s[i++] != '\0' ) {
	}
	return i;
}

void escape(char s[], char t[]) {
	int i, j;
	i = j = 0;
	while ( s[i] != '\0' ) {
		switch ( s[i] ) {
			case '\t':
				t[j] = '\\';
				t[j+1] = 't';
				j += 2;
			break;
			case '\n':
				t[j] = '\\';
				t[j+1] = 'n';
				j += 2;
			break;
			default:
				t[j] = s[i];
				j += 1;
			break;
		}
		i++;
	}
	t[j] = '\0';
}

void unescape(char s[], char t[]) {
	int i, j;
	i = j = 0;
	while ( s[i] != '\0' ) {
		switch ( s[i] ) {
			case '\\':
				if ( s[i+1] == 'n' ) {
					t[j] = '\n';
					i += 2;
				}
				else if ( s[i+1] == 't' ) {
					t[j] = '\t';
					i += 2;
				}
				else {
					t[j] = '\\';
					i++;
				}
			break;
			default:
				t[j] = s[i];
				i++;
			break;
		}
		j++;
	}
	t[j] = '\0';
}

int main() {
	char s[] = "My very \n elegant \t marry";
	int len = mystrlen(s);
	char t[len*2 + 1];
	escape(s, t);
	printf("%s \n", t);
	
	int other_len = mystrlen(t);
	char a[other_len/2 + 2];
	unescape(t, a);
	printf("%s", a);
}
				

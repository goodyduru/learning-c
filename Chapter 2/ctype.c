#include <stdio.h>

int my_atoi(char s[]) {
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
		n = 10 * n + (s[i] - '0');
	}
	return n;
}

int my_lower(int c) {
	if ( c >= 'A' && c <= 'Z') {
		return c + 'a' - 'A';
	}
	else {
		return c;
	}
}

int my_htoi(char s[]) {
	int i, n;
	char lower_case;
	n = 0;
	for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') 
			|| (s[i] >= 'A' && s[i] <= 'F') || (s[i] == 'x' || s[i] == 'X'); i++ ) {
		lower_case = (char)my_lower(s[i]);
		if (lower_case == 'x'){
	       		n = 0;
	       	}
	       	else if (lower_case >= 'a' && lower_case <= 'f') {
			n = 16 * n + (lower_case - 'a' + 10);
		}
		else {
			n = 16 * n + (lower_case - '0');
		}
	}
	return n;
}

int main() {
	int c = my_htoi("0xFF");
	printf("Answer: %d", c);
}

		       

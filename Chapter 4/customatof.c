#include <stdio.h>
#include <ctype.h>

double custom_atof(char s[]) {
	double val, power, answer;
	int i, sign, exponent, is_multiply;

	for ( i = 0; isspace(s[i]); i++ )
		;
	sign = (s[i] == '-') ? -1 : 1;
	if ( s[i] == '+' || s[i] == '-' )
		i++;
	for ( val = 0.0; isdigit(s[i]); i++ )
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for ( power = 1.0; isdigit(s[i]); i++ ) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	
	answer = sign * val / power;
	if ( s[i] == '\0' )
		return answer;
	if ( s[i] == 'e' || s[i] == 'E' )
		i++;
	is_multiply = (s[i] == '-') ? 0 : 1;
	if ( s[i] == '+' || s[i] == '-' )
		i++;
	for ( exponent = 0; isdigit(s[i]); i++ )
		exponent = 10 * exponent + (s[i] - '0');
	while ( exponent > 0 ) {
		answer = (is_multiply) ? answer*10 : answer/10;
		exponent--;
	}
	return answer;	
}

int main() {
	printf("%f \n", custom_atof("67584.322"));
	printf("%f \n", custom_atof("1234.32e3"));
	printf("%f \n", custom_atof("-321.23e-2"));
}

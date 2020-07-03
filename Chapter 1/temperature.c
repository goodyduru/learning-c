#include <stdio.h>

int main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("%s\t%s\n", "Fahr", "Cel");
	while ( fahr <= upper ) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr += step;
	}

	celsius = lower;
	printf("%s\t%s\n", "Cel", "Fahr");
	while ( celsius <= upper ) {
		fahr = (9.0*celsius/5.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius += step;
	}
}

#include <stdio.h>

void fahr_to_celsius(float lower, float upper, float step); 
void celsius_to_fahr(float lower, float upper, float step);

void fahr_to_celsius(float lower, float upper, float step) {
	float fahr, celsius;

	fahr = lower;
	printf("%s\t%s\n", "Fahr", "Cel");
	while ( fahr <= upper ) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
	       	fahr += step;
	}
}

void celsius_to_fahr(float lower, float upper, float step) {
	float fahr, celsius;

	celsius = lower;
	printf("%s\t%s\n", "Cel", "Fahr");
	while ( celsius <= upper ) {
		fahr = (9.0*celsius/5.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius += step;
	}
}

int main() {
	fahr_to_celsius(0, 300, 20);
	celsius_to_fahr(0, 300, 20);
}

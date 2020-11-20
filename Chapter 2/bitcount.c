#include <stdio.h>

/* bitcount function
 * It uses the fact that x & x-1 will remove the rightmost bit in x.
 * With that we can count all the 1 bits in an integer
 * For example, with number 5 which is 101 in a 2 complement number system.
 * 101 & 100 will be 100, in the second iteration which will result in 100 & 11
 * will result in 0. This only requires 2 iteration which incidentally is the 
 * number of 1-bit in 101.
 */
int bitcount(unsigned int x) {
	int n = 0;
	while (x != 0) {
		x &= (x - 1);
		n++;
	}
	return n;
}

int main() {
	int j = bitcount(10);
	printf("%d", j);
}

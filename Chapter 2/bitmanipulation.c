#include <stdio.h>

unsigned int getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned int setbits(unsigned x, int p, int n, unsigned y) {
    unsigned int y_right = getbits(y, n-1, n);
    unsigned int y_shift = y_right << (p+1-n);
    unsigned int mask = ~(~0 << n) << (p+1-n);
    x &= ~mask; //clear the bits in position p to p+1-n
    return x | y_shift;
}

unsigned int invert(unsigned x, int p, int n) {
    unsigned int bits = getbits(x, p, n);
    bits = ~bits;
    return setbits(x, p, n, bits);
}

int main() {
    unsigned int ans = setbits(53, 4, 3, 23);
    printf("%u\n", ans);
    ans = invert(53, 4, 3);
    printf("%u\n", ans);
}
#include <stdio.h>
#include <stdlib.h>
#define COLSIZE 80
#define OUTPUTSIZE 1000
int main() {
    int c, i = 0, j = 0;
    char *s = malloc(sizeof(char) * OUTPUTSIZE + 1);
    while ( (c = getchar()) != EOF && i < OUTPUTSIZE ) {
        s[i] = c;
        i++;
        j++;
        if ( j >= 80 ) {
            s[i] = '\n';
            i++;
            j = 0;
        }
    }
    s[i] = '\0';
    printf("\n%s\n", s);
}
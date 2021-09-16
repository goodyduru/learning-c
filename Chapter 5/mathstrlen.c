#include <stdio.h>

int strlen(char *s) {
    char *p = s;

    while ( *p != '\0' )
        p++;
    
    return p - s;
}

int main() {
    printf("Length of '': %d\n", strlen(""));
    printf("Length of 'hello': %d\n", strlen("Hello"));
    printf("Length of 'Goodness Duru': %d\n", strlen("Goodness Duru"));
}
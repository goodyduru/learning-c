#include <stdio.h>

void strncopy(char *s, char *t, int n) {
    for ( int i = 0; i < n; i++) {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';
}

void strncate(char *s, char *t, int n) {
    for (; *s != '\0'; s++)
        ;
    strncopy(s, t, n);
}

int strncmpe(char *s, char *t, int n) {
    for ( int i = 1; *s == *t; s++, t++, i++ ) {
        if ( *s == '\0' || i >= n ) {
            return 0;
        }
    }
    return *s - *t;
}

int main() {
    char s[128] = "";
    char *t = "Holla";
    strncopy(s, t, 3);
    printf("%s\n", s);

    strncate(s, t, 2);
    printf("%s\n", s);

    int j = strncmpe(s, t, 3);
    printf("%d\n", j);
    j = strncmpe(s, t, 4);
    printf("%d\n", j);
}
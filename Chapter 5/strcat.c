#include <stdio.h>
void strcopy(char *s, char *t) {
    while ((*s++ = *t++))
        ;
}
void strcate(char *s, char *t) {
    for (; *s != '\0'; s++)
        ;
    strcopy(s, t);
}

int main() {
    char s[128] = "Hello";
    char *t = " Goody";
    strcate(s, t);
    printf("Concatenated string: %s\n", s);
}
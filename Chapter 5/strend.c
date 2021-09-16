#include <stdio.h>

int strend(char *s, char t) {
    for (; *s != '\0'; s++)
        ;
    return *(s - 1) == t ? 1 : 0;
}

int main() {
    char *s = "hello";
    printf("%d\n", strend(s, 'o'));
    printf("%d\n", strend(s, 'f'));
}
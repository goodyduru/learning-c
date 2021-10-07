#include <stdio.h>

#define is_upper_macro(c) ((c >= 'A') && (c <= 'Z') ? 1 : 0)


int is_upper(int c) {
    return (c >= 'A' && c <= 'Z');
}

int main() {
    printf("%d\n", is_upper_macro('D'));
    printf("%d\n", is_upper('D'));
    printf("%d\n", is_upper_macro('Z'));
    printf("%d\n", is_upper('Z'));
    printf("%d\n", is_upper_macro('g'));
    printf("%d\n", is_upper('g'));
}
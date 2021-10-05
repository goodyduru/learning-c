#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if ( argc <= 1 ) {
        return 0;
    }
    int c;
    char option = *argv[1];
    while ( (c = getchar() ) != EOF ) {
        if ( option == 'u' ) {
            putchar(toupper(c));
        }
        else {
            putchar(tolower(c));
        }
    }
}
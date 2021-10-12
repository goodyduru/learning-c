#include <unistd.h>

#define BUFSIZ 256
#define EOF -1

int getchar() {
    static int n = 0;
    static char buff[BUFSIZ];
    static char *bufp;

    if ( n == 0 ) {
        n = read(0, buff, sizeof(buff));
        bufp = buff;
    }

    return ( --n > 0 ) ? (unsigned char ) *bufp++ : EOF; 
}

int main() {
    char c;
    char d = '\n';
    while ( (c = getchar()) != EOF ) {
        write(1, &c, 1);
        write(1, &d, 1);
    }
}
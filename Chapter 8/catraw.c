#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void filecopy(int ifd, int ofd) {
    char buf[BUFSIZ];
    int n;
    while( (n = read(ifd, buf, BUFSIZ)) > 0 )
        write(ofd, buf, n);
}

void error(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}

int main(int argc, char *argv[]) {
    if ( argc < 2 ) {
        error("Invalid number of arguments: %d", argc);
        exit(1);
    }

    int fd;

    while ( --argc ) {
        if ( (fd = open(*++argv, O_RDONLY, 0)) == -1 )
            error("cat can't open the file: %s", argv[1]);
        else
            filecopy(fd, 1);
            close(fd);
    }
}
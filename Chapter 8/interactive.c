#include <unistd.h>

#define BUFSIZ 256
int main() {
    char buff[BUFSIZ];
    int n;

    while ( (n = read(0, buff, BUFSIZ)) > 0 )
        write(1, buff, n);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 80

char* diff(FILE *first, FILE *second) {
    char* line1 = (char *)malloc(sizeof(char)*MAXLINE);
    char* line2 = (char *)malloc(sizeof(char)*MAXLINE);
    char* diff;
    while ( fgets(line1, MAXLINE, first) != NULL && fgets(line2, MAXLINE, second) != NULL ) {
        if ( strcmp( line1, line2 ) != 0 ) {
            diff = (char *)malloc(sizeof(char)*(strlen(line1) + strlen(line2) + 10));
            sprintf(diff, "%s>>%s\n", line1, line2);
            return diff;
        }
    }
    return "Similar files\n";
}

int main(int argc, char* argv[]) {
    if ( argc < 3 ) {
        fprintf(stderr, "Invalid number of argument: %d", argc);
        exit(1);
    }

    char* diff_line = diff(fopen(argv[1], "r"), fopen(argv[2], "r"));
    printf("%s", diff_line);
}
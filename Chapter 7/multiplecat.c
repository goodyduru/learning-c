#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 80

void filecopy(FILE *ifp, FILE *ofp) {
    char* line = (char *) malloc(sizeof(char)* MAXLINE);
    while ( fgets(line, MAXLINE, ifp) != NULL ) {
        fputs(line, ofp);
    }
    free(line);
}

int main(int argc, char* argv[]) {
    if ( argc < 2 ) {
        fprintf(stderr, "Invalid number of arguments: %d\n", argc);
        exit(1);
    }
    int count = 1;
    char *filename, *filepath;
    while ( --argc > 0 ) {
        printf("Page Number: %d\n", count++);
        filepath = *++argv;
        filename = strrchr(filepath, '/');
        filename = filename ? filename + 1 : filepath;
        printf("Title: %s\n", filename);
        filecopy(fopen(filepath, "r"), stdout);
        printf("\n");
    }
}

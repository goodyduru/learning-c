#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 80

void filecopy(FILE *ifp, FILE *ofp) {
    char* line = (char *) malloc(sizeof(char)* MAXLINE);
    while ( fgets(line, MAXLINE, ifp) != NULL ) {
        fputs(line, ofp);
    }
}

int main(int argc, char* argv[]) {
    if ( argc < 2 ) {
        fprintf(stderr, "Invalid number of arguments: %d\n", argc);
    }
    int count = 1;
    char* filename;
    while ( --argc > 0 ) {
        printf("Page Number: %d\n", count++);
        filename = *++argv;
        printf("Title: %s\n", filename);
        filecopy(fopen(filename, "r"), stdout);
        printf("\n");
    }
}

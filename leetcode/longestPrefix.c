#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if ( strcmp(*strs, "") == 0 ) {
        return "";
    }
    int i;
    int currentCount = 0;
    int started = 1;
    char currentCharacter = **strs;
    while ( started ) {
        i = 1;
        while ( i < strsSize ) {
            if ( !(strlen(strs[i]) >= currentCount + 1) || (strs[i][currentCount] != currentCharacter) ){
                started = 0;
                break;
            }
            i++;
        }
        if ( started ) {
            currentCount++;
            if ( strlen(strs[0]) >= currentCount + 1 ) {
                currentCharacter = strs[0][currentCount];
            }
            else{
                started = 0;
            }
        }
    }
    char *s = malloc(sizeof(char));
    strncpy(s, strs[0], currentCount);
    return s;
}

int main() {
    char *doc[]  = {"flower","flow","flight"};
    char *s = longestCommonPrefix(doc, 3);
    printf("%s\n", s);
}
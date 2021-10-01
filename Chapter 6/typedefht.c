#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

typedef struct nlist* Nodeptr;

static Nodeptr hashtable[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    
    return hashval % HASHSIZE;
}

Nodeptr lookup(char *s) {
    Nodeptr np;

    for ( np = hashtable[hash(s)]; np != NULL; np = np->next ) {
        if (strcmp(s, np->name) == 0)
            return np;
    }
    return NULL;
}

Nodeptr install(char *name, char *defn) {
    Nodeptr np;
    unsigned hashval;

    if ( (np = lookup(name)) == NULL) {
        np = (Nodeptr) malloc(sizeof(*np));
        if ( np == NULL || (np->name = strdup(name)) == NULL ) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtable[hashval];
        hashtable[hashval] = np;
    }
    else {
        free((void *) np->defn);
    }

    if ((np->defn = strdup(defn)) == NULL) 
        return NULL;
    return np;
}

Nodeptr lookupd(char *s) {
    Nodeptr np, prev;

    for ( np = hashtable[hash(s)]; np != NULL; prev = np, np = np->next ) {
        if (strcmp(s, np->name) == 0) {
            return prev;
        }
    }
    return NULL;
}

void undef(char *name) {
    Nodeptr np, prev;
    unsigned hashval;
    prev = lookupd(name);
    hashval = hash(name);
    if ( prev == NULL && hashtable[hashval] == NULL ) {
        return;
    }

    if ( prev == NULL ) {
        np = hashtable[hashval];
        hashtable[hashval] = np->next;
    }
    else {
        np = prev->next;
        prev->next = np->next;
        free(np->name);
        free(np->defn);
    }
}

int main() {
    install("howfar", "index");
    install("awk", "kaw");
    install("howdy", "ddd");
    undef("awk");
}

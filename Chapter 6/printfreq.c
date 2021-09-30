#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    char *word;
    int count;
    struct node *next;
};

struct node* searchlist(struct node *item, char *s) {
    struct node *temp;
    if ( item == NULL ) {
        return NULL;
    }
    if ( strcmp(item->word, s) == 0 ) {
        return item;
    }

    temp = searchlist(item->next, s);
    return temp;
}

struct node* min(struct node *item) {
    while ( item->next != NULL ) {
        item = item->next;
    }
    return item;
}

void swap(struct node *item, struct node *another_item) {
    char* temp_str;
    int temp_count;
    temp_str = strdup(item->word);
    temp_count = item->count;
    item->word = strdup(another_item->word);
    item->count = another_item->count;
    another_item->word = strdup(temp_str);
    another_item->count = temp_count;
    free(temp_str);
}

void bubble_sort(struct node *item) {
    int swapped, i;
    struct node *ptr;
    struct node *last_ptr = NULL;

    do {
        swapped = 0;
        ptr = item;
        while ( ptr->next != last_ptr ) {
            if ( ptr->count < ptr->next->count ) {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last_ptr = ptr;
    }
    while ( swapped );
}

struct node *additem(struct node *item, char *s) {
    int cond;
    struct node *n;

    if ( item == NULL ) {
        item = (struct node *) malloc(sizeof(struct node));
        item->word = strdup(s);
        item->count = 1;
        item->next = NULL;
    }
    else if ( (n = searchlist(item, s)) != NULL ) {
        n->count++;
    }
    else {
        n = min(item);
        n->next = (struct node *) malloc(sizeof(struct node));
        n->next->word = strdup(s);
        n->next->count = 1;
        n->next->next = NULL;
    }
    return item;
}

void printlist(struct node *item) {
    if ( item != NULL ) {
        printf("%4d %s\n", item->count, item->word);
        printlist(item->next);
    }
}

int main() {
    char *words[20] = {
        "world",
        "hell",
        "what",
        "hell",
        "world",
        "how",
        "what",
        "hell",
        "jug",
        "cat",
        "what",
        "see",
        "see",
        "see",
        "hell",
        "see",
        "see",
        "jug",
        "world",
        "tar"
    };
    struct node *root = NULL;
    for ( int i = 0; i < 20; i++ ) {
        root = additem(root, words[i]);
    }
    bubble_sort(root);
    printlist(root);
}
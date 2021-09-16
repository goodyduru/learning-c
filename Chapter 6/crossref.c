#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 1000

struct page {
	int number;
	struct page *node;
};

struct index {
	char *word;
	struct page *pg;
};

char *document[] = {"we", "need", "we", "need", "to", "go", "to", "the", "market"};

int doc_len = 9;

struct page *palloc() {
	return (struct page *) malloc(sizeof(struct page));
}

struct index *ialloc() {
	return (struct index *) malloc(sizeof(struct index));
}

struct page *add_page(struct page *p, int page_num) {
	if ( p == NULL ) {
		p = palloc();
		p->number = page_num;
		p->node = NULL;
	}
	else {
		p->node = add_page(p->node, page_num);
	}
	return p;
}

struct index *binsearch(char *word, struct index *ref, int n) {
	int cond;
	struct index *low = &ref[0];
	struct index *high = &ref[n];
	struct index *mid;

	while ( low < high ) {
		mid = low + (high-low) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
}

void printnode(struct page *p) {
	if ( p != NULL ){ 
		printf("%d ", p->number);
		printnode(p->node);
	}
}

int main() {
	struct index crossref[MAXLENGTH];
	int current_end, start;
	start = current_end = 0;
	struct index *i;
	char *word;
	for (;start < doc_len;start++) {
		word = document[start];
		if ( current_end == 0 || 
		    (i=binsearch(word, crossref, current_end) == NULL) ) {
			i = ialloc();
			i->word = document[start];
			i->pg = add_page(NULL, start);
			crossref[current_end++] = &i;
		}
		else {
			i->pg->node = add_page(i->pg->node, start);
		}
	}
	
	for (start = 0; start < current_end; start++) {
		struct index *x = &crossref[start];
		printf("%s: ", x->word);
		printnode(x->pg);
		printf("\n");
	}
}

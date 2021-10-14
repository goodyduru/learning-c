#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* merging;
    struct ListNode* merged;
    while ( l1 != NULL && l2 != NULL ) {
        if ( merging == NULL ) {
            merging = (struct ListNode*) malloc(sizeof(struct ListNode));
            merged = merging;
        }
        else {
            merging->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            merging = merging->next;
        }
        if ( l1->val <= l2->val ) {
            merging->val = l1->val;
            l1 = l1->next;
        }
        else {
            merging->val = l2->val;
            l2 = l2->next;
        }
        merging->next = NULL;
    }

    if ( l1 != NULL ) {
        if ( merging == NULL ) {
            merged = l1;
        }
        else {
            merging->next = l1;
        }
    }
    
    if ( l2 != NULL ) {
        if ( merging == NULL ) {
            merged = l2;
        }
        else {
            merging->next = l2;
        }
    }
    return merged;  
}

void printlist(struct ListNode *item) {
    if ( item != NULL ) {
        printf("%4d\n", item->val);
        printlist(item->next);
    }
}

int main() {
    int first[] = {1, 3, 4};
    int second[] = {1, 2, 4};
    struct ListNode *l1, *l2, *p1, *p2, *merged;
    int i = 0;
    while ( i < 3 ) {
        if ( l1 == NULL ) {
            l1 = (struct ListNode*) malloc(sizeof(struct ListNode));
            p1 = l1;
        }
        else {
            l1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            l1 = l1->next;
        }
        l1->val = first[i];

        if ( l2 == NULL ) {
            l2 = (struct ListNode*) malloc(sizeof(struct ListNode));
            p2 = l2;
        }
        else {
            l2->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            l2 = l2->next;
        }
        l2->val = second[i];
        i++;
    }
    merged = mergeTwoLists(p1, p2);
    printlist(merged);
}
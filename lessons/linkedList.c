#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} List;


void init(List **ptr);

/**
 * function to insert an element into the list and it will go
 * before the last element
 */
void pre_insert(List **ptr, int val){
    List *tmpPtr;
    tmpPtr = *ptr;

    *ptr = malloc(sizeof(List));
    (*ptr)->data = val;
    (*ptr)->next = tmpPtr;
    //its like writing **ptr.data
};

int main() {
    List *myList = NULL;
}
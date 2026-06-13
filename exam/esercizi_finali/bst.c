#include <stdio.h>
#include <stdlib.h>

struct btree {
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BST;

void print_rec(BST *ptr);
void ordinsert(BST **ptrPtr, int val);

int main(void) {
    BST *albero = NULL;

    ordinsert(&albero, 5);
    ordinsert(&albero, 3);
    ordinsert(&albero, 7);
    ordinsert(&albero, 1);
    ordinsert(&albero, 4);
    ordinsert(&albero, 7);
    ordinsert(&albero, 8);
    ordinsert(&albero, 6);
    print_rec(albero);

    return 0;
}

void print_rec(BST *ptr) {
    if(ptr != NULL) {
        print_rec(ptr->leftPtr);
        printf("%d ", ptr->valore); // visita simmetrica (in ordine)
        print_rec(ptr->rightPtr);
    }
}

void ordinsert(BST **ptrPtr, int val) {
    if(*ptrPtr == NULL){
        BST *newNode = malloc(sizeof(BST));
        newNode->valore = val;
        newNode->leftPtr = NULL;
        newNode->rightPtr = NULL;
        *ptrPtr = newNode;
    } else {
        if(val < (*ptrPtr)->valore){
            ordinsert(&(*ptrPtr)->leftPtr, val);
        } else {
            ordinsert(&(*ptrPtr)->rightPtr, val);
        }
    }
}
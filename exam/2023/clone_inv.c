#include <stdio.h>
#include <stdlib.h>

struct nodoLista {
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

void suf_insert(Lista **ptrPtr, int val);
void print_list(Lista *ptr);
void clone_invlist(Lista *srcPtr, Lista **destPtr);

int main() {
    Lista *mylist = NULL;
    
    suf_insert(&mylist, 29);
    suf_insert(&mylist, 5);
    suf_insert(&mylist, 13);
    suf_insert(&mylist, 24);
    print_list(mylist);
    
    Lista *myinvlist = NULL;
    clone_invlist(mylist, &myinvlist);
    print_list(myinvlist);
    
    return 0;
}

void suf_insert(Lista **ptrPtr, int val) {
    while(*ptrPtr != NULL) {
        ptrPtr = &((*ptrPtr)->nextPtr);
    }
    Lista *tmpPtr = *ptrPtr;
    *ptrPtr = malloc(sizeof(Lista));
    (*ptrPtr)->valore = val;
    (*ptrPtr)->nextPtr = tmpPtr;
}

void print_list(Lista *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

void preInsert(Lista **ptrPtr, int val) {
    Lista *newNode = malloc(sizeof(Lista));
    if(newNode == NULL) return;

    newNode->valore = val;
    newNode->nextPtr = *ptrPtr;
    
    *ptrPtr = newNode;
}

void clone_invlist(Lista *srcPtr, Lista **destPtr) {
    *destPtr = NULL;

    if(srcPtr == NULL){
        return;
    }

    while(srcPtr!=NULL){
        preInsert(destPtr, srcPtr->valore);

        srcPtr = srcPtr->nextPtr;
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct nodoLista {
    int valore;
    struct nodoLista *nextPtr;
} Lista;

/*
 * Stampa della lista dal primo all'ultimo elemento
 */
void print_list(Lista *ptr) {
    while (ptr != NULL) {
        printf("%d -> ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("NULL\n");
}

/*
 * 1. Inserimento ordinato (in ordine crescente)
 * PRE: ptrPtr != NULL, deve puntare a una lista valida e ordinata in modo crescente
 * POST: Inserisce un nuovo nodo all'interno della lista con valore val, in modo tale che sia ancora in ordine crescente
 */
void ord_insert(Lista **ptrPtr, int val) {
    Lista *newNode = malloc(sizeof(Lista));
    if(newNode == NULL) return;
    newNode->valore = val;
    newNode->nextPtr = NULL;

    if(*ptrPtr == NULL || val <= (*ptrPtr)->valore){
        newNode->nextPtr = *ptrPtr;
        *ptrPtr = newNode;

        return;
    }

    Lista *curr = *ptrPtr;
    while(curr->nextPtr != NULL && curr->nextPtr->valore < val){
        curr = curr->nextPtr;
    }

    newNode->nextPtr = curr->nextPtr;
    curr->nextPtr = newNode;
}

/*
 * 2. Clonazione profonda (deep copy) della lista
 * PRE: 
 * POST: 
 */
void clone_list(Lista *srcPtr, Lista **destPtr) {
    if(srcPtr == NULL){
        *destPtr = NULL;
        return;
    }

    *destPtr = malloc(sizeof(Lista));
    if(*destPtr == NULL) return;

    (*destPtr)->valore = srcPtr->valore;
    (*destPtr)->nextPtr = NULL;

    clone_list(srcPtr->nextPtr, &((*destPtr)->nextPtr));
}

/*
 * 3. Stampa della lista in ordine inverso
 * PRE: 
 * POST: 
 */
void print_list_inv(Lista *ptr) {
    if(ptr == NULL) return;
    print_list_inv(ptr->nextPtr);
    printf("%d ", ptr->valore);
}

int main(void) {
    Lista *mylist = NULL;

    ord_insert(&mylist, 29);
    ord_insert(&mylist, 5);
    ord_insert(&mylist, 32);
    ord_insert(&mylist, 93);
    print_list(mylist);

    Lista *clonedlist = NULL;
    clone_list(mylist, &clonedlist);
    print_list_inv(clonedlist);

    return 0;
}
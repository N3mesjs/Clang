#include <stdio.h>
#include <stdlib.h>

typedef struct nodoLista {
    int valore;
    struct nodoLista *nextPtr;
} Lista;

void print_list(Lista *ptr);
void ord_insert(Lista **ptrPtr, int val);
void clone_list(Lista *srcPtr, Lista **destPtr);
void print_list_inv(Lista *ptr);

/*
 * PRE: ptr punta a una Lista valida e ben formata, non puo essere NULL
 * POST: Stampa a schermo la lista partendo dalla testa fino alla coda
 */
void print_list(Lista *ptr) {
    while(ptr !=NULL){
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }

    printf("\n");

    return;
}

/*
 * PRE: ptrPtr non e NULL e punta alla testa della coda
 * POST: inserimento in ordine crescente di un nodo all'interno della lista
 */
void ord_insert(Lista **ptrPtr, int val) {
    Lista *newNode = malloc(sizeof(Lista));
    if(newNode == NULL) return;
    newNode->valore = val;
    newNode->nextPtr = NULL;

    if(*ptrPtr == NULL || (*ptrPtr)->valore > val){
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

    return;
}

/*
 * PRE: srcPtr punta alla testa di una lista e destPtr punta anche esso alla testa di una lista non e' null
 * POST: Allochiamo i vari valori del srcPtr nella destinazione con il medesimo ordine e valori
 */
void clone_list(Lista *srcPtr, Lista **destPtr) {
    if(srcPtr == NULL) {
        *destPtr = NULL;
        return;
    }

    (*destPtr) = malloc(sizeof(Lista));
    if(*destPtr == NULL) return;

    (*destPtr)->valore = srcPtr->valore; 
    (*destPtr)->nextPtr = NULL;

    clone_list(srcPtr->nextPtr, &((*destPtr)->nextPtr));
}

/*
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
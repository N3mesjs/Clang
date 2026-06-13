#include <stdio.h>
#include <stdlib.h>

struct nodoLista{
    int valore;
    struct nodoLista *nextPtr;
};
typedef struct nodoLista Lista;

void print_list(Lista *ptr);
void ord_insert(Lista **ptr, int val);

void print_list(Lista *ptr){
    while(ptr != NULL){
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

void ord_insert(Lista **ptr, int val){
    Lista *previousPtr = NULL;
    Lista *currentPtr = *ptr;
    Lista *newNode = malloc(sizeof(Lista));
    newNode->valore = val;
    newNode->nextPtr = NULL;

    while (currentPtr != NULL && currentPtr->valore < val)
    {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    if(previousPtr == NULL){
        newNode->nextPtr = *ptr;
        *ptr = newNode;
    } else {
        previousPtr->nextPtr = newNode;
        newNode->nextPtr = currentPtr;
    }
}

int main(){
    Lista *l1 = NULL;
    
    ord_insert(&l1, 5);
    ord_insert(&l1, 3);
    ord_insert(&l1, 8);
    ord_insert(&l1, 1);
    print_list(l1); // atteso: 1 3 5 8
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct nodoLista {
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

void suf_insert(Lista **ptrPtr, int val);
void print_list(Lista *ptr);
void intersection(Lista *list1, Lista *list2, Lista **destPtr);
void intersection_rec(Lista *list1, Lista *list2, Lista **destPtr);

int main() {
    Lista *l1 = NULL, *l2 = NULL;
    
    suf_insert(&l1, 9);
    suf_insert(&l1, 5);
    suf_insert(&l1, 11);
    suf_insert(&l1, 42);
    suf_insert(&l1, 7);
    print_list(l1);

    suf_insert(&l2, 7);
    suf_insert(&l2, 13);
    suf_insert(&l2, 22);
    suf_insert(&l2, 5);
    print_list(l2);
    
    Lista *l3 = NULL;
    intersection_rec(l1, l2, &l3);
    print_list(l3);
    
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

void intersection(Lista *list1, Lista *list2, Lista **destPtr) {
    Lista *tmpPtr = list2;
    while(list1 != NULL){
        while(list2 != NULL){
            if(list1->valore == list2->valore){
                suf_insert(destPtr, list1->valore);
            }
            list2 = list2->nextPtr;
        }
        list2 = tmpPtr;
        list1 = list1->nextPtr;
    }
}

int contains(Lista *list, int val) {
    if(list == NULL) return 0;

    if(list->valore == val) return 1;
    return contains(list->nextPtr, val);
}

void intersection_rec(Lista *list1, Lista *list2, Lista **destPtr) {
    if(list1 == NULL) return;

    //intersection_rec(list1->nextPtr, list2, destPtr);
    if(contains(list2, list1->valore)){
        suf_insert(destPtr, list1->valore);
    }
    intersection_rec(list1->nextPtr, list2, destPtr);
}
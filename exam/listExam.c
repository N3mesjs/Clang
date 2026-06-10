#include <stdio.h>
#include <stdlib.h>

struct nodoLista {
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

void suf_insert(Lista **ptrPtr, int val);
void print_list(Lista *ptr);
void difference(Lista *list1, Lista *list2, Lista **destPtr);

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
    difference(l1, l2, &l3);
    print_list(l3);
    
    return 0;
}

void pre_insert(Lista **ptr, int val){
    Lista *tmp;
    tmp = *ptr;

    *ptr = malloc(sizeof(Lista));
    (*ptr)->valore = val;
    (*ptr)->nextPtr = tmp;
}

void suf_insert(Lista **ptrPtr, int val) {
    while(*ptrPtr != NULL){
        ptrPtr = &((*ptrPtr)->nextPtr);
    }
    pre_insert(ptrPtr, val);
}


void print_list(Lista *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

void difference(Lista *list1, Lista *list2, Lista **destPtr) {
    while(list1 != NULL){
        int found = 0;
        Lista *tmp = list2;
        while(tmp != NULL){
            if(list1->valore == tmp->valore){
                found = 1;
            }
            tmp = tmp->nextPtr;
        }

        if(!found){
            suf_insert(destPtr, list1->valore);
        }

        found = 0;
        list1 = list1->nextPtr;
    }
}
#include <stdio.h>
#include <stdlib.h>

struct nodoLista {
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

void suf_insert(Lista **ptr, int val);
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

void suf_insert(Lista **ptr, int val) {
    Lista *newNode = malloc(sizeof(Lista));
    if(newNode == NULL) return;

    newNode->valore = val;
    newNode->nextPtr = NULL;

    if(*ptr == NULL){
        *ptr = newNode;
        return;
    }

    Lista *curr = *ptr;
    while(curr->nextPtr != NULL){
        curr = curr->nextPtr;
    }

    curr->nextPtr = newNode;
}

void print_list(Lista *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

int contains(Lista *list, int val){
    while(list != NULL){
        if(list->valore == val) return 1;

        list = list->nextPtr;
    }

    return 0;
}

void difference(Lista *list1, Lista *list2, Lista **destPtr) 
{
    *destPtr = NULL;
    if(list1 == NULL || list2 == NULL) return;

    Lista *tail = NULL;

    while(list1 != NULL){
        if(!contains(list2, list1->valore)){
            Lista *newNode = malloc(sizeof(Lista));
            if(newNode == NULL) return;

            newNode->valore = list1->valore;
            newNode->nextPtr = NULL;

            if(*destPtr == NULL){
                *destPtr = newNode;
                tail = *destPtr;
            } else {
                tail->nextPtr = newNode;
                tail = newNode;
            }
        }
        list1 = list1->nextPtr;
    }
}
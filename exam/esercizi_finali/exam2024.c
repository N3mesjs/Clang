#include <stdio.h>
#include <stdlib.h>

/* ===================== PARTE 1: STRINGHE BINARIE ===================== */

/*
 * PRE:  n >= 0
 * POST: 
 */
int conta_stringhe(int n);

/*
 * PRE:  n >= 0, k >= 0
 * POST: 
 */
int conta_stringhe_k(int n, int k);

/* funzione ausiliaria suggerita dalla consegna */
int conta_stringhe_k_aux(int n, int k, int consecutivi);


/* ===================== PARTE 2: LISTE ===================== */

struct nodoLista {
    int valore;
    struct nodoLista *nextPtr;
};
typedef struct nodoLista Lista;

void print_list(Lista *ptr);

/*
 * PRE:  
 * POST: 
 */
void suf_insert(Lista **ptrPtr, int val);

/*
 * PRE:  list1 e list2 non contengono duplicati
 * POST: 
 */
void difference(Lista *list1, Lista *list2, Lista **destPtr);


/* ===================== MAIN ===================== */

int main(void) {
    // test conta_stringhe
    printf("conta_stringhe(3) = %d\n", conta_stringhe(3)); // atteso 5
    printf("conta_stringhe(4) = %d\n", conta_stringhe(4)); // atteso 8

    // test conta_stringhe_k
    printf("conta_stringhe_k(3,1) = %d\n", conta_stringhe_k(3, 1)); // atteso 5
    printf("conta_stringhe_k(3,2) = %d\n", conta_stringhe_k(3, 2)); // atteso 7

    // test suf_insert e difference
    Lista *l1 = NULL, *l2 = NULL, *l3 = NULL;
    suf_insert(&l1, 9);
    suf_insert(&l1, 5);
    suf_insert(&l1, 11);
    suf_insert(&l1, 42);
    suf_insert(&l1, 7);
    print_list(l1); // 9 5 11 42 7

    suf_insert(&l2, 5);
    suf_insert(&l2, 42);
    suf_insert(&l2, 3);
    print_list(l2); // 5 42 3

    difference(l1, l2, &l3);
    print_list(l3); // atteso: 9 11 7

    return 0;
}


/* ===================== IMPLEMENTAZIONI ===================== */

void print_list(Lista *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

int conta_stringhe(int n) {
    if(n==0) return 1;
    if(n==1) return 2;

    return conta_stringhe(n-1) + conta_stringhe(n-2);
}

int conta_stringhe_k(int n, int k) {
    return conta_stringhe_k_aux(n, k, 0);
}

int conta_stringhe_k_aux(int n, int k, int consecutivi) {
    if(n==0) return 1;

    int metto_zero = conta_stringhe_k_aux(n-1, k, 0);

    int metto_uno = 0;

    if(consecutivi < k){
        metto_uno = conta_stringhe_k_aux(n-1, k, consecutivi+1);
    }

    return metto_uno + metto_zero;
}

void suf_insert(Lista **ptrPtr, int val) {
    while(*ptrPtr != NULL){
        ptrPtr = &(*ptrPtr)->nextPtr;
    }

    Lista *newNode = malloc(sizeof(Lista));
    newNode->valore = val;
    newNode->nextPtr = NULL;

    *ptrPtr = newNode;
}

void difference(Lista *list1, Lista *list2, Lista **destPtr) {
    Lista *tmp = list2;
    int found = 0;
    while(list1 != NULL)
    {
        while (list2 != NULL)
        {
            if(list1->valore == list2->valore) found = 1;
            list2 = list2->nextPtr;
        }

        if(!found){
                // Lista *tmp = *destPtr;
                // Lista *newNode = malloc(sizeof(Lista));
                // newNode->valore = list1->valore;
                // newNode->nextPtr = *destPtr;
                // *destPtr = newNode;
                suf_insert(destPtr, list1->valore);
        }

        list2 = tmp;
        list1 = list1->nextPtr;
        found = 0;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int value;
    struct node *nextPtr;
};

typedef struct node Lista;

/* ========================================================================== */
/*                           1. VERSIONE ITERATIVA                            */
/* ========================================================================== */

/*
 * PRE: Un puntatore valido a una linked list
 * POST: Restituisce il puntatore al nodo di valore dispari piu piccolo tra tutti i nodi dispari.
 */
Lista* first_odd_iter(Lista *srcPtr) {
    Lista *oddPtr = NULL;
    while(srcPtr != NULL){
        if(srcPtr->value % 2 != 0){
            if(oddPtr == NULL || oddPtr->value > srcPtr->value){
                oddPtr = srcPtr;
            }
        }

        srcPtr = srcPtr->nextPtr;
    }

    return oddPtr;
}

/* ========================================================================== */
/*                           2. VERSIONE RICORSIVA                            */
/* ========================================================================== */

/*
 * PRE: puntatore a un nodo della lista concatenata, puntatore al nodo di valore dispari minimo
 * POST: restituisce il puntatore del nodo minimo qual ora giungiamo alla fine della lista, se no 
 * chiamiamo ricorsivamente la funzione e per ogni nodo controgliamo parita e se il valore e minore del 
 * valore del nodo minore corrente
 */
// (Opzionale) Definire qui un'ausiliaria se necessario, es:
Lista* first_odd_rec_helper(Lista *curr, Lista *min){
    if(curr == NULL){
        return min;
    }

    if(curr->value % 2 != 0){
        if(min == NULL || min->value > curr->value){
            min = curr;
        }
    }

    return first_odd_rec_helper(curr->nextPtr, min);
}

/*
 * PRE: puntatore a una lista concatenata
 * POST: ritorna il puntatore al nodo di valore dispari di valore piu piccolo tra tutti i nodi di valore dispari
 */
Lista* first_odd_rec(Lista *srcPtr) {
    return first_odd_rec_helper(srcPtr, NULL);
}

/* ========================================================================== */
/*                               MAIN DI TEST                                 */
/* ========================================================================== */

void push(Lista **head, int val) {
    Lista *n = malloc(sizeof(Lista));
    n->value = val;
    n->nextPtr = *head;
    *head = n;
}

void free_list(Lista *head) {
    while (head != NULL) {
        Lista *tmp = head;
        head = head->nextPtr;
        free(tmp);
    }
}

int main(void) {
    printf("=== TEST first_odd (Iterativa & Ricorsiva) ===\n");

    // Test 1: Lista vuota -> NULL
    Lista *l1 = NULL;
    assert(first_odd_iter(l1) == NULL);
    assert(first_odd_rec(l1) == NULL);
    printf("[OK] Test 1: Lista vuota superato\n");

    // Test 2: Solo numeri pari -> NULL
    Lista *l2 = NULL;
    push(&l2, 8);
    push(&l2, 4);
    push(&l2, 2);
    assert(first_odd_iter(l2) == NULL);
    assert(first_odd_rec(l2) == NULL);
    printf("[OK] Test 2: Solo pari superato\n");

    // Test 3: Più elementi dispari (9 -> 3 -> 7 -> 5 -> 10, minimo dispari = 3)
    Lista *l3 = NULL;
    push(&l3, 10);
    push(&l3, 5);
    push(&l3, 7);
    push(&l3, 3);
    push(&l3, 9);
    Lista *res3_it = first_odd_iter(l3);
    Lista *res3_rec = first_odd_rec(l3);
    assert(res3_it != NULL && res3_it->value == 3);
    assert(res3_rec != NULL && res3_rec->value == 3);
    printf("[OK] Test 3: Minimo dispari positivo superato\n");

    // Test 4: Con negativi dispari (1 -> -7 -> -3 -> 4, minimo dispari = -7)
    Lista *l4 = NULL;
    push(&l4, 4);
    push(&l4, -3);
    push(&l4, -7);
    push(&l4, 1);
    Lista *res4_it = first_odd_iter(l4);
    Lista *res4_rec = first_odd_rec(l4);
    assert(res4_it != NULL && res4_it->value == -7);
    assert(res4_rec != NULL && res4_rec->value == -7);
    printf("[OK] Test 4: Minimo dispari negativo superato\n");

    free_list(l2);
    free_list(l3);
    free_list(l4);

    printf("\nTUTTI I TEST SUPERATI!\n");
    return 0;
}
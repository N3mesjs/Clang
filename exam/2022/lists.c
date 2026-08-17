#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *nextPtr;
};

typedef struct node Lista;

/*
 * Esercizio 4: Versione ITERATIVA
 */
Lista* first_odd_iter(Lista *srcPtr) {
    Lista *lowest = NULL;

    while (srcPtr != NULL) {
        if (srcPtr->value % 2 != 0) {
            if (lowest == NULL || srcPtr->value < lowest->value) {
                lowest = srcPtr;
            }
        }
        srcPtr = srcPtr->nextPtr;
    }

    return lowest;
}

/*
 * Esercizio 5: Versione RICORSIVA (con helper tail-recursive)
 */
Lista* first_odd_rec_helper(Lista *srcPtr, Lista *lowest) {
    if (srcPtr == NULL) {
        return lowest;
    }

    if (srcPtr->value % 2 != 0) {
        if (lowest == NULL || srcPtr->value < lowest->value) {
            lowest = srcPtr;
        }
    }

    return first_odd_rec_helper(srcPtr->nextPtr, lowest);
}

Lista* first_odd_rec(Lista *srcPtr) {
    return first_odd_rec_helper(srcPtr, NULL);
}

// Funzione ausiliaria per inserire in testa (utile per il testing)
void push(Lista **head, int val) {
    Lista *n = malloc(sizeof(Lista));
    n->value = val;
    n->nextPtr = *head;
    *head = n;
}

// Funzione ausiliaria per stampare la lista
void print_list(Lista *head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->nextPtr;
    }
    printf("NULL\n");
}

int main(void) {
    Lista *head = NULL;

    // Esempio: lista con valori 8 -> 11 -> 4 -> 3 -> 7 -> 2
    // I numeri dispari sono: 11, 3, 7. Il minimo è 3.
    push(&head, 2);
    push(&head, 7);
    push(&head, 3);
    push(&head, 4);
    push(&head, 11);
    push(&head, 8);

    printf("Lista: ");
    print_list(head);

    Lista *res_iter = first_odd_iter(head);
    if (res_iter != NULL) {
        printf("[Iterativo] Minimo dispari: %d (indirizzo: %p)\n", res_iter->value, (void*)res_iter);
    } else {
        printf("[Iterativo] Nessun elemento dispari trovato (NULL)\n");
    }

    Lista *res_rec = first_odd_rec(head);
    if (res_rec != NULL) {
        printf("[Ricorsivo] Minimo dispari: %d (indirizzo: %p)\n", res_rec->value, (void*)res_rec);
    } else {
        printf("[Ricorsivo] Nessun elemento dispari trovato (NULL)\n");
    }

    return 0;
}
#include <stdlib.h>
#include <stdio.h>

/**
 * File created just to rewrite all the functions and see if i undestood the assignment
 */

typedef struct Node {
    int value;
    struct Node *next;
} Node;

/* ==========================================================================
 * LE TUE FUNZIONI DA RISCRIVERE
 * ========================================================================== */

/**
 * 1. initList
 * Inizializza il puntatore alla testa della lista portandolo a NULL.
 */
void initList(Node **ptr) {
    *ptr = NULL;
}

/**
 * 2. preInsert
 * Crea un nuovo nodo e lo inserisce in TESTA alla lista.
 */
void preInsert(Node **ptr, int value) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;
    newNode->value = value;

    newNode->next = *ptr;
    *ptr = newNode;
}

/**
 * 3. sufInsert
 * Crea un nuovo nodo e lo inserisce in CODA alla lista.
 * Attenzione al caso in cui la lista sia vuota!
 */
void sufInsert(Node **ptr, int value) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;
    newNode->value = value;
    newNode->next = NULL;

    if(*ptr == NULL){
        *ptr=newNode;
        return;
    }

    Node *currNode = *ptr;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }

    currNode->next = newNode;
}

/**
 * 4. printList
 * Scorre la lista e stampa i valori di tutti i nodi uno sotto l'altro.
 */
void printList(Node *ptr) {
    while(ptr != NULL){
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
}

/**
 * 5. ord_insert
 * Inserisce un nuovo elemento mantenendo la lista ordinata in modo crescente.
 * Gestisci i casi: lista vuota, inserimento in testa, in mezzo, in coda.
 */
void ord_insert(Node **ptr, int val) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;
    newNode->value = val;
    newNode->next = NULL;

    if(*ptr == NULL || (*ptr)->value >= val){
        newNode->next = *ptr;
        *ptr = newNode;
        return;
    }

    Node *curr = *ptr;
    while(curr->next != NULL && curr->next->value < val){
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

/**
 * 6. clone_list
 * Prende una lista sorgente (srcList) e ne crea una copia esatta in destList.
 * Ricordati di avanzare con un puntatore all'ultimo nodo (tail) per farlo in O(N).
 */
void clone_list(Node *srcList, Node **destList) {
    *destList = NULL;
    Node *tail = NULL;

    while(srcList != NULL){
        Node *newNode = malloc(sizeof(Node));
        if(newNode == NULL) return;
        newNode->value = srcList->value;
        newNode->next = NULL;

        if(*destList == NULL){
            *destList = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
        srcList = srcList->next;
    }
}


/* ==========================================================================
 * MAIN DI TEST (Pronto all'uso)
 * ========================================================================== */

int main(void)
{
    Node *LinkedList;
    Node *SecondList;

    printf("=== TEST 1: Inizializzazione ===\n");
    initList(&LinkedList);
    initList(&SecondList);

    printf("\n=== TEST 2 & 4: Inserimento in Testa e Stampa ===\n");
    printf("Inserisco 42, 17, 4 in testa:\n");
    preInsert(&LinkedList, 42);
    preInsert(&LinkedList, 17);
    preInsert(&LinkedList, 4);
    printList(LinkedList); 
    // Atteso: 4, 17, 42

    printf("\n=== TEST 3: Inserimento in Coda ===\n");
    printf("Aggiungo 53 e 73 in coda:\n");
    sufInsert(&LinkedList, 53);
    sufInsert(&LinkedList, 73);
    printList(LinkedList); 
    // Atteso: 4, 17, 42, 53, 73

    printf("\n=== TEST 5: Inserimento Ordinato ===\n");
    printf("Inserisco 143 in coda e 2 in testa:\n");
    ord_insert(&LinkedList, 143);
    ord_insert(&LinkedList, 2);
    printList(LinkedList); 
    // Atteso: 2, 4, 17, 42, 53, 73, 143

    printf("\n=== TEST 6: Clonazione Lista ===\n");
    clone_list(LinkedList, &SecondList);
    printf("Contenuto di SecondList (clonata):\n");
    printList(SecondList);

    return 0;
}
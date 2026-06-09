#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

void pre_insert(Node **ptr, int value){
    Node *tmp;
    tmp = *ptr;

    *ptr = malloc(sizeof(Node));
    (*ptr)->val = value;
    (*ptr)->next = tmp;
}

void append(Node **ptr, int value){
    while(*ptr != NULL){
        ptr = &((*ptr)->next);
    }

    pre_insert(ptr, value);
}

void init(Node **ptr){
    *ptr = NULL;
}

void printList(Node *ptr){
    while(ptr != NULL){
        printf("Value: %d, next: %p\n", (ptr)->val, (ptr)->next);
        ptr = (ptr)->next;
    }
}

int main(){
    Node *list; 
    init(&list);

    pre_insert(&list, 17); // Inserisce 17 in testa -> Lista: 17
    pre_insert(&list, 29); // Inserisce 29 in testa -> Lista: 29 -> 17
    append(&list, 93);     // Inserisce 93 in coda  -> Lista: 29 -> 17 -> 93

    printList(list); // Passo direttamente list per stamparla
}
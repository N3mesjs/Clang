#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int val;
    struct Stack *next;
};

typedef struct Stack Stack;

void init(Stack **ptr);
int isempty(Stack *ptr);
void print_list(Stack *ptr);
void push(Stack **ptr, int val);
void pop(Stack **ptr);

int main(void){
    //Lista *pila = NULL;
    Stack *pila;
    init(&pila);
    printf("Lista vuota? %d\n", isempty(pila));
    //pop(&pila);
    
    push(&pila, 17);
    printf("Lista vuota? %d\n", isempty(pila));
    push(&pila, 29);
    push(&pila, 5);
    push(&pila, 32);
    push(&pila, 93);
    print_list(pila);
    
    pop(&pila);
    print_list(pila);
    
    pop(&pila);
    //pop(&pila);
    //pop(&pila);
    //pop(&pila);
    print_list(pila);
    
    return 0;
}

void init(Stack **ptr){
    *ptr = NULL;
}

int isempty(Stack *ptr){
    return ptr == NULL;
}

void push(Stack **ptr, int value){
    Stack *newNode = malloc(sizeof(Stack));
    (newNode)->val = value; 
    (newNode)->next = *ptr;

    *ptr = newNode;
}

void pop(Stack **ptr){
    if(!isempty(*ptr)){
        Stack *tmp = *ptr;
        *ptr = (*ptr)->next;
        free(tmp);
    }
}

void print_list(Stack *ptr){
    if(!isempty(ptr)){
        while(ptr != NULL){
            printf("Value: %d, next element: %p\n", (ptr)->val, (ptr)->next);
            ptr = (ptr)->next;
        }
    }
}
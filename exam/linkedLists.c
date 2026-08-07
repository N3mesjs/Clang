#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void initList(Node **ptr){
    *ptr = NULL;
}

void preInsert(Node **ptr, int value)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->next = *ptr;
    newNode->value = value;

    *ptr = newNode;
}

void sufInsert(Node **ptr, int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if(*ptr == NULL){
        *ptr = newNode;
        return;
    }

    Node *tmpNode = *ptr;
    while(tmpNode->next != NULL){
        tmpNode = tmpNode->next;
    }

    tmpNode->next = newNode;
}

void printList(Node *ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
}

int main(void)
{
    Node *LinkedList;

    initList(&LinkedList);
    preInsert(&LinkedList, 42);
    preInsert(&LinkedList, 17);
    preInsert(&LinkedList, 4);
    sufInsert(&LinkedList, 53);
    sufInsert(&LinkedList, 73);

    printList(LinkedList);

    return 0;
}
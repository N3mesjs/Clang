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

void ord_insert(Node **ptr, int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->value = val;

    // caso in cui primo elemento inesistente oppure piu grande di value
    if(*ptr == NULL || (*ptr)->value >= val)
    {
        newNode->next = *ptr;
        *ptr = newNode;
        return;
    }

    // caso in cui il valore deve essere inserito in mezzo o in coda
    Node *curr = *ptr;
    while(curr->next != NULL && curr->next->value < val){
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

//TODO: make a good function that works and uses a pointer to the tail!
void clone_list(Node *srcList, Node **destList)
{
    if(srcList == NULL){
        *destList = NULL;
        return;
    }

    while(srcList != NULL){
        //sufInsert(destList, srcList->value);
        Node *newNode = malloc(sizeof(Node));
        newNode->value = srcList->value;
        newNode->next = NULL;

        if(*destList == NULL){
            *destList = newNode;
        }

        Node *tmpNode = *destList;
        while(tmpNode->next != NULL){
            tmpNode = tmpNode->next;
        }

        tmpNode->next = newNode;

        srcList = srcList->next;
    }
}

int main(void)
{
    Node *LinkedList;
    Node *SecondList;

    initList(&LinkedList);
    preInsert(&LinkedList, 42);
    preInsert(&LinkedList, 17);
    preInsert(&LinkedList, 4);
    sufInsert(&LinkedList, 53);
    sufInsert(&LinkedList, 73);

    ord_insert(&LinkedList, 143);
    ord_insert(&LinkedList, 2);

    printList(LinkedList);

    initList(&SecondList);
    clone_list(LinkedList, &SecondList);
    printList(SecondList);

    return 0;
}
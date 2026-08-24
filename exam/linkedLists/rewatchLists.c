#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int value;
    struct List *next;
} List;

void list_init(List **ptr)
{
    *ptr = NULL;
    return;
}

void list_headInsert(List **ptr, int val)
{
    List *newNode = malloc(sizeof(List));
    if (newNode == NULL)
        return;

    newNode->next = *ptr;
    newNode->value = val;

    *ptr = newNode;
    return;
}

void list_tailInsert(List **ptr, int val)
{
    List *newNode = malloc(sizeof(List));
    if (newNode == NULL)
        return;

    newNode->next = NULL;
    newNode->value = val;

    if (*ptr == NULL)
    {
        *ptr = newNode;
        return;
    }

    List *curr = *ptr;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
}

void list_ordInsert(List **ptr, int val)
{
    List *newNode = malloc(sizeof(List));
    if (newNode == NULL)
        return;

    newNode->next = NULL;
    newNode->value = val;

    if (*ptr == NULL || (*ptr)->value > val)
    {
        *ptr = newNode;
        return;
    }

    List *curr = *ptr;
    while (curr->next != NULL && curr->next->value <= val)
    {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void list_clone(List *src, List **dest)
{
    *dest = NULL;

    if (src == NULL)
        return;

    List *tail;
    while (src != NULL)
    {
        // list_tailInsert(dest, src->value); si puo fare ma complessita alta
        List *newNode = malloc(sizeof(List));
        if (newNode == NULL) return;

        newNode->next = NULL;
        newNode->value = src->value;

        if(*dest == NULL){
            *dest = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
        src = src->next;
    }

    return;
}

void list_clone_rec(List *src, List **dest)
{
    if (src == NULL)
    {
        *dest = NULL;
        return;
    };

    (*dest) = malloc(sizeof(List));
    if (*dest == NULL)
        return;

    (*dest)->value = src->value;
    (*dest)->next = NULL;

    list_clone_rec(src->next, &((*dest)->next));
}

int main(void)
{

    return 0;
}
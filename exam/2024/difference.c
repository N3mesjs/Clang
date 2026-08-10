#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int valore;
    struct Node *next;
};

typedef struct Node Node;

void suf_insert(Node **ptrPtr, int val);
void print_list(Node *ptr);
void difference(Node *list1, Node *list2, Node **destPtr);

int main()
{
    Node *l1 = NULL, *l2 = NULL;

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

    Node *l3 = NULL;
    difference(l1, l2, &l3);
    print_list(l3);

    return 0;
}

void suf_insert(Node **ptr, int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->valore = val;
    newNode->next = NULL;

    if (*ptr == NULL)
    {
        *ptr = newNode;
        return;
    }

    Node *curr = *ptr;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
}

void print_list(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->valore);
        ptr = ptr->next;
    }
    printf("\n");
}

int contains(Node *ptr, int val)
{
    if (ptr == NULL)
        return 0;

    while (ptr != NULL)
    {
        if (val == ptr->valore)
        {
            return 1;
        }

        ptr = ptr->next;
    }
    return 0;
}

void difference(Node *list1, Node *list2, Node **destPtr)
{
    *destPtr = NULL;
    Node *lastElement = NULL;

    while (list1 != NULL)
    {
        if (!contains(list2, list1->valore))
        {
            Node *newNode = malloc(sizeof(Node));
            newNode->valore = list1->valore;
            newNode->next = NULL;

            if (*destPtr == NULL)
            {   
                *destPtr = newNode;
                lastElement = newNode;
            }
            else
            {
                lastElement->next = newNode;
                lastElement = newNode;
            }
        }
        list1 = list1->next;
    }
}
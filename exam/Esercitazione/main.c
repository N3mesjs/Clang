#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* ========================================================================== */
/*                              STRUTTURE DATI                                */
/* ========================================================================== */

typedef struct BST
{
    int value;
    struct BST *left;
    struct BST *right;
} BST;

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

/* ========================================================================== */
/*                       FUNZIONI DA BST.C DEL PROF                           */
/* ========================================================================== */

// Inizializza l'albero a NULL
void bst_init(BST **ptr)
{
    *ptr = NULL;
}

// Inserimento ricorsivo ordinato in un BST
void bst_insert(BST **ptr, int val)
{
    if (*ptr == NULL)
    {
        BST *newNode = malloc(sizeof(BST));
        if (newNode == NULL)
            return;
        newNode->value = val;
        newNode->left = NULL;
        newNode->right = NULL;
        *ptr = newNode;
    }
    else if (val > (*ptr)->value)
    {
        bst_insert(&((*ptr)->right), val);
    }
    else if (val <= (*ptr)->value)
    {
        bst_insert(&((*ptr)->left), val);
    }
}

// Verifica se l'albero e' vuoto
int bst_isEmpty(BST *ptr)
{
    if (ptr == NULL)
        return 1;
    return 0;
}

// Ricerca di un valore nel BST
int bst_search(BST *ptr, int val)
{
    if (ptr == NULL)
        return 0;
    if (val == ptr->value)
    {
        return 1;
    }

    if (val < ptr->value)
    {
        return bst_search(ptr->left, val);
    }
    else if (val > ptr->value)
    {
        return bst_search(ptr->right, val);
    }

    return 0;
}

// Stampa dell'albero in pre-order
void bst_print(BST *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d ", ptr->value);
    bst_print(ptr->left);
    bst_print(ptr->right);
}

// Crea una copia speculare dell'albero
void bst_mirror(BST *srcPtr, BST **destPtr)
{
    *destPtr = NULL;
    if (srcPtr == NULL)
    {
        *destPtr = NULL;
        return;
    }

    *destPtr = malloc(sizeof(BST));
    if (*destPtr == NULL)
        return;
    (*destPtr)->value = srcPtr->value;
    (*destPtr)->right = NULL;
    (*destPtr)->left = NULL;

    bst_mirror(srcPtr->left, &((*destPtr)->right));
    bst_mirror(srcPtr->right, &((*destPtr)->left));
}

// Verifica ricorsiva se tutti i nodi rispettano l'intervallo (min, max]
int bst_isInRange(BST *ptr, int min, int max)
{
    if (ptr == NULL)
        return 1;
    if (ptr->value <= min || ptr->value > max)
    {
        return 0;
    }

    return bst_isInRange(ptr->left, min, ptr->value) &&
           bst_isInRange(ptr->right, ptr->value, max);
}

// Verifica se l'albero e' un BST valido
int bst_isBst(BST *ptr)
{
    if (bst_isInRange(ptr, INT_MIN, INT_MAX))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Rimozione di un valore dal BST con gestione dei 3 casi e successore
void bst_remove(BST **ptr, int value)
{
    if (*ptr == NULL)
        return;

    if (value < (*ptr)->value)
    {
        bst_remove(&((*ptr)->left), value);
    }
    else if (value > (*ptr)->value)
    {
        bst_remove(&((*ptr)->right), value);
    }
    else if (value == (*ptr)->value)
    {
        if ((*ptr)->left == NULL)
        {
            BST *temp = *ptr;
            *ptr = (*ptr)->right;
            free(temp);
            return;
        }
        else if ((*ptr)->right == NULL)
        {
            BST *temp = *ptr;
            *ptr = (*ptr)->left;
            free(temp);
            return;
        }
        else
        {
            BST *parent = *ptr;
            BST *curr = parent->right;

            while (curr->left != NULL)
            {
                parent = curr;
                curr = curr->left;
            }

            (*ptr)->value = curr->value;

            if (parent == *ptr)
            {
                parent->right = curr->right;
            }
            else
            {
                parent->left = curr->right;
            }

            free(curr);
        }
    }
    else
    {
        return;
    }
}

/* ========================================================================== */
/*                      FUNZIONI DA LISTS.C DEL PROF                          */
/* ========================================================================== */

// Inizializza la lista a NULL
void initList(Node **ptr)
{
    *ptr = NULL;
}

// Inserimento in testa (pre-insert)
void preInsert(Node **ptr, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return;

    newNode->value = value;
    newNode->next = *ptr;

    *ptr = newNode;
}

// Inserimento in coda (suffisso)
void sufInsert(Node **ptr, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return;

    newNode->value = value;
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

// Stampa di tutti gli elementi della lista
void printList(Node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d ", ptr->value);
    printList(ptr->next);
}

// Inserimento ordinato in lista
void ord_insert(Node **ptr, int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;

    if (*ptr == NULL || val <= (*ptr)->value)
    {
        newNode->next = *ptr;
        *ptr = newNode;
        return;
    }

    Node *curr = *ptr;
    while (curr->next != NULL && curr->next->value < val)
    {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

// Clonazione della lista in ordine identico (deep copy)
void clone_list(Node *srcList, Node **destList)
{
    *destList = NULL;
    if (srcList == NULL)
    {
        *destList = NULL;
        return;
    }

    (*destList) = malloc(sizeof(Node));
    if (*destList == NULL)
        return;

    (*destList)->value = srcList->value;
    (*destList)->next = NULL;

    clone_list(srcList->next, &((*destList)->next));
}

/* ========================================================================== */
/*                                    MAIN                                    */
/* ========================================================================== */

int main(void)
{
    printf("=== TEST LISTE (lists.c) ===\n");
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

    printf("LinkedList originale:\n");
    printList(LinkedList);

    initList(&SecondList);
    clone_list(LinkedList, &SecondList);
    printf("SecondList clonata:\n");
    printList(SecondList);

    printf("\n=== TEST BST (bst.c) ===\n");
    BST *bst;
    bst_init(&bst);

    printf("Albero vuoto? %d\n", bst_isEmpty(bst));

    bst_insert(&bst, 2);
    printf("bst vuoto? %d\n", bst_isEmpty(bst));
    bst_insert(&bst, 1);
    bst_insert(&bst, 0);
    bst_insert(&bst, 2);
    bst_insert(&bst, 6);
    bst_insert(&bst, 6);
    bst_insert(&bst, 9);
    bst_insert(&bst, 5);

    printf("Stampa BST:\n");
    bst_print(bst);

    int target = 9;
    printf("\nL'albero contiene %d? %d\n", target, bst_search(bst, target));
    printf("L'albero e' BST? %d\n", bst_isBst(bst));

    BST *mirror_bst = NULL;
    bst_mirror(bst, &mirror_bst);
    printf("\nStampa Mirror BST:\n");
    bst_print(mirror_bst);

    printf("\nRimozione nodo con valore 6...\n");
    bst_remove(&bst, 6);
    bst_print(bst);

    return 0;
}
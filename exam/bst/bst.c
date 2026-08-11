#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct BST
{
    int value;
    struct BST *left;
    struct BST *right;
} BST;

void bst_init(BST **ptr)
{
    *ptr = NULL;
    return;
}

void bst_insert(BST **ptr, int val)
{
    if (*ptr != NULL)
    {
        if (val <= (*ptr)->value)
        {
            bst_insert(&((*ptr)->left), val);
        }
        else
        {
            bst_insert(&((*ptr)->right), val);
        }
    }
    else
    {
        BST *newNode = malloc(sizeof(BST));
        newNode->value = val;
        newNode->left = NULL;
        newNode->right = NULL;

        *ptr = newNode;
    }
}

int bst_isEmpty(BST *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

int bst_search(BST *ptr, int val)
{
    if (ptr == NULL)
        return 0;
    if (ptr->value == val)
        return 1;

    if (val <= ptr->value)
    {
        return bst_search(ptr->left, val);
    }
    else
    {
        return bst_search(ptr->right, val);
    }
}

void bst_print(BST *ptr)
{
    if (ptr == NULL) return;

    printf("%d\n", ptr->value);
    bst_print(ptr->left);
    bst_print(ptr->right);
}

void bst_mirror(BST *srcPtr, BST **destPtr) 
{
    if(srcPtr == NULL){
        *destPtr = NULL;
        return;
    }

    BST *newNode = malloc(sizeof(BST));
    if(newNode == NULL) return;

    newNode->value = srcPtr->value;
    *destPtr = newNode;

    bst_mirror(srcPtr->left, &((*destPtr)->right));
    bst_mirror(srcPtr->right, &((*destPtr)->left));
}

int bst_isInRange(BST *ptr, int min, int max){
    if(ptr == NULL) return 1;

    if(ptr->value <= min || ptr->value > max){
        return 0;
    }

    return bst_isInRange(ptr->left, min, ptr->value) && bst_isInRange(ptr->right, ptr->value, max);
}

int bst_isBst(BST *ptr){
    return bst_isInRange(ptr, INT_MIN, INT_MAX);
}

int main(void)
{
    BST *bst;
    bst_init(&bst);

    printf("Albero vuoto? %d\n", bst_isEmpty(bst));

    bst_insert(&bst, 2);
    printf("bst vuoto? %d\n", bst_isEmpty(bst));
    bst_insert(&bst, 1);
    bst_insert(&bst, 0);
    bst_insert(&bst, 2);
    // bst_insert(&bst, 7);
    bst_insert(&bst, 6);
    bst_insert(&bst, 6);
    bst_insert(&bst, 9);
    bst_insert(&bst, 5);
    // ordinsert_rec(&bst, 2);
    bst_print(bst);

    int target = 9;
    printf("\nL'albero contiene %d? %d\n", target, bst_search(bst, target));

    printf("l'albero è BST? %d", bst_isBst(bst));

    return 0;
}
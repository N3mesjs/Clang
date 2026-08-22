#include <stdio.h>
#include <stdlib.h>

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
    if (*ptr == NULL)
    {
        BST *newNode = malloc(sizeof(BST));
        if (newNode == NULL)
            return;

        newNode->value = val;
        newNode->left = NULL;
        newNode->right = NULL;

        *ptr = newNode;

        return;
    } else if(val > (*ptr)->value){
        bst_insert(&((*ptr)->right), val);
    } else if(val <= (*ptr)->value){
        bst_insert(&((*ptr)->left), val);
    }
}

void bst_remove(BST **ptr, int val){
    if(*ptr == NULL) return;

    if(val < (*ptr)->value) bst_remove(&((*ptr)->left), val);
    else if(val > (*ptr)->value) bst_remove(&((*ptr)->right), val);
    else if(val == (*ptr)->value){
        BST *temp;
        if((*ptr)->left == NULL){
            temp = *ptr;
            *ptr = (*ptr)->right;
            free(temp);
            return;
        }else if((*ptr)->right == NULL){
            temp = *ptr;
            *ptr = (*ptr)->left;
            free(temp);
            return;
        } else {
            BST *parent = *ptr;
            BST *curr = (*ptr)->right;

            while(curr->left != NULL){
                parent = curr;
                curr = curr->left;
            }

            (*ptr)->value = curr->value;

            if(parent == *ptr){
                parent->right = curr->right;
            } else {
                parent->left = curr->right;
            }
            free(curr);
            return;
        }
    }
}

void bst_print(BST *ptr){
    if(ptr == NULL) return;
    printf("%d ", ptr->value);
    bst_print(ptr->left);
    bst_print(ptr->right);
}

int main(void)
{
    BST *bst;
    bst_init(&bst);

    bst_insert(&bst, 8);

    bst_insert(&bst, 3);
    bst_insert(&bst, 4);
    bst_insert(&bst, 2);
    bst_insert(&bst, 1);
    bst_insert(&bst, 5);
    bst_insert(&bst, 10);
    bst_insert(&bst, 9);

    bst_remove(&bst, 3);

    bst_print(bst);
}
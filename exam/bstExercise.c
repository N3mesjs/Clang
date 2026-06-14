#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int value;
    struct BST *left;
    struct BST *right;
} BST;

void bst_init(BST **root){
    *root = NULL;
}

void  bst_insert(BST **root, int value){
    if(*root != NULL){
        if(value < (*root)->value) bst_insert(&((*root)->left), value);
        else bst_insert(&((*root)->right), value);
    } else {
        *root = malloc(sizeof(BST));
        if(*root == NULL){
            printf("malloc failed");
            return;
        }
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
}

void bst_print(BST *root){
    if(root == NULL) return;

    printf("%d\n", root->value);

    bst_print(root->left);
    bst_print(root->right);
}

void bst_delete(BST **node){
    if(*node == NULL) return;

    BST *curr = *node;

    //check se ha un figlio oppure no
    if((*node)->left == NULL){
        *node = (*node)->right;
        free(curr);
    } else if((*node)->right == NULL){
        *node = (*node)->left;
        free(curr);
    } else {
        BST *parentPtr, *tmpPtr;
        tmpPtr = (*node)->right;
        parentPtr = *node;

        while(tmpPtr->left != NULL){
            parentPtr = tmpPtr;
            tmpPtr = tmpPtr->left;
        }

        (*node)->value = tmpPtr->value;

        if(parentPtr == *node){
            parentPtr->right = tmpPtr->right;
        } else {
            parentPtr->left = tmpPtr->right;
        }

        free(tmpPtr);
    }
}

int main(void){
    BST *bst;
    bst_init(&bst);

    bst_insert(&bst, 10);
    bst_insert(&bst, 2);
    bst_insert(&bst, 1);
    bst_insert(&bst, 3);

    bst_insert(&bst, 12);
    bst_insert(&bst, 11);
    bst_insert(&bst, 20);
    bst_insert(&bst, 11);

    bst_print(bst);

    return 0;
}
#include <stdlib.h>
#include <stdio.h>

typedef struct BTree {
    int value;
    struct BTree *left;
    struct BTree *right;
} BST;

int main(void){
    BST *tree;
    init(&tree);


    return 0;
}

void init(BST **ptr){
    *ptr = NULL;
}

void isEmpty(BST *ptr){
    return ptr == NULL;
}

void ordinsert_rec(BST **ptr, int val){
    if((*ptr)!=NULL){
        if(val<=(*ptr)->value){
            ordinsert_rec((*ptr)->left, val);
        } else {
            ordinsert_rec((*ptr)->right, val);
        }
    } else {
        (*ptr) = malloc(sizeof(BST));
        (*ptr)->value = val;
        (*ptr)->left = NULL;
        (*ptr)->right = NULL;
    }
}

int searc_rec(BST *ptr, int val){
    int found = 0;

    if(ptr != NULL){
        if(ptr->value == val){
            found = 1;
        } else {
            if(val>ptr->value){
                found += searc_rec(ptr->right, val);
            } else {
                found += search_rec(ptr->left, val);
            }
        }
    }

    return found;
}
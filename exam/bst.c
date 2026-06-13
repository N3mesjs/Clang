#include <stdlib.h>
#include <stdio.h>

#define COUNT 8

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

void init(Node **ptr){
    *ptr = NULL;
}

void insert_rec(Node **root, int value){
    if(*root != NULL){
        if(value<=(*root)->value){
            insert_rec(&((*root)->left), value);
        } else {
            insert_rec(&((*root)->right), value);
        }
    } else {
        *root = malloc(sizeof(Node));
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
}

/**
 * PRE: N.A.
 * POST: Funzione che ritorna void, si occupa
 * di iterare ricorsivamente per i nodi a sinistra
 * stampando ogni volta che avviene la chiamata
 * ricorsiva e poi si passa alla desta, il tutto partendo
 * dalla root
 */

void print_rec(Node *ptr){
    if(ptr == NULL) return;

    printf("%d\n", ptr->value);

    print_rec(ptr->left);

    //printf("%d\n", ptr->value);

    print_rec(ptr->right);

    //printf("%d\n", ptr->value);
}

void print_bst2D_util(Node *root, int space){
    
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print_bst2D_util(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);
 
    // Process left child
    print_bst2D_util(root->left, space);
}

void print_bst2D(Node *root){
    // Pass initial space count as 0
    print_bst2D_util(root, 0);
}

int main(void){
    Node *tree;
    init(&tree);

    //ROOT
    insert_rec(&tree, 7); 

    //Left side
    insert_rec(&tree, 4);
    insert_rec(&tree, 2);
    insert_rec(&tree, 5);

    //Right side
    insert_rec(&tree, 8);
    insert_rec(&tree, 7);
    insert_rec(&tree, 9);

    print_rec(tree);

    print_bst2D(tree);

    return 0;
}
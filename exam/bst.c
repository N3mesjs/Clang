#include <stdlib.h>
#include <stdio.h>

typedef struct Bst {
    int value;
    struct Bst *left;
    struct Bst *right;
} Bst;

void init(Bst **ptr, int value){
    *ptr = NULL;
}

int main(void){
    Bst *tree;
    
}
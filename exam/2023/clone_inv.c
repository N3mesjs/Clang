#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void preInsert(Node **ptr, int val){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;
    newNode->val = val;
    newNode->next = *ptr;

    *ptr = newNode;
}

void clone_inv(Node *src, Node **dest){
    *dest = NULL;

    while(src != NULL){
        preInsert(dest, src->val);

        src = src->next;
    }
}

int main(void){
    return 0;
}
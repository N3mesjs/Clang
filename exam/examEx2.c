#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

struct btree {
    int value;
    struct btree *leftPtr;
    struct btree *rightPtr;
};
typedef struct btree BTree;

Node* first_odd(Node *list){
    int min;
    Node *ptrMin = NULL;
    if(list == NULL){
        return NULL;
    } 

    while(list != NULL){
        if(list->value % 2 != 0 && (min > list->value || min == 0)){
            min = list->value;
            ptrMin = list;
        }
        list = list->next;
    }
};

Node* first_odd_rec(Node *list){
    if(list == NULL) return NULL;

    Node *ptrMin = first_odd_rec(list->next);

    if(list->value % 2 == 0) return ptrMin;

    if(list->value < ptrMin->value){
        return list;
    } else {
        return ptrMin;
    }
}

void delete_node(BTree **ptrPtr) {
    if(*ptrPtr == NULL) return;

    BTree *curr = *ptrPtr;

    if(curr->rightPtr == NULL){
        *ptrPtr = curr->leftPtr;
        free(curr);
    } else if(curr->leftPtr == NULL){
        *ptrPtr = curr->rightPtr;
        free(curr);
    } else {
        BTree *tmpPtr = curr->rightPtr;
        BTree *parentPtr = curr;

        while(tmpPtr->leftPtr != NULL){
            parentPtr = tmpPtr;
            tmpPtr = tmpPtr->leftPtr;
        }

        curr->value = tmpPtr->value;

        if(curr == parentPtr){
            parentPtr->rightPtr = tmpPtr->rightPtr;
        } else {
            parentPtr->leftPtr = tmpPtr->rightPtr;
        }
        free(tmpPtr);
    }
}

int main(void){
    return 0;
}
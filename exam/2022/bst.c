#include <stdio.h>
#include <stdlib.h>

struct btree {
    int value;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BTree;

/*
 * Esercizio 6: Cancellazione di un nodo da un BST
 * ptrPtr punta direttamente al puntatore al nodo da cancellare (*ptrPtr).
 * Gestisce i 3 casi classici:
 * 1. Nodo foglia (nessun figlio)
 * 2. Nodo con un solo figlio (destro o sinistro)
 * 3. Nodo con due figli (sostituzione con predecessore/successore)
 */
void delete_node(BTree **ptrPtr) {
    if(*ptrPtr == NULL) return;
    BTree *temp;

    if((*ptrPtr)->leftPtr == NULL) {
        temp = *ptrPtr;
        *ptrPtr = (*ptrPtr)->rightPtr;
        free(temp);
        return;
    } else if((*ptrPtr)->rightPtr == NULL) {
        temp = *ptrPtr;
        *ptrPtr = (*ptrPtr)->leftPtr;
        free(temp);
        return;
    } else {
        BTree *parent = *ptrPtr;
        BTree *curr = (*ptrPtr)->rightPtr;

        while(curr->leftPtr != NULL) {
            parent = curr;
            curr = curr->leftPtr;
        }

        (*ptrPtr)->value = curr->value;

        if(parent == *ptrPtr){
            parent->rightPtr = curr->rightPtr;
        } else {
            parent->leftPtr = curr->rightPtr;
        }

        free(curr);
    }
}

// Funzione ausiliaria per inserire in un BST ordinato
void bst_insert(BTree **root, int val) {
    if (*root == NULL) {
        *root = malloc(sizeof(BTree));
        (*root)->value = val;
        (*root)->leftPtr = NULL;
        (*root)->rightPtr = NULL;
        return;
    }
    if (val < (*root)->value) {
        bst_insert(&((*root)->leftPtr), val);
    } else {
        bst_insert(&((*root)->rightPtr), val);
    }
}

// Stampa in-order (deve risultare sempre strettamente crescente)
void print_inorder(BTree *root) {
    if (root == NULL) return;
    print_inorder(root->leftPtr);
    printf("%d ", root->value);
    print_inorder(root->rightPtr);
}

// Funzione per cercare il doppio puntatore a un dato valore (utile per testare delete_node)
BTree** find_node_ptr(BTree **root, int val) {
    if (*root == NULL) return NULL;
    if ((*root)->value == val) return root;
    if (val < (*root)->value) return find_node_ptr(&((*root)->leftPtr), val);
    return find_node_ptr(&((*root)->rightPtr), val);
}

int main(void) {
    BTree *root = NULL;

    // Costruzione BST di test:
    //         50
    //       /    \
    //     30      70
    //    /  \    /  \
    //   20  40  60  80
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        bst_insert(&root, values[i]);
    }

    printf("BST iniziale (in-order): ");
    print_inorder(root);
    printf("\n");

    // Test 1: cancellazione foglia (20)
    BTree **target = find_node_ptr(&root, 20);
    if (target != NULL) delete_node(target);
    printf("Dopo cancellazione di 20: ");
    print_inorder(root);
    printf("\n");

    // Test 2: cancellazione nodo con due figli (es. radice 50 o 30)
    target = find_node_ptr(&root, 30);
    if (target != NULL) delete_node(target);
    printf("Dopo cancellazione di 30: ");
    print_inorder(root);
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* ========================================================================== */
/*                               1. LINKED LIST                               */
/* ========================================================================== */

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Inizializza la lista ponendo il puntatore a NULL
void list_init(Node **ptr) {
    *ptr = NULL;
    return;
}

// Inserimento in testa
void list_preInsert(Node **ptr, int value) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->value = value;
    newNode->next = *ptr;

    *ptr = newNode;
    return;
}

// Inserimento in coda
void list_sufInsert(Node **ptr, int value) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->value = value;
    newNode->next = NULL;

    if(*ptr == NULL){
        *ptr = newNode;
        return;
    }

    Node *curr = *ptr;
    while(curr->next != NULL){
        curr = curr->next;
    }
    
    curr->next = newNode;
    return;
}

// Inserimento mantenendo l'ordine crescente
void list_ord_insert(Node **ptr, int val) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->value = val;
    newNode->next = NULL;

    if(*ptr == NULL || (*ptr)->value > val){
        newNode->next = *ptr;
        *ptr = newNode;
        return;
    }

    Node *curr = *ptr;
    while(curr->next != NULL && curr->next->value < val){
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return;
}

// Cancellazione del primo nodo con valore 'val' (gestendo testa e nodi interni)
void list_remove_val(Node **ptr, int val) {
    if(*ptr == NULL) return;

    if((*ptr)->value == val) {
        Node *tmp = *ptr;
        *ptr = (*ptr)->next;
        free(tmp);

        return;
    }

    Node *curr = *ptr;
    while(curr->next != NULL && curr->next->value != val){
        curr = curr->next;
    }

    if(curr->next == NULL) return;

    Node *tmp = curr->next;
    curr->next = tmp->next;
    free(tmp);

    return;
}

// Clonazione iterativa della lista
void list_clone(Node *srcList, Node **destList) {
    *destList = NULL;
    if(srcList == NULL) return;

    Node *tail;

    while(srcList != NULL){
        Node *newNode = malloc(sizeof(Node));
        if(newNode == NULL) return;

        newNode->value = srcList->value;
        newNode->next = NULL;

        if(*destList == NULL){
            *destList = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
        srcList = srcList->next;
    }

    return;
}

// Clonazione ricorsiva della lista tramite doppio puntatore
void list_clone_rec(Node *srcList, Node **destList) {
    if(srcList == NULL) {
        *destList = NULL;
        return;
    }

    (*destList) = malloc(sizeof(Node));
    if(*destList == NULL) return;

    (*destList)->value = srcList->value;
    (*destList)->next = NULL;

    list_clone_rec(srcList->next, &((*destList)->next));
}

// Stampa iterativa della lista
void list_print(Node *ptr) {
    while(ptr != NULL){
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");

    return;
}


/* ========================================================================== */
/*                        2. BINARY SEARCH TREE (BST)                         */
/* ========================================================================== */

typedef struct BST {
    int value;
    struct BST *left;
    struct BST *right;
} BST;

// Inizializza l'albero ponendo la radice a NULL
void bst_init(BST **ptr) {
    *ptr = NULL;
    return;
}

// Ritorna 1 se l'albero è vuoto, 0 altrimenti
int bst_isEmpty(BST *ptr) {
    if(ptr == NULL) return 1;
    else return 0;
}

// Inserimento ricorsivo di un valore nel BST
void bst_insert(BST **ptr, int val) {
    if(*ptr == NULL) {
        *ptr = malloc(sizeof(BST));
        (*ptr)->value = val;
        (*ptr)->left = NULL;
        (*ptr)->right = NULL;

        return;
    }

    if(val > (*ptr)->value) bst_insert(&((*ptr)->right), val);
    else if(val <= (*ptr)->value) bst_insert(&((*ptr)->left), val);

    return;
}

// Ricerca ricorsiva di un valore nel BST (1 se trovato, 0 altrimenti)
int bst_search(BST *ptr, int val) {
    if(ptr == NULL) return 0;
    if(ptr->value == val) return 1;

    if(val < ptr->value){
        return bst_search(ptr->left, val);
    } else if(val > ptr->value){
        return bst_search(ptr->right, val);
    }
}

// Stampa pre-order dei nodi dell'albero
void bst_print(BST *ptr) {
    if(ptr == NULL) return;

    printf("%d ", ptr->value);
    bst_print(ptr->left);
    bst_print(ptr->right);

    return;
}

// Stampa in-order (visita ordinata crescente)
void bst_inorder(BST *ptr) {
    if(ptr == NULL) return;

    bst_inorder(ptr->left);
    printf("%d ", ptr->value);
    bst_inorder(ptr->right);

    return;
}

// Clona l'albero creando la versione specchiata (mirror)
void bst_mirror(BST *srcPtr, BST **destPtr) {
    if(srcPtr == NULL) {
        *destPtr = NULL;
        return;
    }

    (*destPtr) = malloc(sizeof(BST));
    (*destPtr)->value = srcPtr->value;
    (*destPtr)->left = NULL;
    (*destPtr)->right = NULL;

    bst_mirror(srcPtr->left, &((*destPtr)->right));
    bst_mirror(srcPtr->right, &((*destPtr)->left));
}

// Funzione ausiliaria per verificare se tutti i nodi sono nell'intervallo (min, max]
int bst_isInRange(BST *ptr, int min, int max) {
    if(ptr == NULL) return 1;

    if(ptr->value > max || ptr->value <= min){
        return 0;
    }

    return bst_isInRange(ptr->left, min, ptr->value) &&
           bst_isInRange(ptr->right, ptr->value, max);
}

// Verifica se l'albero rispetta le proprietà di un BST
int bst_isBst(BST *ptr) {
    return bst_isInRange(ptr, INT_MIN, INT_MAX);
}

// Rimozione completa di un nodo in BST (foglia, 1 figlio, 2 figli col successore)
void bst_remove(BST **ptr, int value) {
    if(*ptr == NULL) return;
    
    if(value < (*ptr)->value){
        bst_remove(&((*ptr)->left), value);
    } else if(value > (*ptr)->value){
        bst_remove(&((*ptr)->right), value);
    } else if(value == (*ptr)->value){
        if((*ptr)->left == NULL){
            BST *tmp = *ptr;
            *ptr = (*ptr)->right;
            free(tmp);
            return;
        } else if((*ptr)->right == NULL){
            BST *tmp = *ptr;
            *ptr = (*ptr)->left;
            free(tmp);
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
    } else {
        return;
    }

}


/* ========================================================================== */
/*                                    MAIN                                    */
/* ========================================================================== */

int main(void) {
    printf("==================== TEST LINKED LIST ====================\n");
    Node *list1;
    list_init(&list1);

    printf("1. Test Inserimenti (Testa, Coda, Ordinato):\n");
    list_preInsert(&list1, 20);
    list_preInsert(&list1, 10);
    list_sufInsert(&list1, 40);
    list_ord_insert(&list1, 30);
    list_ord_insert(&list1, 5);
    list_print(list1); // Atteso: 5 -> 10 -> 20 -> 30 -> 40

    printf("\n2. Test Rimozione Valori (Testa: 5, Mezzo: 30):\n");
    list_remove_val(&list1, 5);
    list_remove_val(&list1, 30);
    list_print(list1); // Atteso: 10 -> 20 -> 40

    printf("\n3. Test Clonazione Iterativa:\n");
    Node *listCloneIter;
    list_init(&listCloneIter);
    list_clone(list1, &listCloneIter);
    list_print(listCloneIter);

    printf("\n4. Test Clonazione Ricorsiva:\n");
    Node *listCloneRec;
    list_init(&listCloneRec);
    list_clone_rec(list1, &listCloneRec);
    list_print(listCloneRec);


    printf("\n==================== TEST BST ====================\n");
    BST *tree;
    bst_init(&tree);

    printf("1. Test Albero Vuoto: %d (Atteso: 1)\n", bst_isEmpty(tree));

    bst_insert(&tree, 50);
    bst_insert(&tree, 30);
    bst_insert(&tree, 70);
    bst_insert(&tree, 20);
    bst_insert(&tree, 40);
    bst_insert(&tree, 60);
    bst_insert(&tree, 80);

    printf("2. Test Albero Vuoto dopo inserimenti: %d (Atteso: 0)\n", bst_isEmpty(tree));

    printf("\n3. Stampa Pre-Order:\n");
    bst_print(tree);

    printf("\n4. Stampa In-Order (Crescente):\n");
    bst_inorder(tree);
    printf("\n");

    printf("\n5. Ricerca nodi:\n");
    printf("Cerca 40: %d (Atteso: 1)\n", bst_search(tree, 40));
    printf("Cerca 99: %d (Atteso: 0)\n", bst_search(tree, 99));

    printf("\n6. Validità BST: %d (Atteso: 1)\n", bst_isBst(tree));

    printf("\n7. Test Mirror (In-order deve risultare decrescente):\n");
    BST *treeMirror;
    bst_init(&treeMirror);
    bst_mirror(tree, &treeMirror);
    bst_inorder(treeMirror);
    printf("\n");

    printf("\n8. Test Rimozione (Nodo radice/2 figli: 50):\n");
    bst_remove(&tree, 50);
    printf("In-order dopo remove(50): ");
    bst_inorder(tree);
    printf("\n");

    return 0;
}
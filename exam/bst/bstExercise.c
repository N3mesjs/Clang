#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct BST
{
    int value;
    struct BST *left;
    struct BST *right;
} BST;

// ============================================================================
// --- FUNZIONI BASE GIÀ IMPLEMENTATE ---
// ============================================================================

void bst_init(BST **ptr)
{
    *ptr = NULL;
}

int bst_isEmpty(BST *ptr)
{
    return ptr == NULL;
}

int bst_search(BST *ptr, int val)
{
    if (ptr == NULL) return 0;
    if (ptr->value == val) return 1;

    if (val <= ptr->value)
        return bst_search(ptr->left, val);
    else
        return bst_search(ptr->right, val);
}

void bst_print(BST *ptr)
{
    if (ptr == NULL) return;

    bst_print(ptr->left);
    printf("%d ", ptr->value);
    bst_print(ptr->right);
}

void bst_insert(BST **ptr, int val)
{
    // Caso base: posto libero trovato, allochiamo il nuovo nodo
    if (*ptr == NULL)
    {
        BST *newNode = malloc(sizeof(BST));
        newNode->value = val;
        newNode->left = NULL;
        newNode->right = NULL;
        *ptr = newNode;
        return;
    }

    // Ricerca della posizione corretta
    if (val < (*ptr)->value)
    {
        bst_insert(&((*ptr)->left), val);
    }
    else if (val > (*ptr)->value)
    {
        bst_insert(&((*ptr)->right), val);
    }
    else
    {
        // val == (*ptr)->value: il valore è già presente!
        // Ignoriamo il duplicato per garantire chiavi uniche.
        // printf("Valore %d già presente, ignorato.\n", val);
    }
}

// ============================================================================
// --- PALESTRA BST: COMPLETA LE FUNZIONI SEGUENTI ---
// ============================================================================

void bst_mirror(BST *srcPtr, BST **destPtr)
{
    *destPtr = NULL;

    if(srcPtr == NULL){
        return;
    }

    *destPtr = malloc(sizeof(BST));
    if(*destPtr == NULL) return;

    (*destPtr)->value = srcPtr->value;

    bst_mirror(srcPtr->left, &((*destPtr)->right));
    bst_mirror(srcPtr->right, &((*destPtr)->left));
}

int bst_isInRange(BST *ptr, long long min, long long max)
{
    if(ptr == NULL) return 1;

    if(ptr->value < min || ptr->value > max) return 0;

    return bst_isInRange(ptr->left, min, ptr->value) && bst_isInRange(ptr->right, ptr->value, max);
}

int bst_isBst(BST *ptr)
{
    return bst_isInRange(ptr, INT_MIN, INT_MAX);
}

/**
 * TODO 3: Rimuove il nodo contenente 'value' dal BST.
 * Gestisci i tre casi:
 *  - Caso 1: 0 figli (foglia)
 *  - Caso 2: 1 figlio (sinistro o destro)
 *  - Caso 3: 2 figli (trova il minimo a destra, copia il valore e stacca il nodo)
 */
void bst_remove(BST **ptr, int value)
{
    if(*ptr ==  NULL) return;
    
    if((*ptr)->value > value){
        bst_remove(&((*ptr)->left), value);
    } else if((*ptr)->value < value){
        bst_remove(&((*ptr)->right), value);
    } else {
        if((*ptr)->left == NULL){
            BST *tmp = *ptr;
            *ptr = (*ptr)->right;

            free(tmp);
        } else if((*ptr)->right == NULL){
            BST *tmp = *ptr;
            *ptr = (*ptr)->left;

            free(tmp);
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
        }
    }
}

// ============================================================================
// --- MAIN DI TEST ---
// ============================================================================

int main(void)
{
    BST *bst;
    bst_init(&bst);

    printf("=== TEST 1: Inserimento e Stampa ===\n");
    int valori[] = {5, 3, 7, 1, 4, 6, 9, 2};
    int n = sizeof(valori) / sizeof(valori[0]);

    for (int i = 0; i < n; i++) {
        bst_insert(&bst, valori[i]);
    }

    printf("Stampa In-Order dell'albero (deve essere ordinata): ");
    bst_print(bst);
    printf("\n\n");

    printf("=== TEST 2: Verifica BST ===\n");
    printf("L'albero iniziale è un BST valido? %s\n\n", bst_isBst(bst) ? "SI ✅" : "NO ❌");

    printf("=== TEST 3: Specchio dell'Albero ===\n");
    BST *specchio = NULL;
    bst_mirror(bst, &specchio);
    printf("Stampa In-Order dello specchio (deve essere decrescente): ");
    bst_print(specchio);
    printf("\n\n");

    printf("=== TEST 4: Cancellazione Nodi ===\n");
    
    printf("1. Rimuovo una FOGLIA (nodo 2)...\n");
    bst_remove(&bst, 2);
    printf("   Albero: "); bst_print(bst); printf("\n");

    printf("2. Rimuovo un nodo con 1 FIGLIO (nodo 1)...\n");
    bst_remove(&bst, 1);
    printf("   Albero: "); bst_print(bst); printf("\n");

    printf("3. Rimuovo un nodo con 2 FIGLI (nodo 3)...\n");
    bst_remove(&bst, 3);
    printf("   Albero: "); bst_print(bst); printf("\n");

    printf("4. Rimuovo la RADICE (nodo 5)...\n");
    bst_remove(&bst, 5);
    printf("   Albero: "); bst_print(bst); printf("\n\n");

    printf("L'albero rimanente è ancora un BST valido? %s\n", bst_isBst(bst) ? "SI ✅" : "NO ❌");

    return 0;
}
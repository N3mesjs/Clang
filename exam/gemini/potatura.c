#include <stdio.h>
#include <stdlib.h>

typedef struct nodoAlbero {
    int valore;
    struct nodoAlbero *left;
    struct nodoAlbero *right;
} Albero;

/* Funzione ausiliaria ricorsiva per liberare tutta la memoria di un albero */
void free_tree(Albero *radice) {
    if (radice == NULL) return;
    free_tree(radice->left);
    free_tree(radice->right);
    free(radice);
}

/*
 * PRE: 
 * POST: 
 */
void bst_potatura(Albero **radice, int min, int max) {
    if(*radice == NULL) return;

    if((*radice)->valore <= min || (*radice)->valore > max){
        free_tree(*radice);
    }

    bst_potatura(&((*radice)->left), min, (*radice)->valore);
    bst_potatura(&((*radice)->right), (*radice)->valore, max);
}
#include <stdio.h>
#include <assert.h>

/**
 * PRE: A punta a un array di interi contenente almeno *dim elementi;
 *      dim punta a un intero >= 0 indicante la dimensione iniziale dell'array.
 * POST: A contiene nelle prime *dim posizioni una sequenza ordinata in modo non decrescente
 *       (A[i] <= A[i+1] per ogni 0 <= i < *dim - 1) ottenuta eliminando gli elementi
 *       che violavano l'ordinamento rispetto all'ultimo elemento valido mantenuto;
 *       *dim viene aggiornato con il numero effettivo di elementi rimasti.
 */
void rimuovi_non_ordinati(int A[], int *dim) {
    if(*dim <= 1) return;

    // for(int i=1; i < *dim; i++){
    //     if(A[i] < A[i-1]){
    //         for(int j=i; j< *dim-1; j++){
    //             A[j] = A[j+1];
    //         }

    //         *dim-=1;
    //         i-=1;
    //     }
    // }

    int write = 0;

    for(int i=1; i<*dim; i++){
        if(A[i]>=A[write]){
            write++;
            A[write] = A[i];
        }
    }

    *dim = write + 1;

}

/* ========================================================================== */
/*                               MAIN DI TEST                                 */
/* ========================================================================== */

int main(void) {
    printf("=== TEST rimuovi_non_ordinati ===\n");

    // Test 1: Array vuoto
    int a1[] = {};
    int dim1 = 0;
    rimuovi_non_ordinati(a1, &dim1);
    assert(dim1 == 0);
    printf("[OK] Test 1: Array vuoto -> dim = 0\n");

    // Test 2: Singolo elemento
    int a2[] = {42};
    int dim2 = 1;
    rimuovi_non_ordinati(a2, &dim2);
    assert(dim2 == 1 && a2[0] == 42);
    printf("[OK] Test 2: Singolo elemento -> dim = 1, valore = 42\n");

    // Test 3: Array già ordinato (non elimina nulla)
    int a3[] = {1, 3, 5, 5, 8};
    int dim3 = 5;
    rimuovi_non_ordinati(a3, &dim3);
    assert(dim3 == 5);
    assert(a3[0] == 1 && a3[1] == 3 && a3[2] == 5 && a3[3] == 5 && a3[4] == 8);
    printf("[OK] Test 3: Gia' ordinato -> dim = 5 invariata\n");

    // Test 4: Elementi non ordinati sparsi (es. 5, 2, 8, 3, 9, 1) -> rimangono 5, 8, 9
    int a4[] = {5, 2, 8, 3, 9, 1};
    int dim4 = 6;
    rimuovi_non_ordinati(a4, &dim4);
    assert(dim4 == 3);
    assert(a4[0] == 5 && a4[1] == 8 && a4[2] == 9);
    printf("[OK] Test 4: Elementi misti {5, 2, 8, 3, 9, 1} -> {5, 8, 9} (dim = 3)\n");

    // Test 5: Sequenza strettamente decrescente -> rimane solo il primo elemento
    int a5[] = {10, 8, 6, 4, 2};
    int dim5 = 5;
    rimuovi_non_ordinati(a5, &dim5);
    assert(dim5 == 1 && a5[0] == 10);
    printf("[OK] Test 5: Decrescente {10, 8, 6, 4, 2} -> {10} (dim = 1)\n");

    printf("\nTUTTI I TEST SUPERATI!\n");
    return 0;
}
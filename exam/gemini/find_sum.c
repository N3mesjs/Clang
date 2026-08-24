#include <stdio.h>

/* Prototipo con PRE e POST */

/* 
 * PRE: X punta a un array di interi > 0 di dimensione n >= 0, target >= 0
 * POST: restituisce 1 se esiste una combinazione di elementi di X (anche ripetuti)
 *       la cui somma sia uguale a target, 0 altrimenti
 */
int subset_sum_unbounded(const int X[], int n, int target){
    if(target < 0) return 0;
    if(target == 0) return 1;

    if(n==0) return 0;

    return subset_sum_unbounded(X, n, target - *X) || subset_sum_unbounded(X+1, n-1, target);
}

int main(void) {
    int X[] = {4, 5, 3, 6, 1};
    int n = sizeof(X) / sizeof(X[0]);
    int target = 7;

    int res = subset_sum_unbounded(X, n, target);

    if (res == 1) {
        printf("Esiste una sequenza la cui somma e' %d\n", target);
    } else {
        printf("Nessuna sequenza trovata con somma %d\n", target);
    }

    return 0;
}
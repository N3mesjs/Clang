#include <stdio.h>


/**
 * PRE: n>=1
 * POST: Ritorna la somma dei casi in cui la stringa inizia per 1
 *       e caso in cui iniza per 0
 */
int conta_stringhe(int n){
    if(n==1) return 2;
    if(n==2) return 3;

    return conta_stringhe(n-1) + conta_stringhe(n-2);
}

int conta_stringhe_k_helper(int n, int k, int attuali_uno){
    if(attuali_uno > k) return 0;
    if(n==0) return 1;

    int addZero = conta_stringhe_k_helper(n-1, k, 0);
    int addOne = conta_stringhe_k_helper(n-1, k, attuali_uno + 1);

    return addOne + addZero;
}

int conta_stringhe_k(int n, int k){
    return conta_stringhe_k_helper(n, k, 0);
}

int main(void){
    printf("%d", conta_stringhe(3));
}
#include <stdio.h>

/**
 * PRE: n > 0
 * POST: Returns the number of strings that has no consecutives ones
 */
int conta_stringhe(int n){
    if(n==1) return 2;
    if(n==2) return 3;

    return conta_stringhe(n-1) + conta_stringhe(n-2);
}


int conta_stringhe_k_helper(int n, int k, int occurencies){
    if(occurencies > k) return 0;
    if(n == 0) return 1;

    int insertZero = conta_stringhe_k_helper(n-1, k, 0);
    int insertOne = conta_stringhe_k_helper(n-1, k, occurencies + 1);

    return insertOne + insertZero;
}

/**
 * PRE: n, k > 0 
 * POST: Returns the number of strings that has k consecutives ones
 */
int conta_stringhe_k(int n, int k){
    return conta_stringhe_k_helper(n, k, 0);
}

int main(void){
    printf("%d", conta_stringhe(3));
}
#include <stdio.h>

 

// 
//PRE: n>=0
//POST: Ritorna il numero di modi di scrivere una stringa binara con al più
//      di un 1 consecutivo
int conta_stringhe(int n) {
    if(n==0){
        return 1;
    }
    if(n==1){
        return 2;
    }
    return conta_stringhe(n-1) + conta_stringhe(n-2);
}

int conta_stringhe_k_rec(int n, int k, int occorrenze){
    if(n==0) return 1;

    /**
     * Caso in cui mettiamo lo 0 allora si resettano le occorrenze
     */
    int result = conta_stringhe_k_rec(n-1, k, 0);

    /**
     * Caso in cui andiamo a mettere un 1
     */
    if(occorrenze < k){
        result += conta_stringhe_k_rec(n-1, k, occorrenze+1);
    }

    return result;
}

//PRE: n>=0, k>=0
//POST: Ritorna il numero di modi di scrivere una stringa binara con al più di k
//      di 1 consecutivo
int conta_stringhe_k(int n, int k){
    return conta_stringhe_k_rec(n, k, 0);
}



int main(void) {
   int x;
    scanf("%d", &x); 
    printf("%d\n", conta_stringhe_k(x, 3));
    return 0;
}

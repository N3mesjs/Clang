#include <stdio.h>

/*
 * Implementare una funzione ricorsiva che, dati due array A e B, restituisce:
 * - 1 se tutti i valori di A sono presenti, con lo stesso segno o con segno opposto, in B nello stesso ordine;
 * - 0 altrimenti.
 *
 * Negli esempi seguenti i numeri tra asterischi sono gli elementi di B che fanno sì che la funzione restituisca 1:
 * 1) la funzione restituisce 1 per A={1,-3,2} e B={*1*,9,8,*3*,8,6,*2*,7,9} // 1 3 2 sono presenti in B nello stesso ordine (anche se 3 ha segno opposto)
 * 2) la funzione restituisce 0 per A={1,3,2} e B={1,9,8,4,8,6,2,7,9} // non c'è l'elemento 3
 * 3) la funzione restituisce 0 per A={1,3,2} e B={1,9,8,4,8,6,2,7,3} // il 2 ed il 3 non sono nell'ordine corretto
 * 4) la funzione restituisce 1 per A={1,3,2} e B={*1*,9,8,4,8,6,2,7,*3*,5,*2*} // da B si può estrarre la tripla 1,3,2 che corrisponde ai valori di A
 *
 * N.B. Soluzioni iterative che richiamano la funzione stessa al termine senza calcolare niente ricorsivamente non saranno accettate.
 *
 * - Specificare PRE e POST della funzione implementata
 */

/*
 * PRE: 
 * POST: 
 */
int array_stesso_ordine(int *A, int N, int *B, int M) {
    if(N==0) return 1;
    if(M==0) return 0;

    if(*A == *B || *A == -*B) {
        return array_stesso_ordine(A+1, N-1, B+1, M-1);
    } else {
        return array_stesso_ordine(A, N, B+1, M-1);
    }
    
}

int main(void) {
    int N;
    int M;

    //int A[3] = {1,3,4}; N=3;
    //int B[8] = {1,2,8,7,2,3,4,9}; M=8;

    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", A + i);
    }

    scanf("%d", &M);
    int B[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", B + i);
    }

    printf("%d\n", array_stesso_ordine(A, N, B, M));

    return 0;
}
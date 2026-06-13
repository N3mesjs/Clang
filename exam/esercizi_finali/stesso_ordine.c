#include <stdio.h>

/*
 * Implementare una funzione RICORSIVA che, dati due array A e B, restituisce:
 * - 1 se tutti i valori di A sono presenti, con lo stesso segno o con segno opposto, in B nello stesso ordine
 * - 0 altrimenti
 * 
 * PRE: N>=0 && M>=0
 * POST: La funzione a partire da un elemento di A scorre in B
 * vedendo se trova un suo valore assoluto uguale, notiamo che 
 * l'indice che scorre B si ricorda della sua posizione in modo
 * da verificare che l'ordine sia rispettato
 */

int array_stesso_ordine(int *A, int N, int *B, int M);

int main(void) {
    int N;
    int M;

    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", A+i);
    }

    scanf("%d", &M);
    int B[M];
    for(int i = 0; i < M; i++){
        scanf("%d", B+i);
    }

    printf("%d\n", array_stesso_ordine(A, N, B, M));

    return 0;
}

int array_stesso_ordine(int *A, int N, int *B, int M) {
    if(N==0) return 1;
    if(M==0) return 0;

    if(*A == -(*B) || *A == *B){
        return array_stesso_ordine(A+1, N-1, B+1, M-1);
    } else {
        return array_stesso_ordine(A, N, B+1, M-1);
    }
}
#include <stdio.h>
#include <assert.h>

/* 
    Implementare una funzione che, data una matrice ed un intero k, "elimini" le prime e le ultime k righe dalla matrice.    
*/ 

int matrice_clip_top_bottom(int *mat, int *rows, int *cols,  int k){
    if(k==0) return 1;

    if(k<0 || *rows < 2*k) return 0;

    int elements_save = (*rows - 2 * k) * *cols;
    int source = k * *cols;

    for(int i=0; i<elements_save; i++){
        mat[i] = mat[source + i]; 
    }

    *rows = *rows - 2*k;

    return 1;
}


void main() {

    int righe, colonne, k;

    scanf("%d", &righe);
    scanf("%d", &colonne);
    scanf("%d", &k);

    int mat[righe][colonne];

    /* leggi contenuto matrice da input */
    for(int i =0; i<righe*colonne; i+=1)
        scanf("%d", *mat+i);

    // completate l'invocazione seguente aggiungendo i 4 parametri della funzione (lasciate la funzione all'interno della printf)
    printf("%d\n", 
        matrice_clip_top_bottom(mat, &righe, &colonne, k)
    );

    /* stampa matrice */
    for(int i=0; i<righe; i+=1) {
        printf("%d", mat[i][0]);
        for(int j=1; j<colonne; j+=1)
            printf(" %d", mat[i][j]);
        printf("\n");
    }
}

#include <stdio.h>

/**
 * PRE:
 * POST:
 */
int compatta_matrice(int *mat, int righe, int *colonne, int c){
    if(righe<=0 || *colonne<=1 || c<0 || c>=*colonne) return 0;

    int write_idx = 0;

    for(int i=0; i<righe; i++){
        for(int j=0; j<*colonne; j++){
            if(j != c){
                mat[write_idx] = mat[i* *colonne + j];
                write_idx++;
            }
        }
    }

    (*colonne)--;

    return 1;
}

void printMatrix(int *matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i*cols + j]);
        }
        printf("\n");
    }
}

int main(void){
    int rows = 3;
    int cols = 4;

    int matrix[3][4] = { {3, 4, 5, 3}, {6, 7, 2, 1}, {1, 3, 4, 5} };

    printMatrix(*matrix, rows, cols);
    compatta_matrice(*matrix, rows, &cols, 2);
    printMatrix(*matrix, rows, cols);

    return 0;
}
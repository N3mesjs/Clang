#include <stdio.h>
#include <assert.h>

/* 
    Funzione che modifica una matrice in modo da ottenere la sua riflessa
*/ 


void matrice_riflessa(int *m, int righe, int colonne)
{
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne/2; j++){
            int iLeft = i * colonne + j;
            int iRight = i * colonne + (colonne - 1 - j);
            int temp = m[iLeft];
            m[iLeft] = m[iRight];
            m[iRight] = temp;
        }
    }
}

void consegna_moodle();
void test_matrice_riflessa();

int main() {
    test_matrice_riflessa();
    //consegna_moodle();
}

void consegna_moodle() {

    int n,m,i,j;
    scanf("%d %d", &n, &m);
    int A[n][m];
    for(int i =0; i<n; i+=1)
        for(int j =0; j<m; j+=1)
            scanf("%d", &A[i][j]);

    //matrice_riflessa(...);

    for(int i =0; i<n; i+=1) {
        for(int j =0; j<m; j+=1)
            printf(" %d", A[i][j]);
        printf("\n");
    }
}

void test_matrice_riflessa() {

    int m[][4] = {{1,2,3,4},{5,6,7,8}};
    matrice_riflessa((int *)m, 2, 4);
    assert(m[0][0]==4 && m[1][0]==8 && m[0][1]==3 && m[1][1]==7
        && m[0][2]==2 && m[1][2]==6 && m[0][3]==1 && m[1][3]==5);
    printf("Test superati con successo\n");
}
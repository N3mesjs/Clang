#include <stdio.h>

void rimuovi_tripletta(int *A, int *dim){
    int i=1;
    while(i<*dim-1){
        if(A[i-1] == A[i] && A[i] == A[i+1]){
            for(int j=i; j<*dim; j++){
                A[j] = A[j+1];
            }
            (*dim)--;
        } else {
            i++;
        }
    }
}

int main(void){
    int dim = 7;
    int arr[] = {1,1,1,1,3,1,4};

    rimuovi_tripletta(arr, &dim);

    for(int i=0; i<dim; i++){
        printf("%d", *(arr+i));
    }
    return 0;
}
#include <stdio.h>

void rimuovi_triple(int *arr, int *dim){
    for(int i=0; i<*dim; i++){
        if(arr[i-1] == arr[i] && arr[i] == arr[i+1]){
            for(int j=i; j<*dim; j++){
                arr[j] = arr[j+1];
            }

            *dim-=1;
        }
    }
}

void printArray(int *arr, int dim){
    for(int i=0; i<dim; i++){
        printf("%d ", arr[i]);
    }
}

int main(void){
    int arr[] = {1, 1, 1, 3, 3, 3, 2, 6, 5};
    int dim = 9;

    printArray(arr, dim);
    printf("\n");
    rimuovi_triple(arr, &dim);
    printArray(arr, dim);
}
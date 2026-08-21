#include <stdio.h>

void segrega_pari_dispari_rec(int *arr, int i, int j){
    if(i>=j) return;

    if(arr[i] % 2 == 0){
        segrega_pari_dispari_rec(arr, i+1, j);
        return;
    } if(arr[j] %2 != 0){
        segrega_pari_dispari_rec(arr, i, j-1);
        return;
    }

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    segrega_pari_dispari_rec(arr, i+1, j-1);
}

void segrega_pari_dispari(int *arr, int dim){
    segrega_pari_dispari_rec(arr, 0, dim-1);
}


int main(void){
    int dim = 8;
    int arr[] = {1, 2, 3, 4, 5, 6 ,7 ,8};

    segrega_pari_dispari(arr, 8);

    for(int i=0; i<dim; i++){
        printf("%d", arr[i]);
    }

    return 0;
}
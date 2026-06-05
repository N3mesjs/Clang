#include <stdio.h>
#define ARRAY_SIZE 10
/**
 * Funzione per trovare il valore massimo in un array
 * di interi fatto pero in modo ricorsivo!
 */


int maxValue(int *ar, int size){
    if(size == 1){
        return ar[0];
    }

    int max = maxValue(ar+1, size-1);
    
    return ar[0]>max ? ar[0] : max;
}

int main(){
    int array[ARRAY_SIZE] = {10, 34, 40, 59, 12, 23, 23, 12, 42, 200};

    printf("%d", maxValue(array, ARRAY_SIZE));
    return 0;
}
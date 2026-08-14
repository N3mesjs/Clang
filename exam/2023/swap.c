#include <stdio.h>

void swap_eq(int* arr, int dim, int i, int j, int n) 
{
    if(n==0) return;

    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;

    swap_eq(arr, dim, i+1, j+1, n-1);
}

void swap(int* arr, int dim, int m, int n, int p) 
{
    int lenA = n-m;
    int lenB = p-n;

    if(lenA == lenB){
        swap_eq(arr, dim, m, n, lenA);
    } else if(lenA < lenB){
        swap_eq(arr, dim, m, n, lenA);
        swap(arr, dim, n, n+lenA, p);
    } else if(lenA > lenB){
        swap_eq(arr, dim, n-lenB, n, lenB);
        swap(arr, dim, m, n-lenB, n);
    }
}

int main(void){
    return 0;
}
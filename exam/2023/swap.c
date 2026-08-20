#include <stdio.h>

/*

 */


//PRE:
//POST:
void swap_eq(int* a, int dim, int i, int j, int n) {
    if(n==0) return;

    int temp = a[j];
    a[j] = a[i];
    a[i] = a[j];

    swap_eq(a, dim, i+1, j+1, n-1);
}


//PRE:
//POST:
void swap(int* a, int dim, int m, int n, int p) {
    int lenA = n-m;
    int lenB = p-n;

    if(lenA == lenB){
        swap_eq(a, dim, m, n, lenA);
    } else if(lenA > lenB){
        swap_eq(a, dim, n-lenB, n, p);
        swap(a, dim, m, n-lenB, n);
    } else if(lenA < lenB){
        swap_eq(a, dim, m, n, lenA);
        swap(a, dim, n, n+lenA, p);
    }
}



int main(void) {
    int dim;
    int m;
    int n;
    int p;
    
    scanf("%d", &dim);
    int arr[dim];
    for(int i = 0; i < dim; i++){
        scanf("%d", arr+i);
    }
    
    void print_array(int *a, int d) {
    for (int i = 0; i < d; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

scanf("%d", &m);
scanf("%d", &n);
scanf("%d", &p);

swap(arr, dim, m, n, p); 
print_array(arr, dim);

}

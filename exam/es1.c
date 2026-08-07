#include <stdio.h>

int x=20;

int main() {

    int m[5][3]={21,10,41,34,28,44,22,17,32,40,31,9,15,8,6};
    int *pm = *(m+3)+1; //&m[3][0] + 1 ottieni 31!
    printf("%d", m[2][2]);    //1
    if (x==20) {
        int *p = &m[0][0];
        int **q = &p;
    }
    printf(" %d", *pm);       //2
    //printf(" %d\n", **q+1);   //3
}
#include <stdio.h>

int same_elements(int *pA, int sizeA, int *pB, int sizeB){
    if(sizeA<=0){
        return 1;
    } else if (sizeB<=0){
        return 0;
    }

    if(*pA == *pB || -(*pA) == *pB){
        return(same_elements(pA+1, sizeA-1, pB+1, sizeB-1));
    } else {
        return(same_elements(pA, sizeA, pB+1, sizeB-1));
    }
}

int main(void){
    int A[3] = {1,2,3};
    int B[5] = {1,2,4,5,3};

    printf("%d", same_elements(A, 3, B, 5));
}
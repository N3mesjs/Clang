#include <stdio.h>

void walk(int n){
    if(n <= 0) return;
    walk(n-1);
    printf("I am walking! step no. %d\n", n);
}

int factorial(int n){
    if(n==0) return 1;
    
    return n * factorial(n-1);
}

int factorial_tail(int n, int acc){
    if(n==0) return acc;
    
    return factorial_tail(n-1, n*acc);
}

int pow(int base, int exp){
    if(exp == 0) return 1;
    if(exp == 1) return base;

    return base * pow(base, exp-1);
}

int main(void){
    walk(5);

    printf("il fattoriale di 5 e': %d\n", factorial(5));
    printf("5^7 = %d", pow(7, 5));

    return 0;
}
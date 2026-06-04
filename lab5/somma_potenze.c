#include <stdio.h>

int potenza(int base, int exp){
    if(exp==0){
        return 1;
    }

    return base * potenza(base, exp-1);
}


int somma_pow(int b, int n) {
  if(n==0){
    return 1;
  }

  return potenza(b,n) + somma_pow(b, n-1);
}

int main() {
    int b, n;
    scanf("%d %d", &b, &n);
    printf("%d\n", somma_pow(b, n)); 
    return 0;
}
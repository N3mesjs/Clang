#include <stdio.h>

int potenza(int base, int exp){
    if(exp == 0) return 1;

    return base * potenza(base, exp-1);
}

int potenza_tailHelper(int base, int exp, int acc){
    if(exp == 0) return acc;

    return potenza_tailHelper(base, exp-1, acc * base);
}

int potenza_tail(int base, int exp){
    return potenza_tailHelper(base, exp, 1);
}

int main(void){
    printf("Potenza normale, non tail:\n");
    printf("%d\n", potenza(2,3));

    printf("potena tail recursive\n");
    printf("%d\n", potenza_tail(2,3));
}
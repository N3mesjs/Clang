#include <stdio.h>
#define ARRAY_SIZE 30
/*
    Implementazione efficiente della funzione ricorsiva per il calcolo dei numeri di fibonacci. 
    La funzione fibonacci(n) è definita come: 
                                    0 se n=0 
                                    1 se n=1
        fibonacci(n-1)+fibonacci(n-2) se n>1
    
    L'implementazione standard di fibonacci è inefficiente, in quanto ripete più volte gli stessi calcoli. 
    Modifichiamola aggiungendo una memoria (un array) dove salviamo i valori di fibonacci calcolati e che controlliamo prima di ogni chiamata ricorsiva di fibonacci(x): se il valore fibonacci(x) è già stato calcolato, non invoco la funzione ricorsiva ma restituisco direttamente il valore che avevo salvato nella memoria.  
*/

int fibonacci(int n){
    static int arr[ARRAY_SIZE] = {0};
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(arr[n]!=0){
        return arr[n];
    } 

    arr[n]=fibonacci(n-1)+fibonacci(n-2);

    return arr[n];
}


void test_fibonacci();
void versione_per_consegna_moodle();

int main (void) {
    //test_fibonacci();
    versione_per_consegna_moodle(); 
}

void test_fibonacci() {

    printf("output fibonacci(0):\n");
    printf("%d\n", fibonacci(0));
    printf("\noutput atteso:\n0\n\n");
    
    printf("output fibonacci(1):\n");
    printf("%d\n", fibonacci(1));
    printf("\noutput atteso:\n1\n\n");
    
    printf("output fibonacci(2):\n");
    printf("%d\n", fibonacci(2));
    printf("\noutput atteso:\n1\n\n");
    
    printf("output fibonacci(6):\n");
    printf("%d\n", fibonacci(6));
    printf("\noutput atteso:\n8\n\n");
    
    printf("output fibonacci(8):\n");
    printf("%d\n", fibonacci(8));
    printf("\noutput atteso:\n21\n\n");

}

void versione_per_consegna_moodle(){
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
}
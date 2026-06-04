#include <stdio.h>

/*
    Scrivere una funzione ricorsiva che, dato un intero n>=0, lo stampi convertito in binario. 
    L'algoritmo per la conversione è stato spiegato in una delle prime lezioni. 

    Attenzione: il numero binario non deve iniziare con uno zero.

    Ad esempio se n=4, la funzione deve stampare 100 e non 0100. 
 */


void converti_binario(int n);
void test_converti_in_binario();
void versione_per_consegna_moodle();
 
void converti_binario(int n){
    if(n>1){
        converti_binario(n/2);
    }

    printf("%d", n%2);
}

int main() {

    //test_converti_in_binario();
    versione_per_consegna_moodle();

}


void test_converti_in_binario() {

    printf("output converti_binario(5):\n");
    converti_binario(5);
    printf("\noutput atteso:\n101\n\n");

    printf("output converti_binario(0):\n");
    converti_binario(0);
    printf("\noutput atteso:\n0\n\n");

    printf("output converti_binario(1):\n");
    converti_binario(1);
    printf("\noutput atteso:\n1\n\n");

    printf("output converti_binario(8):\n");
    converti_binario(8);
    printf("\noutput atteso:\n1000\n\n");
    
    printf("output converti_binario(109):\n");
    converti_binario(109);
    printf("\noutput atteso:\n1101101\n\n");

}


void versione_per_consegna_moodle() {

    int n;
    scanf("%d", &n);
    converti_binario(n);

}

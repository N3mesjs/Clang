#include <stdio.h>
#include <stdlib.h>

typedef struct Intervento{
    int id;
    float costo;
    char tipo[50];
} Intervento;

int main(void){
    Intervento *array = malloc(2*sizeof(Intervento));
    if(array==NULL)
    {
        printf("Malloc Error!");
        return 1;
    }
    for (int i = 0; i < 2; i++) {
    printf("\n--- Inserimento Intervento %d ---\n", i + 1);
    
    // 1. Assegno l'ID in automatico basandomi su i
    array[i].id = i + 1; 

    // 2. Chiedo il costo
    printf("Inserisci il costo dell'intervento: ");
    scanf("%f", &array[i].costo);

    // 3. Chiedo il tipo (la descrizione)
    printf("Inserisci il tipo di intervento (max 49 caratteri): ");
    // Nota: usando %s prende solo una parola. 
    // Per sicurezza leggiamo una stringa senza spazi, es: "Cambio_Olio" o "Gomme"
    scanf("%s", array[i].tipo); 
}

    Intervento *temp = realloc(array, 4*sizeof(Intervento));
    if(temp == NULL){
        free(array);
        return 1;
    }

    array = temp;

    printf("\n--- Inserimento Intervento %d ---\n", 3);
    
    // 1. Assegno l'ID in automatico basandomi su i
    array[2].id = 3; 

    // 2. Chiedo il costo
    printf("Inserisci il costo dell'intervento: ");
    scanf("%f", &array[2].costo);

    // 3. Chiedo il tipo (la descrizione)
    printf("Inserisci il tipo di intervento (max 49 caratteri): ");
    // Nota: usando %s prende solo una parola. 
    // Per sicurezza leggiamo una stringa senza spazi, es: "Cambio_Olio" o "Gomme"
    scanf("%s", array[2].tipo); 

    for(int i=0; i<3; i++){
        printf("\nID: %d, Costo: %f, Descrizione dell'intervento: %s\n", array[i].id, array[i].costo, array[i].tipo); 
    }

    free(array);
    return 0;
}
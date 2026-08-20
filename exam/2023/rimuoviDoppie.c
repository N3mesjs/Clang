#include<stdio.h>

/*
    Definire una funzione rimuovi_doppie() che, data una stringa in input, restituisca la stringa stessa con tutte le doppie rimosse.
*/

char * rimuovi_doppie(char *str){
    if(str == NULL || *str == '\0' || *(str+1) == '\0') return str;

    if(*str == *(str+1)){
        char *p = str+2;
        char *dest = str;
        while(*p != '\0'){
            *dest = *p;

            dest++;
            p++;
        }
        
        *dest = '\0';

        rimuovi_doppie(str);
    } else {
        rimuovi_doppie(str+1);
    }

    return str;
}


int main(){

    unsigned int len;
    scanf("%u", &len); 
    char A[len];
    scanf("%s", A); 
    char *s;

    for (s=rimuovi_doppie(A); *s!='\0'; s++)
        printf("%c",*s);
    printf("\n");

}


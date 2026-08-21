#include <string.h>
#include <stdio.h>


/**
 * PRE: C e un carattere valido
 * POST: Ritrona 1 se c e' una vocale maiuscola o minuscola altrimenti 0
 */
int isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
    c == 'A' || c=='E' || c=='I' || c=='O' || c=='U';
}

/**
 * PRE: s puntatore non nullo a una stringa valida
 * POST: inverte ricorsivamente tutte le vocali in place presenti nella porzione
 * s[i]..s[j] mantenendo invariata la posizione degli altri caratteri.
 */
void inverti_vocali_rec(char *s, int i, int j){
    if(i>=j) return;

    if(!isVowel(s[i])){
        inverti_vocali_rec(s, i+1, j);
        return;
    }
    if(!isVowel(s[j])){ 
        inverti_vocali_rec(s, i, j-1);
        return;
    }

    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    inverti_vocali_rec(s, i+1, j-1);
}

char* inverti_vocali(char *s){
    if(s != NULL && *s != '\0'){
        inverti_vocali_rec(s, 0, strlen(s)-1);
    }
    return s;
}

int main(void){
    char string[11] = "universita";
    printf("%s\n", string);

    char *newString = inverti_vocali(string);
    printf("%s\n", newString);
}
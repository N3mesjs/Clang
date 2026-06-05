#include <stdio.h>

/*
 * Enigmistica - Parole intrecciate. 
 * Scrivere una funzione che, data una tabella di caratteri
 * di dimensione 13x15 e una stringa, cerchi se la stringa
 * appare nella tabella: la stringa può apparire scritta:
 * 
 * 1) in orizzontale da sinistra a destra 
 * 2) in orizzontale da destra a sinistra
 * 
 * Se la parola è presente nella tabella, restituire le sue
 * coordinate; se la parola non
 * compare, utilizzare le coordinate -1,-1. 
 * Nel main utilizzare il seguente frammento di codice per 
 * stampare il risultato:
    // gli interi x,y contengono le coordinate,
    // dir è un intero che rappresenta la direzione del match (0 se è da sinistra a destra, 1 viceversa) 
    // parola la parola da cercare
    printf("Parola %s ", parola);
    if (x != -1)
        printf("in (%d,%d), direzione %s\n", x, y, dir==0?"s->d":"d->s");
    else
        printf("non trovata\n");;
 * 
 * Ad esempio nella tabella fornita sotto, se
 * parola_cercata = "Riposo"; allora stampa
    Parola Riposo in (1,0), direzione s->d
 * ATTENZIONE: le parole fornite devono avere solo lettere maiuscole, come la tabella
 */

 int findWord(char matrix[13][16], char *word, int *x, int *y, int *dir){
    int rows = 13;
    int col = 16;
    int strlenght = 0;
    while(word[strlenght]!='\0'){
        strlenght++;
    }

    //lets go trough every row and col
    for(int r=0; r<rows; r++){
        for(int c=0; c<col; c++){
            //left -> right
            for(int i=0; i<strlenght; i++){
                if(word[i]!=matrix[r][c + i]){
                    *x=-1;
                    break;
                }
                if(i==strlenght-1){
                    *x=r;
                    *y=c;
                    *dir=0;
                    return 1;
                }
            }

            //right -> left
            for(int i=0; i<strlenght; i++){
                if(word[i]!=matrix[r][c - i]){
                    *x=-1;
                    break;
                }
                if(i==strlenght-1){
                    *x=r;
                    *y=c;
                    *dir=1;
                    return 1;
                }
            }
        }
    }

    return 0;
 }

int main(void) {

    char tabella[13][16] = { 
        {"EISEOPIDLNOTETM"},
        {"RIPOSOTICUCBAOI"},
        {"ETROPSIVOOINMRL"},
        {"RSINNETIITGSFAA"},
        {"ROCKSPCNTOIOOLM"},
        {"OLAUOSSABLLIRLI"},
        {"CAMPINGZCBDAUYN"},
        {"BCOLLEZIONISMOA"},
        {"ALTIROCONLARCOB"},
        {"LAOIGGANIDRAIGM"},
        {"LIBGCINEMAIERLA"},
        {"OROTALIGUPORITS"},
        {"OTENOIZAMROFNIE"}
        };

    int x, y, dir;
    char parola[256];

    scanf("%255s", parola);

    findWord(tabella, parola, &x, &y, &dir);

    printf("Parola %s ", parola);
    if (x != -1)
        printf("in (%d,%d), direzione %s\n", x, y, dir==0?"s->d":"d->s");
    else
        printf("non trovata\n");

}


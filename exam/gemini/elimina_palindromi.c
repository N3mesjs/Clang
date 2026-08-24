#include <stdio.h>
#include <string.h>
#include <assert.h>

/*
 * PRE: 
 * POST: 
 */
void elimina_palindromi(char *s) {
    if(s==NULL || *s=='\0') return;

    int len = strlen(s);
    int delMap[50] = {0};

    for(int i=0, j=len-1; i<=j; i++, j--){
        if(i==j){
            delMap[i] = 1;
        } else if(s[i] == s[j]){
            delMap[i] = 1;
            delMap[j] = 1;
        }
    }

    int write = 0;
    for(int read = 0; read<len; read++){
        if(!delMap[read]){
            s[write++] = s[read];
        }
    }
    s[write] = '\0';
}

/* ========================================================================== */
/*                               MAIN DI TEST                                 */
/* ========================================================================== */

int main(void) {
    printf("=== TEST elimina_palindromi ===\n");

    // Test 1: Esempio traccia "parlai" -> "prli" ('a' in pos 1 e pos 4 uguali)
    char t1[50] = "parlai";
    elimina_palindromi(t1);
    assert(strcmp(t1, "prli") == 0);
    printf("[OK] Test 1: \"parlai\" -> \"%s\" (Atteso: \"prli\")\n", t1);

    // Test 2: Esempio traccia "parlo" -> "palo" (carattere centrale 'r' eliminato)
    char t2[50] = "parlo";
    elimina_palindromi(t2);
    assert(strcmp(t2, "palo") == 0);
    printf("[OK] Test 2: \"parlo\" -> \"%s\" (Atteso: \"palo\")\n", t2);

    // Test 3: Esempio traccia "palo" -> "palo" (lunghezza pari, nessuna coppia palindroma)
    char t3[50] = "palo";
    elimina_palindromi(t3);
    assert(strcmp(t3, "palo") == 0);
    printf("[OK] Test 3: \"palo\" -> \"%s\" (Atteso: \"palo\")\n", t3);

    // Test 4: Esempio traccia "anna" -> "" (tutti i caratteri eliminati)
    char t4[50] = "anna";
    elimina_palindromi(t4);
    assert(strcmp(t4, "") == 0);
    printf("[OK] Test 4: \"anna\" -> \"%s\" (Atteso: \"\")\n", t4);

    // Test 5: Stringa vuota "" -> ""
    char t5[50] = "";
    elimina_palindromi(t5);
    assert(strcmp(t5, "") == 0);
    printf("[OK] Test 5: \"\" -> \"%s\" (Atteso: \"\")\n", t5);

    // Test 6: Singolo carattere "a" -> "" (essendo centrale va eliminato)
    char t6[50] = "a";
    elimina_palindromi(t6);
    assert(strcmp(t6, "") == 0);
    printf("[OK] Test 6: \"a\" -> \"%s\" (Atteso: \"\")\n", t6);

    printf("\nTUTTI I TEST SUPERATI!\n");
    return 0;
}
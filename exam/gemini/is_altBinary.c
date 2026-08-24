#include <stdio.h>

int rec_check(const char *s, int expected){
    if(s == NULL) return 0;
    if(*s == '\0') return 1;

    if(*s != expected + '0'){
        return 0;
    }

    if(expected == 0){
        expected = 1;
    } else {
        expected = 0;
    }

    return rec_check(s+1, expected);
}

/**
 * PRE: s puntatore a una stringa C valida, che termina per '\0', composta solo da 1 e 0
 * POST: restituisce 1 se si ha una stringa vuota, o una stringa binaria che inizia per 1
 * e ha numeri alterni, no doppioni, 0 se inizia per 0 o non rispetta la clausola
 */

int is_alt_binary(const char *s){
    return rec_check(s, 1);
}

int main(void) {
    // Array di test: stringa e risultato atteso
    struct {
        const char *input;
        int expected;
    } tests[] = {
        {"", 1},          // Stringa vuota valida
        {"1", 1},         // Singolo '1' valido
        {"10", 1},        // Alternanza valida
        {"101", 1},       // Alternanza valida
        {"1010", 1},      // Alternanza valida
        {"101010101", 1}, // Sequenza lunga valida
        {"0", 0},         // Non inizia con '1'
        {"01", 0},        // Inizia con '0'
        {"0101", 0},      // Inizia con '0' anche se alternata
        {"11", 0},        // Due '1' consecutivi
        {"1001", 0},      // Due '0' consecutivi
        {"1011", 0},      // Due '1' consecutivi
        {"101001", 0},    // Due '0' consecutivi a metà
        {"1010110", 0}    // Due '1' consecutivi verso la fine
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    printf("=== AVVIO TEST is_alt_binary ===\n\n");

    for (int i = 0; i < num_tests; i++) {
        int res = is_alt_binary(tests[i].input);
        if (res == tests[i].expected) {
            printf("[OK] Test %2d superato: \"%s\" -> %d\n", i + 1, tests[i].input, res);
            passed++;
        } else {
            printf("[FAIL] Test %2d FALLITO: \"%s\" -> ottenuto %d, atteso %d\n", 
                   i + 1, tests[i].input, res, tests[i].expected);
        }
    }

    printf("\nRisultato: %d/%d test superati.\n", passed, num_tests);

    return 0;
}
#include <stdio.h>


int str_len(const char *s){
    if(*s == '\0') return 0;

    return 1+str_len(s+1);
}

int rec_check(const char *s, int left, int right){
    if(s == NULL) return 0;
    if(left >= right) return 1;

    if(s[left] == ' ') return rec_check(s, left+1, right);
    if(s[right] == ' ') return rec_check(s, left, right-1);

    if(s[left] != s[right]) return 0;

    return rec_check(s, left+1, right-1);
}

int is_palindrome_spaces(const char *s){
    return rec_check(s, 0, str_len(s)-1);
}


int main(void) {
    struct {
        const char *input;
        int expected;
    } tests[] = {
        {"", 1},
        {"a", 1},
        {"radar", 1},
        {"  ", 1},
        {"r a d a r", 1},
        {"ingegni", 1},
        {" in ge g ni ", 1},
        {"evitativ e", 1},
        {"ciao", 0},
        {"ab a b", 0},
        {"algo", 0},
        {"ra darx", 0}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    printf("=== TEST is_palindrome_spaces ===\n\n");

    for (int i = 0; i < num_tests; i++) {
        int res = is_palindrome_spaces(tests[i].input);
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
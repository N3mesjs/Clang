#include <stdio.h>
#include <string.h>

int pal_ignore_aux(char *s, int i, int j, char c) {
    if(i>=j) return 1;

    if(s[i] == c) return pal_ignore_aux(s, i+1, j, c);
    if(s[j] == c) return pal_ignore_aux(s, i, j-1, c);

    if(s[i]!=s[j]) return 0;

    return pal_ignore_aux(s, i+1, j-1, c);
}

int pal_ignore(char *s, char c) {
    return pal_ignore_aux(s, 0, strlen(s) - 1, c);
}

int main() {
    char s[100];
    char c;

    scanf("%99s", s);
    scanf(" %c", &c);  
    
    int result = pal_ignore(s,c);
    printf("%d\n", result); // stampa risultato

    return 0;
}
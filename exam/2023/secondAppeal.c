#include <stdio.h>

/*
 * PRE: 
 * POST: 
 */
void copyString(char* src, char* dest) {
    *dest = *src;

    if(*src == '\0') return;

    copyString(src+1, dest+1);
}

/*
 * PRE: 
 * POST: 
 */
void shuffle(char* s1, char* s2, char* r) {
    if(*s1 == '\0'){
        copyString(s2, r);
        return;
    } else if(*s2 == '\0'){
        copyString(s1, r);
        return;
    }

    *r = *s1;
    *(r+1) = *s2;

    shuffle(s1+1, s2+1, r+2);
}

/*
 * PRE: 
 * POST: 
 */
void intToString(int n, char* s) {
    if(n==0){
        *s = '0';
        *(s+1) = '\0';

        return;
    }

    *s = n%10 + '0';

    intToString(n/10, s+1);
}

int main() {
    int num;
    char digits[20];
    scanf("%d", &num);
    intToString(num, digits);
     
    char s1[10], s2[10], result[20];
    scanf("%s", s1);
    scanf("%s", s2);
    shuffle(s1, s2, result);
    
    printf("%s\n", digits);
    printf("%s\n", result);

    return 0;
}
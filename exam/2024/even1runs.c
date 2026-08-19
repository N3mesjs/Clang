#include <stdio.h>

int rec_check(char *s, int state){
    if(*s == '\0') return (state == 0) ? 1 : 0;

    if(*s == '1' && state == 1){
        state = 0;
    } else if(*s == '1' && state == 0){
        state = 1;
    } else if(*s == '0' && state == 1){
        return 0;
    }

    return rec_check(s+1, state);
}

int even1runs(char *s) {
    return rec_check(s, 0);
}

int main(void) {

    char s[50];
    scanf("%s", s);
    printf("%d", even1runs(s));
    
}

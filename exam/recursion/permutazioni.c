#include <stdio.h>
#include <string.h>

void swap(char *char1, char *char2){
    char temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}

void permuta(char *str, int start, int end){
    if(start == end) {
        printf("%s\n", str);
        return;
    }

    for(int i=start; i<end; i++){
        swap(str+start, str+i);

        permuta(str, start+1, end);

        swap(str+start, str+i);
    }
}

int main(void) {
    char s[] = "123";
    int n = strlen(s);

    printf("Tutte le permutazioni di \"%s\":\n", s);
    permuta(s, 0, n);

    return 0;
}
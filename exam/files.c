#include <stdio.h>

int main(){
    FILE *pFile = fopen("output.txt", "w");

    if(pFile == NULL){
        return 1;
    }

    char string[] = "BOOTY BOOTY\nJINGER NIGGERSAAA";

    fprintf(pFile, "%s", string);

    fclose(pFile);

    FILE *pFile2 = fopen("output.txt", "r+");

    char buffer[1024] = {0};

    while(fgets(buffer, 10240, pFile2)){
        printf("%s", buffer);
    }

    return 0;
}
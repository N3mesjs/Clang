#include <stdio.h>
#include <stdlib.h>

struct Point {
    float x;
    float y;
};

int main(){
    struct Point *array = malloc(20 * sizeof(struct Point));
    if(array == NULL){
        printf("Error with malloc");

        return 1;
    }

    for(int i=0; i<20; i++){
        array[i].x = i*10 / 3;
        array[i].y = i*20 / 3;
    }

    struct Point *temp = realloc(array, 40 * sizeof(struct Point));

    if(temp == NULL){
        printf("Trouble with realloc!");
        free(array);
        return 1;
    }

    array = temp;

    for(int i=20; i<40; i++){
        array[i].x = i*10 / 3;
        array[i].y = i*20 / 3;
    }

    for(int i=0; i<40; i++){
        printf("%d: Coordinates x:%.2f | y:%.2f\n", i, array[i].x, array[i].y);
    }

    free(array);
    return 0;
}
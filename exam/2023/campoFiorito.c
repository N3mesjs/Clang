#include <stdio.h>

#define DIM_X 5
#define DIM_Y 5

int mossa(int arr[][DIM_Y], int x, int y){
    if(x<0 || x>=DIM_X || y<0 || y>=DIM_Y || arr[x][y] == 0){
        return 0;
    }

    if(x==0){
        return 1;
    }

    return mossa(arr, x-1, y) + mossa(arr, x, y+1);
}


int main(void) {

    int campo[DIM_X][DIM_Y]={
                         {0,0,0,1,1},
                         {0,1,1,1,1},
                         {1,0,1,1,0},
                         {1,0,1,1,1},
                         {1,0,1,0,0}
                    };
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);

    printf("Numero di percorsi da %d,%d alla riga 0: %d\n", x, y, mossa(campo, x, y));
}

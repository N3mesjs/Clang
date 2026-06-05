#include <stdio.h>

int exponent(int base, int exp)
{
    if(exp==0)
    {
        return 1;
    } else if(base == 0)
    {
        return 0;
    } else if(exp==1){
        return base;
    }

    return base*exponent(base, exp-1);
}

int main(){
    printf("%d", exponent(3,3));
    return 0;
}
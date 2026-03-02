#include <limits.h>
#include <stdio.h>


/**
 * We can define macros, that are replaced by the preprocessor 
 * before compilation, in this case we are defining x as the 
 * maximum value of an int, which is defined in limits.h
 * 
 * The pros of using macros is that it doesn't cost
 * memory and time when compilint, and its defined globally,
 * the cons is that when debugging, the value of x will not 
 * be shown, and it can lead to confusion
 */
#define x INT_MAX

int main() {
    /**
     * There is also %ld for long int
     */
    printf("%d\n", x);

    float f = 3.1451123;
    printf("%.2f\n", f); //this ways we can specify the number of 
                         //digits after the decimal point, this can lead to precision loss

    return 0;
}
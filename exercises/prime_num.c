#include <stdio.h>

int isPrime(int n)
{
    int prime = 1;
    if (n < 2)
    {
        return 0;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            prime = 0;
        }
    }
    return prime;
}

void printPrimeNum(int n)
{
    if (n <= 50){
        if(isPrime(n)){
            printf("%d\n", n);
        }
        return printPrimeNum(n + 1);
    }
}

int main()
{
    int startingNum = 1;
    printPrimeNum(startingNum);
}
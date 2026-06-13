#include <stdio.h>
#include <string.h>

//es 1
int sumArrayRec(int *ptr, int n);

//es 2
void reverse_string(char *str, int left, int right);

//es 3
int is_palindrome(char *str, int left, int right);

//es 4
int power(int base, int exp);

//es 5
int count_occurrences(int *arr, int n, int val);

//es 6
int max_array(int *arr, int n);

//es 7
int is_sorted(int *arr, int n);

//es 8
int sum_digits(int n);

//es 9
int reverse_number(int n, int acc);

//es 10
int mcd(int a, int b);


int main(void){
    char str[] = "ciaobelli";
    reverse_string(str, 0, strlen(str)-1);

    printf("%s\n", str);

    printf("%d\n", power(2,8));
}

int sumArrayRec(int *ptr, int n){
    if(n==0) return 0;

    return *ptr + sumArrayRec(ptr+1, n-1);
}

void reverse_string(char *str, int left, int right){
    if(left >= right) return;

    char tmp;
    tmp = str[left];
    str[left] = str[right];
    str[right] = tmp;
    
    reverse_string(str, left+1, right-1);
}

int is_palindrome(char *str, int left, int right){
    if(left >= right) return 1;

    if(str[left] != str[right]) return 0;

    return is_palindrome(str, left+1, right-1);
}

int power(int base, int exp){
   if(exp == 0) return 1;
   if(exp == 1) return base;

   return base * power(base, exp-1);
}

int count_occurrences(int *arr, int n, int val){
    if(n==0) return 0;

    return (*arr == val) + count_occurrences(arr+1, n-1, val);
}

int max_array(int *arr, int n)
{
    if(n==1) return *arr;

    int maxRest = max_array(arr + 1, n-1);

    if(*arr<maxRest) return maxRest;
    else return *arr;
}

int is_sorted(int *arr, int n){
    if(n==1) return 1;

    if(*arr<=*(arr+1)) return is_sorted(arr+1, n-1);
    else return 0;
}

int sum_digits(int n){
    if(n==0) return 0;

    return n % 10 + sum_digits(n/10);
}

int reverse_number(int n, int acc){
    if(n==0) return acc;

    return reverse_number(n/10, acc*10 + n%10);
}

int mcd(int a, int b){
    if(b==0) return a;

    return mcd(b, a%b);
}
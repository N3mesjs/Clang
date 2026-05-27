#include <stdio.h>

int matrix[][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};

int array[5] = {0};

char str1[] = "CIACOOO"; //{'C', 'I', ... , '\0'}
char *str2 = "Sono Figo";

int main(){
  printf("%d\n", (matrix[0] + 3)[0]);

  int (*p)[5] = &array;

  str1[0] = 'X';
  printf("%s\n", str1);

  //str2[0] = 'X';
  printf("%s\n", str2);

  printf("size of str1: %d", (sizeof(str1)/sizeof(str1[0])));
  return 0;
}
#include <stdio.h>

void permutazioni(char *str, int left, int right)
{
    if (left == right)
    {
        printf("%s\n", str);
        return;
    };
    for (int i = left; i <= right; i++)
    {
        // swap
        char tmp = str[left];
        str[left] = str[i];
        str[i] = tmp;

        permutazioni(str, left + 1, right);

        // reswap identico
        char tmp2 = str[left];
        str[left] = str[i];
        str[i] = tmp2;
    }
}

int main(void)
{
    char str[] = "cacca";
    permutazioni(str, 0, 4);

    return 0;
}
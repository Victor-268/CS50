#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    for (int i = 1; i <= n; i++)
    {
        for (int a = n; a > i; a--)
        {
            printf(" ");
        }
        for (int b = 0; b < i; b++)
        {
            printf("#");
        }
        printf("  ");
        for (int c = 0; c < i; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}

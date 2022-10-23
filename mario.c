#include <cs50.h>
#include <stdio.h>

int main(void)
//ask for height
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    // now for the pyramid

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }
        
        {
            printf("#");
        }
        printf("\n");
    }
}
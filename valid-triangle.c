#include <cs50.h>
#include <stdio.h>

int valid_triangle(int a, int b, int c); // we declare the function

int main(void)
{
    int a = get_int("first side: ");
    int b = get_int("second side: ");
    int c = get_int("third slide: ");

    int z = valid_triangle(a, b, c); //uses the function
}

int valid_triangle(a, b, c) //we define the function
{
    if (a + b < c )
    {
        printf("false:/\n");
        return 0;
    }
    if(a < 0 || b < 0 || c < 0)
    {
        printf("false:/\n");
        return 0;
    }

    printf("true!\n");
    return 0;
}
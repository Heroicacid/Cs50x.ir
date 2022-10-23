#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int only_digits(int a);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("usage: ./caesar key\n");
            return 1;
        }
        if (isalpha(argv[1][i]))
        {
            printf("usage: ./caesar key\n");
            return 1;
        }
        
        int k = atoi(argv[1]);
        
        string s = get_string("plaintext: ");
        printf("ciphertext: ");
        
        for (int j = 0; j < strlen(s); j++)
        {
            
            if (isupper(s[j]))
            {
                printf("%c", 65 + ((s[j] - 65) + k) % 26);
            }
            else if (islower(s[j]))
            {
                printf("%c", 97 + ((s[j] - 97) + k) % 26);
            }
            else
            {
                printf("%c", s[j]);
            }
        
        }
        printf("\n");
        return 0;
    }
}
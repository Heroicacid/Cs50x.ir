#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //prompt user for input
    string text = get_string("Text: ");
    
    //claculation
    int l = count_letters(text); //letters
    
    int words = count_words(text);
    
    int s = count_sentences(text); //sens
    
    //print the Grade
    float L = (l * 100) / words;
    float S = (s * 100) / words;
    
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int s = 0;
    
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            s++;
        }
    }
    return s;
}

int count_words(string text)
{
    int w = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            w ++;
        }
    }
    return w;
}

int count_sentences(string text)
{
    int j = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            j++;
        }
    }
    return j;
}
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    string text = get_string("Text: ");

    int wordcount = 1;
    int sentencecount = 0;
    int lettercount = 0;

    // code that computes average number of letters in 100 words
    // for loop counting until 100 words, putting the ammount in an array, then calculating the average
    // inlcude counter for . 
    // include counter for " "
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            wordcount++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencecount++;
        }
        if (isalpha(text[i]))
        {
            lettercount++;
        }
    }

    float averagel = ((float) lettercount / wordcount) * 100;
    float averages = ((float) sentencecount / wordcount) * 100;

    float value = (0.0588 * averagel) - (0.296 * averages) - 15.8;

    if (value < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (value < 16)
    {
        printf("Grade %.0f\n", value);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

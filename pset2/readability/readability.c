#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

// L is the average number of letters per 100 words in the text
double letters_rete(char *text)
{
    int i = 0;
    int count_letters = 0;
    int count_words = 0;
    int word_flag = 0;
    double ratio;
    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            count_letters++;
            word_flag = 1;
        }
        if (isspace(text[i]) && word_flag == 1)
        {
            count_words++;
            word_flag = 0;
        }
        i++;
    }
    if (word_flag == 1)
    {
        count_words++;
    }
    ratio = ((round(count_letters * 10000 / count_words))) / 100;
    return (ratio);
}

// S is the average number of sentences per 100 words in the text.
double sentences_rate(char *text)
{
    int i = 0;
    int count_sentences = 0;
    int count_words = 0;
    int word_flag = 0;
    double ratio;

    while (text[i] != '\0')
    {
        if (isalpha(text [i]))
        {
            word_flag = 1;
        }
        if (word_flag == 1)
        {
            if (text[i] == '.' || text[i] == '?' || text[i] == '!')
            {
                count_sentences++;
            }
            if (isspace(text[i]))
            {
                count_words++;
                word_flag = 0;
            }
        }
        i++;
    }
    if (word_flag == 1)
    {
        count_words++;
    }
    ratio = ((round(count_sentences * 10000 / count_words))) / 100;
    return (ratio);
}

int main(void)
{
    char *text;
    double index;
    double letters;
    double sentences;

    text = get_string("Text: ");
    letters = letters_rete(text);
    sentences = sentences_rate(text);
    // Coleman-Liau index
    index = 0.0588 * letters - 0.296 * sentences - 15.8;
    index = (int) round(index);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int) index);
    }
    return (0);
}

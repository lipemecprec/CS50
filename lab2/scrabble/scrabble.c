#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

char *to_lower_case(string word)
{
    int i = 0;
    
    while (word[i] != '\0')
    {
        if ('A' <= word[i] && word[i] <= 'Z')
        {
            word[i] = word[i] + ('a' - 'A');
        }
        i++;
    }
    return word;
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    int letter;
    int i = 0;
    word = to_lower_case(word);
    while (word[i] != '\0')
    {
        if ('a' <= word[i] && word[i] <= 'z')
        {
            letter = word[i] - 'a';
            score = score + POINTS[letter];
        }
        i++;   
    }
    return (score);
}


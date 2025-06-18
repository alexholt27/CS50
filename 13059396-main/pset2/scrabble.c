#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);

const int LETTER_VALUES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Prompt the user for the 2 words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Determine the score for each word
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    // Print toal score counts
    printf("Player 1 Score: %i - Player 2 Score: %i\n", score1, score2);

    // Print the winner based off the returned scores
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Initialize score counter
    int score = 0;

    // Compute score for each individual character
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += LETTER_VALUES[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += LETTER_VALUES[word[i] - 'a'];
        }
    }
    // Returns the final score for the given word
    return score;
}

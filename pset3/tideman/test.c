#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

int candidate_count = 3;

int checkloop(int winner, int loser)
{
    int i;
    int opa;

    i = 0;
    if(locked[winner][loser] == true)
    {
        while(i < candidate_count)
        {
            if(locked[loser][i] == 1)
                break;
            i++;
        }
    }
    if (i == candidate_count)
        return (1);
    return (0);
}

int main()
{
    locked [0][1] = true;
    // locked [2][0] = true;

    int loop;
    int i;
    int j;

    i = 0;
    while (i < candidate_count)
    {
        locked[1][2] = true;
        j = 0;
        while (j < candidate_count)
        {
            loop = checkloop(1, 2);
            j++;
        }
        if (loop == 1)
        {
            printf("OPA!");
        }
        i++;
    }
    return (0);
}
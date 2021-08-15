#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    int i;

    i = 0;
    while (i < candidate_count)
    {
        if(strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
        i++;
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int i;
    int j;

    i = 0;
    while (i < candidate_count)
    {
        j = i + 1;
        while (j < candidate_count)
        {
            preferences[ranks[i]][ranks[j]]++;
            j++;
        }
        i++;
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int i;
    int j;
    int k;

    k = 0;
    i = 0;
    while (i < MAX)
    {
        j = i + 1;
        while (j < MAX)
        {
            if (!(preferences[i][j] == preferences[j][i]))
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[k].winner = i;
                    pairs[k].loser = j;
                }
                else
                {
                    pairs[k].winner = j;
                    pairs[k].loser = i;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    pair_count = k;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int i;
    int j;
    int a;
    int b;
    pair temp;

    i = 0;
    while (i < pair_count)
    {
        j = 0;
        while (j < pair_count)
        {
            a = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
            b = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            if (b > a)
            {
                temp = pairs[j];
                pairs[j] = pairs[i];
                pairs[i] = temp;
            }
            j++;
        }
        i++;
    }
    return;
}

int checkloop(int winner, int loser)
{
    if(locked[winner][loser] == true)
    {
        i = 0;
        while(i < candidate_cout)
        {
            locked[loser][i];
            i++;
        }
        return (1);
    }
    return (0);
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int loop;
    int i;
    int j

    i = 0;
    while (i < candidate_count)
    {
        locked[pair[i].winner][pair[i].loser] = true;
        while (j < candidate_count)
        {
            loop = checkloop(pair[i].winner, pair[i].loser);
        }
        if (loop == 1)
        {
            locked[pair[i].winner][pair[i].loser] = false;
        }
        i++;
    }



    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}


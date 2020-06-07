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

            if (!vote(j, name, ranks)) //pass j value as the value set to the ranks[] array -- j represents the ranking, that is put into ranks array
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
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp (name, candidates[i]) == 0) // candidates[i]
        {
            ranks[rank] = i;
            //printf("%i\n", rank);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO

    // preferences array works like a win - loss comparison
    // fire beats grass, water beats fire, grass beats water, etc.

    /*for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] = 0; //initialize all elements in the array to be equivalent to 0
        }
    }*/

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++) //initializes after (helps avoid comparisions where i == j
        {
            /*printf("\nComparing %i to %i\n", ranks[i], ranks[j]);*/

            if (i < j) // don't need to use ranks[i] < rank[j] because that compares value (name) not position order
            {
                preferences[ ranks[i] ][ ranks[j] ]++;
            }
            /*else if (i == j)
            {
                *do nothing*;
            }*/
            /*else
            {
                preferences[ranks[j]][ranks[i]]++; //removing else statement as it would compare all values twice
            }*/
        }
    }

    /*for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i == j)
            {
                preferences[ranks[i]][ranks[j]] = 0;
            }
            else //this would adjust for the earlier mistake, but why adjust for a mistake when you can just not make the mistake in the first place
            {
                preferences[ranks[i]][ranks[j]] = preferences[ranks[i]][ranks[j]] / 2;
            }
        }
    }*/

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("The value at (%i, %i) is %i\n", i, j, preferences[i][j]);
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO

    for (int i = 0; i < candidate_count; i++) //the levels of a for loop are no different than changing bases on an irregular count
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i]) //adding || (and less than <) would add all values twice
            {
                printf("Assigning Winner Value: %i and: Loser Value %i to Pairs value: %i\n", i, j, (i* candidate_count) + j);

                pairs[(i * candidate_count) + j].winner = i + 1; //the code starting here will only execute when for loop j executes, and will assign a victory value for i + j
                pairs[(i * candidate_count) + j].loser = j + 1; // why am I assigning + 1? makes it easier to distinguish than a victory for candidate 0 over another

                pair_count++;
                printf("Pair Count: %i\n", pair_count);
            }
            // asking else if less than would make all values log twice
        }
    }

    for (int i = 0; i < (candidate_count * candidate_count); i++)
    {
        printf("Pairs Value at %i:  W: %i   L: %i\n", i, pairs[i].winner, pairs[i].loser);
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}


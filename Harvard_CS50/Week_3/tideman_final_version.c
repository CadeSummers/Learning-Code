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

bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp (name, candidates[i]) == 0) 
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[])
{

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++) 
        {

            if (i < j) 
            {
                preferences[ ranks[i] ][ ranks[j] ]++;
            }
        }
    }

    return;
}

void add_pairs(void)
{

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pair k; 
                k.winner = i;   
                k.loser = j;    
                pairs[pair_count] = k;
                pair_count++;
            }
        }
    }

    return;
}

void sort_pairs(void)
{

    int winner_count[MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; 

        int lose_hold, win_hold;

        lose_hold = win_hold = 0;

        for (int i = 0; i < pair_count; i++)
        {
             for (int j = 0; j < pair_count; j++)
             {
                 if (pairs[i].winner == j)
                 {
                     winner_count[j]++;
                 }
             }
        }

         for (int i = 0; i < pair_count; i++)
         {
             for (int j = 0; j < pair_count; j++)
             {
                if (winner_count[i] > winner_count[j])
                {
                    win_hold = pairs[j].winner;
                    lose_hold = pairs[j].loser;
                    pairs[j].winner = pairs[i].winner;
                    pairs[j].loser = pairs[i].loser;
                    pairs[i].winner = win_hold;
                    pairs[i].loser = lose_hold;
                }
             }
         }
         
    return;
}

void lock_pairs(void)
{
    int final_input = 0; 
    
    for (int i = 0; i < candidate_count; i++)
    {
        locked[ pairs[i].winner ][ pairs[i].loser ] = true;
        
        final_input = i;
    }
    
    int true_count = 0; 
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true) 
            {
                true_count++;
                i++;
                j = 0;
            }
        }
    }
    
    if (true_count >= candidate_count - 1) 
    {
        locked[ pairs[ final_input ].winner][ pairs[ final_input ].loser] = false;
    }
    
    return;
}

void print_winner(void)
{
    
    int true_count, victor_points;
    true_count = victor_points = 0;
    
    int victor_index = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
                true_count++;
                if (true_count > victor_points)
                {
                    victor_points = true_count;
                    victor_index = i;
                }
            }
        }
        true_count = 0;
    }
    
    printf("%s\n", candidates[victor_index]);
    
    return;
}

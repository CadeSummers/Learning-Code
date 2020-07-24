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
        for (int j = i + 1; j < candidate_count; j++) //initializes after (helps avoid comparisions where i == j)
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

    /*for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("The value at (%i, %i) is %i\n", i, j, preferences[i][j]);
        }
    }*/
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO

    //
    /*k = 0
    for all i indicies in candidate_count  //(0 through candidate_count)
        for all j indicies in candidate_count
            if (i < j):
                // add pair
                pair p
                p.winner = i
                p.loser = j
                pairs[k] = p
                k++*/

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pair k; // fill only with winning pairs?
                k.winner = i;   //to distinguish from unfilled, you may add  +1 if desired
                k.loser = j;    //to distinguish from unfilled, you may add  +1 if desired
                pairs[pair_count] = k;
                pair_count++;
            }
        }
    }

    /*for (int i = 0; i < candidate_count; i++) //the levels of a for loop are no different than changing bases on an irregular count
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i]) //adding || (and less than <) would add all values twice
            {
                printf("Assigning Winner Value: %i and: Loser Value %i to Pairs value: %i\n", i, j, (i* candidate_count) + j);

                pairs[(i * candidate_count) + j].winner = i + 1; //the code starting here will only execute when for loop j executes, and will assign a victory value for i + j
                pairs[(i * candidate_count) + j].loser = j + 1; // why am I assigning + 1? makes it easier to distinguish than a victory for candidate 0 over another

                //the above are indices and you are treating

                pair_count++;
                printf("Pair Count: %i\n", pair_count);
            }
            // asking else if less than would make all values log twice
        }
    }*/

    /*for (int i = 0; i < (candidate_count * candidate_count); i++)
    {
        printf("Pairs Value at %i:  W: %i   L: %i\n", i, pairs[i].winner, pairs[i].loser);
    }*/
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO

    /*for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 1; j < candidate_count; j++) //initializing j @ 1 b/c j == 0 will pick up extra pairs
        {
            //CADE DO THIS
            //COUNT UP VICTORIES OF WINNER OVER LOSER
            //CREATE INDEX OF VICTORIES
            //SORT BY STRENGTH OF VICTORY
            //IF TIE AT VICTORY POSITION ONE AND TWO HAVE EQUAL STRENGTH, NULL VICTORY
            if (pairs[i].winner == j)
            {
                for (int k = 0; k < candidate_count * candidate_count; k++)
                {

                }
            }
        }
    }*/

    int winner_count[MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // MAX SUGGESTED I USE PREFERENCES

    /*for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            if (pairs[i].winner == j && pairs[i].winner != pairs[i].loser)
            {
                for (int k = i; k < candidate_count; k++) //using candidate count because victories are indicated by # of candidates, not pairs
                {
                    if (pairs[k].winner == pairs[i].winner)
                    {
                        while (pairs[k].loser != 0 && pairs[k].winner != 0)
                        {
                            winner_count[i]++;
                        }
                    }
                }
            }
        }
    }*/

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

        /*printf("\n");

        for (int i = 0; i < MAX; i++)
        {
            printf("Number of Victories for Candidate #%i is %i \n", i, winner_count[i]);
        }*/

         //ACTUAL SORT STARTING HERE

         /*printf("\nUNSORTED PAIRS LIST:\n");

         for (int i = 0; i < pair_count; i++)
         {
             printf("Winner:%i \tLoser:%i\n", pairs[i].winner, pairs[i].loser);
         }*/

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

         /*printf("\nSORTED PAIRS LIST:\n");

         for (int i = 0; i < pair_count; i++)
         {
             printf("Winner:%i \tLoser:%i\n", pairs[i].winner, pairs[i].loser);
         }*/

         /*int loser_count, loser_count2;// ITS THE SAME THING HAS HAVING THE MOST WIN FEATURES

         loser_count = loser_count2 = 0;

         for (int i = 0; i < pair_count; i++)
         {
             for (int j = 0; j < pair_count; j++)
             {
                 if (pairs[i].winner == j)
                 {
                    loser_count++;
                 }
             }

         }*/

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    
    
    /*for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (condition that prevents us from logging a cycle)
            {
                
            }
            else if (pairs[i].winner)
            {
                locked
            }
        }
    }*/
    
    int final_input = 0; 
    
    for (int i = 0; i < candidate_count; i++)
    {
        locked[ pairs[i].winner ][ pairs[i].loser ] = true;
        
        /*if ( (locked[ pairs[i].winner ][ pairs[i].loser ] == true && locked[ pairs[i].loser][ pairs[i].winner ] == true) && i == candidate_count - 1)
        {
            locked[ pairs[i].winner ][ pairs[i].loser ] = false;
        }*/
        
        final_input = i;
    }
    
    int true_count = 0; // a cycle occurs only when there is a true value on every row of locked
    
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
    
    /*printf("Final Input Value: %i\n", final_input);
    printf("Pairs value at coordinates of Final input: \nWinner:%i, Loser:%i \n", pairs[ final_input].winner, pairs [final_input].loser);*/
    
    if (true_count >= candidate_count - 1) //if there is a true value on every input row, undo the last input row. Works because pairs are sorted by victory strength, last input is weakest victory
    {
        locked[ pairs[ final_input ].winner][ pairs[ final_input ].loser] = false; //reseting the value to false to prevent cycle
    }
    
    /*int losses[MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //represents the number of loses for a given candidate
    int last_place = 0; //represents the value of the candidate in last place. If no candidate is in last place, then the closest last place value = 0
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == false)
            {
                losses[i]++;
            }
        }
    }
    
    int max_loses = candidate_count - 1; //represents the maximum number of times a candidate can lose
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (losses[i] == max_losses)
        {
            break;
        }
        else if (i == candidate_count - 1)
        {
            for (int)
        }
    }*/
    
    /*for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (losses[j] > last_place);
            {
                last_place = j;
            }
            
            if ((losses[i] == last_place && losses[j] == last_place) && i != j) //if the candidate in the last place is tied with another candidate
            {
                locked[i][j] = false;
                locked[j][i] = true;
            }
        }
    }*/
    
    /*printf("\nVALUES OF LOCKED:\n");
    printf("1 == TRUE, 0 == FALSE\n\n");
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("The Value of Locked at (%i, %i) is %i\n", i, j, locked[i][j]);
        }
    }*/
    
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    
    int true_count, victor_points;
    true_count = victor_points = 0;
    
    int victor_index = 0;
    
    //all of the below may need to go inside of an if/else statement to prevent ties
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true) // 
            {
                true_count++;
                if (true_count > victor_points)
                {
                    victor_points = true_count;
                    victor_index = i;
                }
                /*else if (true_count == victor_points && j == candidate_count - 1) //tie condition
                {
                    printf("Election has been tied.\n");
                }*/
            }
        }
        true_count = 0;
    }
    
    printf("%s\n", candidates[victor_index]);
    
    return;
}


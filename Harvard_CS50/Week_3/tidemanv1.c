#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];
int victories[MAX][MAX];  //the first cell of this array represents the victories of candidate 0 over 1, the second 1 over
int winsarr[2][MAX];
//char names[999]; // stores names, later to be converted into different information

int rank_count = 0; //for assigning rank/ columns
int pref_rows = 0; // for assigning rows
int global_count = 0; //global count

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
int victor;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs();
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
        /*for (int j = 0; j < candidate_count; j++)
        {
            
        }*/
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
            /*else if (vote(j, name, ranks))  //check for proper ordering
            {
                rank_count--;
                for (int x = 0; x < candidate_count; x++)
                {
                    printf("%i\n", preferences[pref_rows][x]);
                }
            }*/
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
    //TODO
    rank_count++;
    
    for (int i = 0; i < candidate_count; i++) // i is checking the names, per a total count of candidate_count
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            
            if (rank_count > candidate_count)  //if encountering issues after 4/22/2020, consider changing this to >= or = rather than >
            {
                pref_rows++;
                rank_count = 1; // initialize at one, due to reduced placement
            }
            
            preferences[pref_rows][rank_count - 1] = i;
            //printf("%i\n", preferences[pref_rows][rank_count - 1]);
            //printf("%i\n", candidate_count);
            
            return true;   
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])  //because I'm calling this function multiple times, I am going row by row, rather than matchup by matchup
{
    //tier out the value of each persons 1st vote compared to 2nd compared to 3rd etc...
    global_count++;
    
    /*printf("PREFERENCES ARRAY\n");
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i is the value at (%i , %i) \n", preferences[i][j], i, j); 
        }    
    } */
    
    printf("\n");
    
    for (int i = 0; i < candidate_count; i++) // AFFECTS THE CORRECT ELEMENTS IN THE ARRAY !!! YAY!!!! ... but i need to make sure it's the correct value
    {
        int x = preferences[global_count - 1][i];  //x represents the "winner" or the column representing the candidate we r talking about in a given iteration of this loop
        
        int victory_points = candidate_count - i - 1;  //candidate_count -1 also possible, i is basically "the margin of points A has beaten B by"
        
        for (int j = x + 1; j != x; )
        {
            if (i > j) //in the event that a vote is A > B > C, this check prevents B from logging victory points over A. 
            {
                if (j >= candidate_count)
                {
                    j = j - candidate_count;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                /*printf("vicpoints value is %i\n", victory_points);*/
                victories[x][j] += victory_points;
                
                if (j >= candidate_count)
                {
                    j = j - candidate_count;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    
    /*printf("VICTORIES ARRAY\n");
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i is the value at (%i , %i) \n", victories[i][j], i, j); 
        }    
    }*/
    
    printf("\n");
    
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i == j)
            {
                locked[i][j] = false; //there are no cells where a one candidated has a victory of themselves
            }
            /*else if (j == candidate_count) //IS IT NECESSARY?? -- logical check of whether or not we need to check the last element to the first element
            {
                if (victories[i][j] > victories[i][0])
                {
                    locked[i][j] = true;
                }
                else
                {
                    locked[i][j] = false;
                }
            }*/
            else if (victories[i][j] > victories[j][i])
            {
                locked[i][j] = true; //statement which confers victories[i][j] victory over ''[i][j + 1]
            }
            else
            {
                locked[i][j] = false; //statement which confers victories[i][j] loss to ''[i][j + 1]
            }
        }
    }
    
    /*for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("The value at %i , %i is %i.\n", i, j, locked[i][j]);
        }
    }*/
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    //int winsarr[2][candidate_count]; //tracks the winners, one row keeps track of value of votes, the other keeps track of names
    
    for (int i = 0; i < candidate_count; i++)
    {
        winsarr[0][i] = i; // "name" of candidate as an array column, count is second dimension
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        winsarr[1][i] = 0;  // keeps the "count" of votes
    }
    
    for (int i = 0; i < candidate_count; i++) // inefficient check, I only need to witness half the values and none on the diagonal.
    {
        for (int j = 0; j < candidate_count; j++)
        {
           if (locked[i][j] == true && i != j)
           {
              winsarr[1][i]++; // adds a "point" to an arry representative of who won that "matchup"
           }
        }
    }
    
    int holder, holder2;
    holder = holder2 = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (winsarr[1][i] > winsarr[1][j])
            {
                //printf("holder becomes winsarr[0][%i] \n", winsarr[0][i]);
                
                holder = winsarr[0][i];
                holder2 = winsarr[1][i];
                
                //printf("\n", winsarr[0][i]);
                
                winsarr[0][i] = winsarr[0][j];
                winsarr[1][i] = winsarr[1][j];
                
                //printf("\n", winsarr[0][i]);
                
                winsarr[0][j] = holder;
                winsarr[1][j] = holder2;
            }
        }
    }
    
    /*printf("Victory Order:\n");
    
    for (int i = 0; i < candidate_count; i++)
    {
        printf("Rank %i: %i \n", i, winsarr[0][i]); // arrange candidate victories in order [2, 0, 0] implies a win, but only for wins of A, need B & C
    }
    printf("\n");*/
    return; 
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs()
{
    // TODO
    int largest = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (winsarr[1][i] > largest) //prevents cycles (fire beats grass, grass beats water, water beats fire, etc)
        {
            //printf("winsarr 1 - i : %i\n", winsarr[1][i]);
            largest = winsarr[1][i];
        }
    }
    
    //printf("largest: %i\n", largest);
    
    /*for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {}
            
    }*/
    
    if (largest == winsarr[1][0] && winsarr[1][1] == largest) //FAULTY; keeps resulting times
    {
        printf("Candidates tied.\n");
        return;
    }
   
    victor = winsarr[0][0]; //change to print name of winner IF I NEED TO PUT STUFF IN print_winner() MAKE VICTOR GLOBAL VARIABLE AND ACCESS
    
    //printf("%s\n", candidates[victor]); //prints winner
    
    return;
    
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    
    printf("%s\n", candidates[victor]); //prints winner
    
    return;
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int voter_count;

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name) // THIS FINALLY WORKS 
{
    // make sure of valid vote
    int n = 0;
    
    while (n <= candidate_count)
    {
        while (strcmp(name, candidates[n].name) == 0)
        {
            candidates[n].votes++;
            return true;
        }
        n++;
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int c = 0;
    
    string winner = candidates[c].name;
    while (c < candidate_count)
    {
        if (candidates[c].votes > (voter_count/2))
        {
            printf("%s has won the election!", candidates[c].name);
            return;
        }
        c++;
    }
    
    int x = 1; //x is the range of comparison between two elements (the comparison and the 1st and the 3rd (x = 2), 5th and 9th (x = 4), etc.)
    c--;
    
    while ((c - x) >= 0)
    {
        if (candidates[c].votes > candidates[c - x].votes)
        {
            //printf("%s changes to %s\n", candidates[c - x].name, candidates[c].name);
            candidates[c - x].votes = candidates[c].votes;
            candidates[c - x].name = candidates[c].name;
            c = c - x;
        }
        else if (candidates[c].votes < candidates[c - x].votes)
        {
            //printf("%s changest to %s\n", candidates[c].name, candidates[c-x].name);
            candidates[c].votes = candidates[c - x].votes;
            candidates[c].name = candidates[c - x].name;
            c = c - x;
        }
        else if (candidates[c].votes == candidates[c - x].votes)
        {
            //printf("2 adjacent elements have the same value\n");
            x++;
            if (x > candidate_count - 1)
            {
                x = 1;
            }
        }
    }
    printf("%s has won the election!\n", candidates[c].name);
    return;
}
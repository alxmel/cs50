#include <cs50.h>
#include <stdio.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{


    // Check for valid candidates
    for (int i = 0; i < candidate_count; i++) {
        // If candidate is valid
        if (candidates[i].name == name) {

            // Update voter preference ranking with candidate's index and return true
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Looping through every voter
    for (int i = 0; i < voter_count; i++) {
        // Looping through each candidate
        for (int j = 0; j < candidate_count; j++) {
            if (!candidates[preferences[i][j]].eliminated) {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // calculating the number of votes needed to win
    int votes_needed_to_win = (voter_count / 2);

    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > votes_needed_to_win) {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Setting a big number to start narrowing down who has the lowest number of votes
    int lowest_votes = 100;

    // Keep track of the index of the candidate with the lowest number of votes
    int candidate_index;

    // for each candidate in the number of candidates
    for (int i = 0; i < candidate_count; i++) {
        // candidate is not eliminated
        if (!candidates[i].eliminated) {
            if (candidates[i].votes < lowest_votes) {
                lowest_votes = candidates[i].votes;
                candidate_index = i;
            }
        }
    }

    // returning the lowest number of votes
    return lowest_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // for each candidate
    for (int i = 0; i < candidate_count; i++) {
        // if the candidate is not eliminated
        if (!candidates[i].eliminated) {
            // if any of the candidates's votes don't match the min, then it is not a tie
            if (candidates[i].votes != min) {
                return false;
            }
        }
    }

    // If false isn't returned, then return true because there is a tie
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Looping through each candidate
    for (int i = 0; i < candidate_count; i++) {
        // If the candidate is still in the race
        if (!candidates[i].eliminated) {
            // Check if the candidate has the lowest number of votes
            if (candidates[i].votes == min) {
                // Eliminate the candidate
                candidates[i].eliminated = true;
            }
        }
    }
}

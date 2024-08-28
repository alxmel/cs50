// Linear Search
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    int strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // Getting string to look for in the Array
    int s = get_string("String: ");

    // Implementing Linear Search
    for (int i = 0; i < 6; i++) {
        // The 'strcmp()' function is how we compare strings in C
        // it specifically returns an int, 0 for a match, which is why
        // we are comparing to 0 instead of a string
        // returns 0 if two strings are equal
        if (strcmp(strings[i], s) == 0) {
            printf("Found number\n");

            return 0;
        }
    }

    printf("Not Found \n");
    return 1;
}


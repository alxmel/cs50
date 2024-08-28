// Linear Search
#include <cs50.h>
#include <stdio.h>

int main(void) {

    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // Getting number to look for in the Array
    int n = get_number("Number: ");

    // Implementing Linear Search
    for (int i = 0; i < 7; i++) {
        if (number[i] == n) {
            printf("Found number\n");

            // return here includes a way to break out of main.
            // If we didn't have a way to break out of main, then we
            // would get "Not Found" alwasy printed after "Found number"
            // below since it is outside of the loop.
            // This is how we make sure we handle meeting the criteria correctly.
            return 0;
        }
    }

    // Notice how we print not found OUTSIDE of the loop. We only want to print
    // Not Found once if n was not found in the entire array.
    printf("Not Found \n");
    return 1;
}


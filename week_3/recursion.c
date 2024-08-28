#include <cs50.h>
#include <stdio.h>

/*
This is a regular iterative example, using for loops
*/


void draw(int n);

int main(void) {
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n) {
// Recursion doesn't really use loops. For Loops are an indication of iteration, not recursion.
// That being said, you CAN still use For Loops in your Recursive Functions.


    // This is the "fail safe", this is how you break out of a Recursive function
    // You don't have to return anything, you can just simply return to break out
    // Officially known as "Base Case"
    // If nothing to draw
    if (n <= 0) {
        return;
    }


    // recursive call to itself
    // Print pyramid of height n - 1
    draw(n - 1);

    // Print one more row
    for (int i = 0; i < n; i++) {
        printf("#");
    }

    printf("\n");



}

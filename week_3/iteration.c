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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}

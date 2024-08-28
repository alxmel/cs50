#include <stdio.h>
#include <cs50.h>

// Getting the user input
int main(void) {

    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++) {
        // Spaces
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        // left side hashes
        for (int k = 0; k <= i; k++) {
            printf("#");
        }

        // print double space gap
        printf("  ");

        // right side hashes
        for (int l = 0; l <= i; l++) {
            printf("#");
        }

        // newline
        printf("\n");

    }
}

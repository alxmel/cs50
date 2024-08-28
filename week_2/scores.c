#include <stdio.h>
#include <cs50.h>

int main(void) {
    // This is telling the computer to reserve enough memory for an Array with 3 items
    int scores[3];

    // Index starts at 0
    int scores[0] = 72;
    int scores[1] = 73;
    int scores[2] = 33;

    // Getting the average using all Array items. Dividing by a float
    // Becuase this will automatically convert the numerator to use floats as well
    // no need to re-cast the varaibles above as float, they can stay as int.
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0)
}

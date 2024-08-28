#include <cs50.h>
#include <stdio.h>
#include <string.h>

// THis is how in C we define a new data type
typedef struct {
    string name;    // String Attribute named 'name'
    string number;  // String Attribute named 'number'
} person; // Here is where we name the new datatype


int main(void) {

    // Here is how we use the new data type.
    // Creating an array named people that will hold 3 objects and they
    // are of type 'person', that we created above
    person people[3];

    // Access the attributes by using a period
    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found: %s\n", people[i].number);
            return 0;
        }
    }

    printf("Not found.\n");
    return 1;
}

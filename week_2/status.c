#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {


    if (argc != 2) {
        printf("Missing command-line argument\n");
        // Returning a status code after program is run. This is error
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    // Return all good
    return 0;
}

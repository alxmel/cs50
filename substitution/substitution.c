#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {

    int length_of_key = 0;
    char alphabet[26] = {'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z'};

    // Failing program if invalid number of argumetns provided.
    if (argc != 2) {
        printf("ERROR: Invalid number of arguments. Please only provide 1 argument.\n");

        return 1;
    }

    // Checking key length
    for (int i = 0; i < strlen(argv[1]); i++) {
        length_of_key++;
    }

    // Failing program if key is invalid length
    if (length_of_key != 26) {
        printf("ERROR: Invalid key length. Key must contain 26 characters\n");
        return 1;
    }

    // Failing program if any character is not alphabetic
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!isalpha(argv[1][i])) {
            printf("ERROR: Please only input letters in the key.\n");
            return 1;
        }
    }


    // Boolean array to keep track of letters seen
    bool seen[26] = {false};

    // Failing program if any duplicates are found
    for (int i = 0; i < strlen(argv[1]); i++) {
        int index = toupper(argv[1][i]) - 'A';
        if (seen[index]) {
            printf("ERROR: Duplicate letter found in key, please use each letter only once.\n");
            return 1;
        } else {
            seen[index] = true;
        }
    }


    // If there are any letters not included, fail the program
    for (int i = 0; i < 26; i++) {
        if (!seen[i]) {
            printf("ERROR: Not all letters in the alphabet were used. Please use every letter in the alphablet.\n");
            return 1;
        }
    }

    // Asking user for plaintext input
    string plaintext = get_string("plaintext: ");


    // Printing ciphertext before printing the actual cipher:
    printf("ciphertext: ");

    // converting key to all uppercase
    for (int i = 0; i < strlen(argv[1]); i++) {
        argv[1][i] = toupper(argv[1][i]);
    }

    // Looping through user's input
    for (int i = 0; i < strlen(plaintext); i++) {
        // preserving case if capital
        if (isupper(plaintext[i])) {
            int pos = plaintext[i] - 'A';
            char cipher_char = toupper(argv[1][pos]);
            printf("%c", cipher_char);
        } else if (islower(plaintext[i])) { // preserving case if lowercase
            int pos = plaintext[i] - 'a';
            char cipher_char = tolower(argv[1][pos]);
            printf("%c", cipher_char);
        } else { // otherwise, just print the character
            printf("%c", plaintext[i]);
        }
    }

    // New line after printing cipher text
    printf("\n");

    // Return 0 on success
    return 0;

}



#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calc_score(string word);

int main(void) {

    // Asking for player words
    string player_one = get_string("Player 1: ");
    string player_two = get_string("Player 2: ");


    // Comparing who has the higher score
    if (calc_score(player_one) > calc_score(player_two)) {
        printf("Player 1 wins!\n");
    } else if (calc_score(player_one) < calc_score(player_two)) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

}

int calc_score(string word) {

    // running score counter
    int word_score = 0;

    // Array containing 1 point letters
    char one_point[10];
    one_point[0] = 'A';
    one_point[1] = 'E';
    one_point[2] = 'I';
    one_point[3] = 'L';
    one_point[4] = 'N';
    one_point[5] = 'O';
    one_point[6] = 'R';
    one_point[7] = 'S';
    one_point[8] = 'T';
    one_point[9] = 'U';

    // Array containing 2 point letters
    char two_points[2];
    two_points[0] = 'D';
    two_points[1] = 'G';

    // Array containing 3 point letters
    char three_points[4];
    three_points[0] = 'B';
    three_points[1] = 'C';
    three_points[2] = 'M';
    three_points[3] = 'P';

    // Array containing 4 point letters
    char four_points[5];
    four_points[0] = 'F';
    four_points[1] = 'H';
    four_points[2] = 'V';
    four_points[3] = 'W';
    four_points[4] = 'Y';

    // Array containing 5 point letters
    char five_points[1];
    five_points[0] = 'K';

    // Array containing 8 point letters
    char eight_points[2];
    eight_points[0] = 'J';
    eight_points[1] = 'X';

    // Array containing 10 point letters
    char ten_points[2];
    ten_points[0] = 'Q';
    ten_points[1] = 'Z';

    // Outer loop iterating through input
    for (int i = 0, n = strlen(word); i < n; i++) {
        // Looping through one_point array to score 1 point if letter matches
        for (int one = 0; one < 10 ; one++) {
            if (toupper(word[i]) == one_point[one]) {
                word_score++;
            }
        }

        // Repeating for 2 points
        for (int two = 0; two < 2; two++) {
            if (toupper(word[i]) == two_points[two]) {
                word_score += 2;
            }
        }

        // Repeating for 3 points
        for (int three = 0; three < 4; three++) {
            if (toupper(word[i]) == three_points[three]) {
                word_score += 3;
            }
        }

        // Repeating for 4 points
        for (int four = 0; four < 5; four++) {
            if (toupper(word[i]) == four_points[four]) {
                word_score += 4;
            }
        }

        // Repeating for 5 points
        for (int five = 0; five < 1; five++) {
            if (toupper(word[i]) == five_points[five]) {
                word_score += 5;
            }
        }

        // Repeating for 8 points
        for (int eight = 0; eight < 2; eight++) {
            if (toupper(word[i]) == eight_points[eight]) {
                word_score += 8;
            }
        }

        // Repeating for 10 points
        for (int ten = 0; ten < 2; ten++) {
            if (toupper(word[i]) == ten_points[ten]) {
                word_score += 10;
            }
        }
    }

    // Returning the final score
    return word_score;
}


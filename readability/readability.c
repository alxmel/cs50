#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Week 2 - Exercise 2: Readability


// index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words
// S = average number of sentences per 100 words

int get_letters(string word);
int get_words(string word);
int get_sentences(string sentence);

int main(void) {
    string placeholder = get_string("Text: ");

    float letters = get_letters(placeholder);
    float words = get_words(placeholder);
    float sentences = get_sentences(placeholder);

    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int index_rounded = round(index);

    if (index_rounded < 1) {
        printf("Before Grade 1\n");
    } else if (index_rounded >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index_rounded);
    }


}

// Function to return the number of letters in a string
int get_letters(string word) {
    int letter_count = 0;

    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            letter_count++;
        }
    }

    return letter_count;

}

// Function to get spaces
int get_words(string word) {
    int word_count = 0;

    for (int i = 0; i < strlen(word); i++) {
        if (isspace(word[i])) {
            word_count++;
        }
    }

    // Adding 1 more to the space_count, to account for the final word not followed by space
    word_count++;

    return word_count;
}

// Counting number of sentences
int get_sentences(string sentence) {
    int sentence_count = 0;

    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?') {
            sentence_count++;
        }
    }

    return sentence_count;

}

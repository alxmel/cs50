#include <stdio.h>
#include <cs50.h>

int main(void) {

    //int credit_card = get_int("Enter Credit Card Number: ");
    long credit_card = get_long("Number: ");
    long dupe_credit_card = credit_card;
    int running_sum;
    int card_number_length = 0;
    int counter = 1;
    int running_sum_even = 0;
    int running_sum_odd = 0;


    //int card_check = credit_card % 10;

    // Loop through credit card numbers
    while (credit_card > 0) {
        // Get the final digit
        int card_final_digit = credit_card % 10;

        // Starting from the 2nd to last digit and moving to the first digit
        if (counter % 2 == 0) {

            // Multiply final digit by 2
            int final_digit_doubled = card_final_digit * 2;

            // Check if there are 2 digits, then Add doubled final digit to the running sum
            if (final_digit_doubled > 9) {
                // Repeat the process to sum both digits
                int temp_digit_1;
                int temp_digit_2;

                // Grabbing final digit
                temp_digit_1 = final_digit_doubled % 10;
                // Shortening the digit to get the first
                final_digit_doubled /= 10;
                // Grabbing first digit
                temp_digit_2 = final_digit_doubled;

                // Summing them together
                int temp_sum = temp_digit_1 + temp_digit_2;

                // Adding to our running sum
                running_sum_even += temp_sum;
            } else {
                running_sum_even += final_digit_doubled;
            }

        } else {
            // Every digit odd digit
            running_sum_odd += card_final_digit;
        }

        // Increment counter
        counter++;

        // Shorten credit card number
        credit_card /= 10;

    }

    // After adding up all the numbers, checking if modulo 0
    running_sum = running_sum_even + running_sum_odd;

    // Checking if credit card is valid, divisible by 10
    if (running_sum % 10 == 0) {

        // Dividing by 10 until we have just the two first digits left
        while (dupe_credit_card > 99) {
            // Keeping track of the card number length
            card_number_length += 1;
            dupe_credit_card /= 10;
        }

        // Adding 2 to the card number length since we held on to the first two
        card_number_length += 2;

        // Checking American Express, Visa, Mastercard, or Invalid
        if (card_number_length == 15 && (dupe_credit_card == 34 || dupe_credit_card == 37)) {
            printf("AMEX\n");
        } else if (card_number_length == 16 && (dupe_credit_card >= 51 && dupe_credit_card <= 55)) {
            printf("MASTERCARD\n");
        } else if ((card_number_length == 13 || card_number_length == 16) && (dupe_credit_card >= 40 && dupe_credit_card <= 49)) {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }

    } else {
        printf("INVALID\n");
    }

}

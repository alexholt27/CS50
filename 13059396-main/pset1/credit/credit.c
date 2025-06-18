#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_credit_card_number(void);
bool passes_luhn_checksum(long card_number);
int get_length(long number);
int get_starting_digits(long number, int n);
void print_card_type(long number);

int main(void) {
    long card_number = get_credit_card_number();

    if (!passes_luhn_checksum(card_number)) {
        printf("INVALID\n");
        return 0;
    }

    print_card_type(card_number);
}

long get_credit_card_number(void) {
    long x;
    do {
        x = get_long("Number: ");
    }
    while (x <= 0);
    return x;
}

bool passes_luhn_checksum(long number) {
    int total_sum = 0;
    bool should_double = false;

    while (number > 0) {
        int last_digit = number % 10;

        if (should_double) {
            int doubled = last_digit * 2;
            total_sum += (doubled / 10) + (doubled % 10);
        } else {
            total_sum += last_digit;
        }

        should_double = !should_double;
        number /= 10;
    }

    return (total_sum % 10 == 0);
}

int get_length(long number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

int get_starting_digits(long number, int n) {
    while (number >= pow(10, n)) {
        number /= 10;
    }
    return number;
}

void print_card_type(long number) {
    int length = get_length(number);
    int first_two_digits = get_starting_digits(number, 2);
    int first_digit = get_starting_digits(number, 1);

    if ((length == 15) && (first_two_digits == 34 || first_two_digits == 37)) {
        printf("AMEX\n");
    }
    else if ((length == 16) && (first_two_digits >= 51 && first_two_digits <= 55)) {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (first_digit == 4)) {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }
}

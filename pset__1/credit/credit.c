#include <cs50.h>
#include <stdio.h>

int get_card_length(long cardNum) {
    int count = 0;
    while (cardNum != 0) {
        count++;
        cardNum /= 10;
    }
    return count;
}

int get_digit_sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(void) {
    long cardNum = get_long("What is your card number: ");
    int cardLength = get_card_length(cardNum);

    int sumNSub = 0;
    int sumSub = 0;
    int firDigit = 0;
    int stlDigit = 0;

    int count = 0;
    while (cardNum != 0) {
        count++;
        int lastDigit = cardNum % 10;

        if (count % 2 == 0) {
            int prodSub = lastDigit * 2;
            sumSub += get_digit_sum(prodSub);
        } else {
            sumNSub += lastDigit;
        }

        if (count == cardLength - 1) {
            stlDigit = lastDigit;
        }
        if (count == cardLength) {
            firDigit = lastDigit;
        }

        cardNum /= 10;
    }

    int totalSum = sumNSub + sumSub;

    if (cardLength == 15 && firDigit == 3 && (stlDigit == 4 || stlDigit == 7) && totalSum % 10 == 0) {
        printf("AMEX\n");
    } else if (cardLength == 16 && firDigit == 5 && stlDigit >= 1 && stlDigit <= 5 && totalSum % 10 == 0) {
        printf("MASTERCARD\n");
    } else if ((cardLength == 13 || cardLength == 16) && firDigit == 4 && totalSum % 10 == 0) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
}

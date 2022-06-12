#include <stdio.h>

int main() {
    int randNum = 15;

    printf("Guess the number between 0 and 20\n");

    for (int guesses = 5; guesses > 0; guesses--) {
        int guessNum;

        printf("You have %d guesses left\nEnter a guess: ", guesses);
        scanf("%d", &guessNum);

        if (guessNum < randNum) {
            printf("My number is greater than that, please try again\n");
        }
        else if (guessNum == randNum) {
            printf("You guessed it!\n");
            break;
        }
        else if (guessNum > randNum) {
            printf("My number is lesser than that, please try again\n");
        }
    }

    return 0;
}
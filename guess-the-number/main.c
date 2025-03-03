#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int secretNum = rand() % 1000 + 1, win = 0, guess, num_of_guesses;
    int ok;

    // Validate num_of_guesses input
    do {
        printf("Enter the number of guesses: ");
        ok = scanf("%d", &num_of_guesses);

        if (ok != 1 || num_of_guesses <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");

            // Clear input buffer
            while (getchar() != '\n');
        }
    } while (ok != 1 || num_of_guesses <= 0);

    for (int i = 0; i < num_of_guesses; ++i) {
        printf("Number of tries left: %d.\n", num_of_guesses - i);
        printf("Enter a guess (between 1 and 1000): ");

        ok = scanf("%d", &guess);

        if (ok != 1) {
            printf("Invalid input. Please enter an integer.\n");

            // Clear input buffer
            while (getchar() != '\n');
            i--; // Don't count invalid attempts
            continue;
        }

        if (secretNum == guess) {
            printf("Guess correct.\n");
            win = 1;
            break;
        } else {
            printf("Guess failed.\n");
        }
    }

    if (win) {
        printf("Well played game. You're a true guesser.\n");
    } else {
        printf("Too bad you lost, better luck next time.\n");
    }

    return 0;
}

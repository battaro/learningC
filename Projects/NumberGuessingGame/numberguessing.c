#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator
    const int min = 20, max = 100;
    int answer, guess;
    answer = (rand() % max) + min;
    guess = 0;

    int guess_count = 0;
    while (guess != answer)
    {
        printf("\nGuess a number between %d and ", min);
        printf("%d :", max);
        scanf("%d", &guess);

        if (guess == (answer - 1) || guess == (answer + 1))
        {
            printf("So close!");
        }
        else if (guess > answer)
        {
            printf("Too high!");
        }
        else if (guess < answer)
        {
            printf("Too low!");
        }
        guess_count++;
    }

    printf("\nYou found the answer with %d guesses!\n", guess_count);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LEADERBOARD_FILE "guessing_leaderboard.txt"

// Checks cleans input for handling later. optionCount is the size of the array or number of options
bool verifyInput(char* stringItems[], int optionCount, char* input) {
	for (int i = 0; i < optionCount; i++) {
		if (strcmp(stringItems[i], input) == 0) {
			return true;
		}
	}
	return false;
}

// Takes input and action for quit dialogue
bool determineContinue() {
	char inputChar[30];
	printf("Press 'q' to quit, press any key to continue:\n");
	scanf("%s", inputChar);
	while (getchar() != '\n');
	// Returns true for anything that isn't "q"
	return (strcmp(inputChar, "q") != 0);
}

void displayLeaderboard()
{

}


int GetGuess()
{
	int guess;
	printf("Guess a value between 10 and 100: ");
	int num_values = scanf("%d", &guess);
	while (getchar() != '\n'); // clear buffer
	// re-prompt if user enters invalid guess
	while (num_values != 1 || guess < 10 || guess > 100)
	{
		printf("Make sure your guess is between 10 and 100: ");
		num_values = scanf("%d", &guess);
		while (getchar() != '\n'); // clear buffer
	}
	return guess;
}


int PlayGuessingGame()
{
	int guessCt = 0;

	// Generate a random number between 10 and 100 and find its square root
	srand((unsigned int)time(NULL)); // Seed rand with current time
	int numberToGuess = rand() % 91 + 10;
	double squareRoot = sqrt(numberToGuess);
	printf("%.8f is the square root of what number?", squareRoot);
	bool done = false;
	while (!done)
	{
		guessCt++;
		int guess = GetGuess();
		if (guess < numberToGuess)
			printf("Too low, guess again: ");
		else if (guess > numberToGuess)
			printf("Too high, guess again: ");
		else
			done = true;
	}
	printf("You got it, baby!\n");

	return guessCt;
}

int main()
{

	return 0;
}

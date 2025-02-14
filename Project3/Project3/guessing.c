/*
* guessing.c
* 
* Aidan Yung
* 2/14/2025
* 
* Guessing game functionality
* 
* The point of this project is to demonstrate file writing and reading capabilities
* The base game function is minimally modified, if at all
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LEADERBOARD_FILE "guessing_leaderboard.bin"

typedef struct 
{
	char fName[40];
	unsigned int score;
} Person;

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
	char inputChar[40];
	printf("Press 'q' to quit, press any key to continue:\n");
	int charCt = scanf(" %39s", &inputChar);
	inputChar[39] = '\0'; //redundancy
	while (getchar() != '\n'); // clear buffer
	// Returns true for anything that isn't "q"
	return (strcmp(inputChar, "q") != 0);
}


void displayLeaderboard(Person p1)
{
	Person playerList[5];

	FILE* fp = NULL;

	fp = fopen(LEADERBOARD_FILE, "rb+");

	if (fp == NULL)
	{
		// For first time execution
		printf("No leaderboard file found, creating new file.\n");
		fp = fopen(LEADERBOARD_FILE, "wb+");
		if (fp == NULL)
		{
			printf(stderr, "File creation failed.\n");
			exit(1);
		}
	}

	fseek(fp, 0, SEEK_END);

	int fSize = ftell(fp);
	int recordCt = fSize / sizeof(Person);

	Person* recordList[6];

	int recordIndex = 0;
	for (recordIndex; recordIndex < recordCt; recordIndex++)
	{
		recordList[recordIndex] = fread(fp, sizeof(Person), recordCt, fp);
	}

	fclose(fp);
}


void getName(char* name) {
	printf("Enter your name: \n");
	int inputCt = scanf("%s", name);
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


void playRound()
{
	Person p1;
	getName(p1.fName);

	p1.score = PlayGuessingGame();

	displayLeaderboard(p1);
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
	bool continueGame = true;
	printf("Welcome to the Guessing Game!\n");

	// Initial quit question as seen in example before going into the loop
	continueGame = determineContinue();

	while (continueGame) {
		playRound();
		continueGame = determineContinue();
	}

	printf("Goodbye!\n");
	return 0;
}

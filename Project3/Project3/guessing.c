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
#include <math.h>
#include <time.h>

#define LEADERBOARD_FILE "guessing_leaderboard.bin"

typedef struct 
{
	char fName[40];
	int score;
} Person;


// compare function for qsort from stdlib
int compare(const void* a, const void* b)
{
	const Person* p1 = (const Person*)a;
	const Person* p2 = (const Person*)b;

	// Returns 0 if tied/equal, 1 if p1 > p2, and -1 if p2 > p1
	return (p1->score > p2->score) - (p1->score < p2->score);
}


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


// Easier print function to auto format
void printPlayer(Person p1, int place)
{
	printf("%d. %s made %d guesses\n", place + 1, p1.fName, p1.score);
}

FILE* openLeaderboardFile()
{
	FILE* fp = NULL;

	fp = fopen(LEADERBOARD_FILE, "rb+");

	if (fp == NULL)
	{
		// For first time execution
		printf("No leaderboard file found, creating new file.\n");
		fp = fopen(LEADERBOARD_FILE, "wb+");
		if (fp == NULL)
		{
			fprintf(stderr, "File creation failed.\n");
			exit(1);
		}
	}

	return fp;
}

int readLeaderboardRecords(FILE* fp, Person* playerList, int recordCt)
{
	for (int recordIndex = 0; recordIndex < recordCt; recordIndex++)
	{
		fread(&playerList[recordIndex], sizeof(Person), 1, fp);
		printf("Retrieved: [%s]\n", playerList[recordIndex].fName);
	}
}

void writeLeaderboardRecords(FILE* fp, Person* playerList, int recordCt)
{
	fp = fopen(LEADERBOARD_FILE, "wb");

	if (recordCt > 5)
	{
		recordCt = 5;
	}

	if (fp == NULL)
	{
		fprintf(stderr, "Failed to save leaderboard\n");
		free(playerList);
		exit(1);
	}

	for (int i = 0; i < recordCt; i++)
	{
		//printf("Saving [%s]...\n", playerList[i].fName);	// Troubleshooting
		fwrite(&playerList[i], sizeof(Person), 1, fp);
	}
}

void displayLeaderboardResults(Person p1, Person* playerList, int* recordCt)
{
	// Add player to leaderboard
	playerList[*recordCt] = p1;
	(*recordCt)++;

	// Display leaderboard
	printf("----------\nLeaderboard:\n");

	// New leaderboard
	if (*recordCt == 0)
	{
		printPlayer(p1, 1);
	}
	else
	{
		// Existing leaderboard
		qsort(playerList, *recordCt, sizeof(Person), compare);
		for (int i = 0; i < *recordCt; i++)
		{
			printPlayer(playerList[i], i);
		}
	}

	// Ending
	printf("----------\n");
}

void fileIOErrorHandler(const char* message, Person* buffer, FILE* fp)
{
	if (fp)
		fclose(fp);
	if (buffer)
		free(buffer);
	printf("%s",message);
	exit(1);
}

void displayLeaderboard(Person p1)
{
	Person* playerList = malloc(6 * sizeof(Person));

	if (playerList == NULL)
	{
		fprintf(stderr, "Memory allocation failed");
		exit(1);
	}

	FILE* fp = openLeaderboardFile();

	fseek(fp, 0, SEEK_END);

	int fSize = ftell(fp);
	int recordCt = fSize / sizeof(Person);
	rewind(fp);
	readLeaderboardRecords(fp, playerList, recordCt);

	fclose(fp);

	// Safety check to make sure current count is not above 5
	if (recordCt > 6)
	{
		recordCt = 6;
	}

	printf("recordCt: %d\n", recordCt);

	displayLeaderboardResults(p1, playerList, &recordCt);
	writeLeaderboardRecords(fp, playerList, recordCt);

	fclose(fp);
	free(playerList);
}

// Get player username
void getName(char* name) {
	printf("Enter your name: \n");
	int inputCt = scanf("%s", name);
	while (getchar() != '\n'); // clear buffer
}


// Gets guess from player
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


// Guessing game
int PlayGuessingGame()
{
	int guessCt = 0;

	// Generate a random number between 10 and 100 and find its square root
	srand((unsigned int)time(NULL)); // Seed rand with current time
	int numberToGuess = rand() % 91 + 10;
	double squareRoot = sqrt(numberToGuess);
	printf("%.8f is the square root of what number?\n", squareRoot);
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

// Play round function packages everything together
void playRound()
{
	Person p1;
	getName(p1.fName);

	p1.score = PlayGuessingGame();

	displayLeaderboard(p1);
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

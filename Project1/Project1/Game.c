#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Checks cleans input for handling later. optionCount is the size of the array or number of options
bool verifyInput(char *stringItems[], int optionCount, char *input) {
	for (int i = 0; i < optionCount; i++) {
		if (strcmp(stringItems[i], input) == 0) {
			return true;
		}
	}
	return false;
}

// Dialogue for player and returns player move after ensuring a safe input
char getPlayerMove() {
	char playerChoice[30];
	bool validChoice = false;
	char* playerOptions[] = { "r", "p", "s" };

	while (!validChoice) {
		printf("Input your play ('r' for 'rock', 'p' for 'paper', 's' for 'scissors'): \n");
		scanf(" %29s", playerChoice);
		while(getchar() != '\n');
		validChoice = verifyInput(playerOptions, 3, playerChoice);
		if (!validChoice) {
			printf("Invalid choice, please try again!\n");
		}
	}
	return playerChoice[0];
}

// Generates computer move and returns it
char getComputerMove() {
	int cpuVal = rand() % 3 + 1;
	if (cpuVal == 1) {
		return 'r';
	}
	else if (cpuVal == 2) {
		return 'p';
	}
	else {
		return 's';
	}
}

// Compares inputs and returns the winner
void roundWinner(char playerMove, char computerMove) {
	if (playerMove == computerMove) {
		printf("It was a tie!\n");
	}
	else if (
		((playerMove == 'p') && (computerMove == 'r')) ||
		((playerMove == 'r') && (computerMove == 's')) ||
		((playerMove == 's') && (computerMove == 'p'))) {
		printf("You win!\n");
	}
	else {
		printf("Computer wins!\n");
	}
}

// Packages the entire round into one function
void playRound() {
	char computerMove = getComputerMove();
	char playerMove = getPlayerMove();

	printf("You choose: %c\n", playerMove);

	printf("CPU chooses: %c\n", computerMove);

	roundWinner(playerMove, computerMove);
}

// Takes input and action for quit dialogue
bool determineContinue() {
	char inputChar[30];
	printf("Press 'q' to quit, press any key to continue:\n");
	scanf("%s", inputChar);
	while(getchar() != '\n');
	// Returns true for anything that isn't "q"
	return (strcmp(inputChar, "q") != 0);
}


int main() {
	bool continueGame = true;
	printf("Welcome to Rock Paper Scissors!\n");

	// Initial quit question as seen in example before going into the loop
	continueGame = determineContinue();

	while (continueGame) {
		playRound();
		continueGame = determineContinue();
	}

	printf("Goodbye!\n");
	return 0;
}

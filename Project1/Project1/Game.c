#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* game.c
* Rock paper scissors assignment for A3 of CSE 240
* 
* Aidan Yung
* 1/30/2025
*/

bool verifyInput(char *stringItems[], int optionCount, char *input) {
	/*
	* Checks cleans input for handling later. optionCount is the size of the array or number of options
	* @param stringItems[] - Possible valid answers
	* @param optionCount - number of options or the length of stringItems
	* @param input - value of input to clean
	* 
	* @return boolean - whether input is valid or not
	*/
	for (int i = 0; i < optionCount; i++) {
		if (strcmp(stringItems[i], input) == 0) {
			return true;
		}
	}
	return false;
}


char getPlayerMove() {
	/*
	* Dialogue for player and returns player move after ensuring a safe input
	* @return char - player input
	*/
	char playerChoice[30];
	bool validChoice = false;
	char* playerOptions[] = { "r", "p", "s" };

	while (!validChoice) {
		printf("Input your play ('r' for 'rock', 'p' for 'paper', 's' for 'scissors'): \n");
		scanf("%29s", playerChoice);
		validChoice = verifyInput(playerOptions, 3, playerChoice);
		if (!validChoice) {
			printf("Invalid choice, please try again!\n");
		}
	}
	return playerChoice[0];
}


char getComputerMove() {
	/*
	* Generates computer move and returns it
	* @return char - character that the computer generates
	*/
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


void roundWinner(char playerMove, char computerMove) {
	/*
	* Compares inputs and returns the winner'
	* @param playerMove - character that the player inputs
	* @param computerMove - character that the computer inputs
	*/
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


void playRound() {
	/*
	* Packages the entire round into one function
	*/
	char computerMove = getComputerMove();
	char playerMove = getPlayerMove();

	printf("You choose: %c\n", playerMove);

	printf("CPU chooses: %c\n", computerMove);

	roundWinner(playerMove, computerMove);
}


bool determineContinue() {
	/*
	* Takes input and action for quit dialogue
	* @return boolean - whether to continue or not
	*/
	char inputChar[30];
	printf("Press 'q' to quit, press any key to continue:\n");
	scanf("%29s", inputChar);

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
/*
* Aidan Yung
* 2/27/2025
* Twenty Questions Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bst.h"

node* buildTree()
{
	node* root = NULL;

	root = InsertNode(root, 500, "Does it grow underground", "");

	return root;
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

// Dialogue for player and returns player move after ensuring a safe input
char getInput() {
	char choice[30];
	bool validChoice = false;
	char* options[] = { "y", "n"};

	while (!validChoice) {
		int inputCt = scanf(" %29s", choice);
		//clear buffer
		while (getchar() != '\n');
		validChoice = verifyInput(options, 2, choice);
		if (!validChoice) {
			printf("Invalid Option\n");
		}
	}
	return choice[0];
}

int main()
{

	return 0;
}
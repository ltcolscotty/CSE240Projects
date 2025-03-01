/*
* Aidan Yung
* 2/27/2025
* Twenty Questions Project
* 
* Assuming 20 questions means the total number of questions in the tree
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
	
	// Left side (Yes)

	InsertNode(root, 250, "q", "");
	InsertNode(root, 375, "q", "");
	InsertNode(root, 350, "q", "");
	InsertNode(root, 425, "q", "");
	InsertNode(root, 400, "q", "");
	InsertNode(root, 450, "q", "");
	InsertNode(root, 125, "q", "");
	InsertNode(root, 175, "q", "");
	InsertNode(root, 200, "q", "");
	InsertNode(root, 60, "q", "");
	InsertNode(root, 30, "q", "");
	InsertNode(root, 100, "q", "");

	// Left side answers

	InsertNode(root, 30, "", "a");
	InsertNode(root, 100, "", "a");
	InsertNode(root, 150, "", "a");
	InsertNode(root, 180, "", "a");
	InsertNode(root, 225, "", "a");
	InsertNode(root, 325, "", "a");
	InsertNode(root, 360, "", "a");
	InsertNode(root, 390, "", "a");
	InsertNode(root, 415, "", "a");
	InsertNode(root, 435, "", "a");
	InsertNode(root, 475, "", "a");

	// Right side (No)

	InsertNode(root, 750, "q", "");
	InsertNode(root, 675, "q", "");
	InsertNode(root, 600, "q", "");
	InsertNode(root, 550, "q", "");
	InsertNode(root, 640, "q", "");
	InsertNode(root, 725, "q", "");
	InsertNode(root, 875, "q", "");
	InsertNode(root, 825, "q", "");
	InsertNode(root, 800, "q", "");
	InsertNode(root, 925, "q", "");

	// Right side answers
	InsertNode(root, 525, "", "a");
	InsertNode(root, 575, "", "a");
	InsertNode(root, 630, "", "a");
	InsertNode(root, 650, "", "a");
	InsertNode(root, 700, "", "a");
	InsertNode(root, 735, "", "a");
	InsertNode(root, 775, "", "a");
	InsertNode(root, 815, "", "a");
	InsertNode(root, 850, "", "a");
	InsertNode(root, 900, "", "a");
	InsertNode(root, 950, "", "a");


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
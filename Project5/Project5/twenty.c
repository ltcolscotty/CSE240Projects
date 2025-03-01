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

	root = InsertNode(root, 500, "Is it a vegetable?\n", "");
	
	// Left side (Yes)

	InsertNode(root, 250, "Does it grow underground?\n", "");
	InsertNode(root, 375, "Does it look like a tree?\n", "");
	InsertNode(root, 350, "Is it green?\n", "");
	InsertNode(root, 425, "Is it leafy?\n", "");
	InsertNode(root, 400, "Are the leaves big?\n", "");
	InsertNode(root, 450, "Would you eat the pod?\n", "");
	InsertNode(root, 125, "Is it long?\n", "");
	InsertNode(root, 175, "Does it have a 'kick' when eaten?\n", "");
	InsertNode(root, 200, "Does it have an 'earthy' taste?\n", "");
	InsertNode(root, 60, "Is it orange?\n", "");

	// Left side answers

	InsertNode(root, 30, "", "It's a carrot!\n");
	InsertNode(root, 100, "", "It's daikon!\n");
	InsertNode(root, 150, "", "It's horseradish!\n");
	InsertNode(root, 180, "", "It's beets!\n");
	InsertNode(root, 225, "", "Potatoes must be it!\n");
	InsertNode(root, 325, "", "It's broccoli isn't it!\n");
	InsertNode(root, 360, "", "It is cauliflower!\n");
	InsertNode(root, 390, "", "It must be lettuce!\n");
	InsertNode(root, 415, "", "It must be spinach!\n");
	InsertNode(root, 435, "", "It's green beans!\n");
	InsertNode(root, 475, "", "They are peas!\n");

	// Right side (No)

	InsertNode(root, 750, "Does it grow on a tree?\n", "");
	InsertNode(root, 675, "Is it a citrus?\n", "");
	InsertNode(root, 600, "Is it sour?\n", "");
	InsertNode(root, 550, "Is it yellow?\n", "");
	InsertNode(root, 640, "Is it red on the inside?\n", "");
	InsertNode(root, 725, "Is it tropical in origin?\n", "");
	InsertNode(root, 875, "Does it grow in a bush?\n", "");
	InsertNode(root, 825, "Is it sweet?\n", "");
	InsertNode(root, 800, "Is it red?\n", "");
	InsertNode(root, 925, "Can it get very large?\n", "");
	InsertNode(root, 900, "Can it be used in pie?\n", "");

	// Right side answers
	InsertNode(root, 525, "", "It must be a lemon!\n");
	InsertNode(root, 575, "", "It must be a lime!\n");
	InsertNode(root, 630, "", "It's grapefruit!\n");
	InsertNode(root, 650, "", "It's oranges isn't it!\n");
	InsertNode(root, 700, "", "It's a banana!\n");
	InsertNode(root, 735, "", "You must be thinking of apples!\n");
	InsertNode(root, 775, "", "It's raspberries!\n");
	InsertNode(root, 815, "", "It's blackberries!\n");
	InsertNode(root, 850, "", "It must be olives!\n");
	InsertNode(root, 885, "", "It's a pumpkin!\n");
	InsertNode(root, 915, "", "It's a watermelon!\n");
	InsertNode(root, 950, "", "You must be thinking of grapes!\n");

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
char getYN() {
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

void handleQuestion(node* node)
{
	// Check for question
	if (strlen(node->question) > 0)
	{
		printf("%s", node->question);
		printf("y/n:\n");
		char answer = getYN();
		if (answer == "y")
		{
			handleQuestion(node->left);
		}
		else
		{
			handleQuestion(node->right);
		}
	}
	// Answer
	else
	{
		printf("%s",node->guess);
		printf("Did I get it right?\n");
	}
}

int main()
{

	return 0;
}
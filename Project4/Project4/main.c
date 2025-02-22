/*
* Aidan Yung
* 2/21/2025
* Deque Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "slist.h"

#define FILENAME "testFile.txt"
#define MAX_NAME_LEN 50

// ------------ DEQUE WRAPPERS ------------

typedef slist Deque;

void push_back(Deque* q, char* data)
{
	insertTail(q, data);
}

void push_front(Deque* q, char* data)
{
	insertHead(q, data);
}

char* pop_back(Deque* q)
{
	removeTail(q);
}

char* pop_front(Deque* q)
{
	removeHead(q);
}

// ------------ MAIN PROGRAM ------------

void loadDataFromFile(Deque* q)
{
	bool done = false;

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error reading file");
		exit(1);
	}

	while (!done)
	{
		char* name = malloc(MAX_NAME_LEN);
		if (fscanf(fp, "%s", name) == 1)
			push_back(q, name);
		else
			done = true;
	}
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
	char* options[] = { "f", "b", "q" };

	while (!validChoice) {
		int inputCt = scanf(" %29s", choice);
		//clear buffer
		while (getchar() != '\n');
		validChoice = verifyInput(options, 3, choice);
		if (!validChoice) {
			printf("Invalid Option\n");
		}
	}
	return choice[0];
}

void page(Deque* q)
{
	char option = malloc(sizeof(char));


	
	// Initial
	option = getInput();

	while (option != 'q')
	{
		

		if (option == 'f')
		{
			
		}
		else
		{

		}
		
		option = getInput();
	}

	return;

}

int main()
{
	Deque q = { NULL, NULL };

	loadDataFromFile(&q);

	printList(&q);

	return 0;
}
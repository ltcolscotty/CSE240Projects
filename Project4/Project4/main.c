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
	// initial input
	char option = getInput();

	bool first = true;

	while (option != 'q')
	{
		if (first)
		{
			// Prints first element of list regardless of initial input
			printf("%s\n", q->head->data);
		}

		// structuring the code this way lets the change happen immediately
		if (option == 'f' && !first)
		{
			char* data = pop_front(q);
			push_back(q, data);
		}
		else
		{
			if (!first)
			{
				char* data = pop_back(q);
				push_front(q, data);
			}
			
		}

		if (!first)
		{
			printf("%s\n", q->head->data);
		}
		first = false;
		option = getInput();
	}

	printf("Goodbye!");

	return;
}

int main()
{
	Deque q = { NULL, NULL };

	loadDataFromFile(&q);

	printf("To scroll, type\nf: forwards, b: backwards, q: quit\n");

	page(&q);

	return 0;
}
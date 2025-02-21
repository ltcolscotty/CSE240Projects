/*
* Aidan Yung
* 2/21/2025
* Deque Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int main()
{
	Deque q = { NULL, NULL };

	loadDataFromFile(&q);

	printList(&q);

	return 0;
}
/*
* Aidan Yung
* 2/21/2025
* Deque Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "slist.h"

void insertHead(slist* list, char* data)
{
	//---- create new node
	struct node* newnode;
	newnode = malloc(sizeof(struct node));
	if (newnode == NULL)
	{
		fprintf(stderr, "slist: Memory allocation failed");
		exit(1);
	}
	newnode->data = data;
	newnode->next = list->head;

	//---- adjust pointers
	list->head = newnode;

	// Empty list case
	if (list->tail == NULL)
		list->tail = newnode;
}

char* removeHead(slist* list)
{
	// Handle cases of null lists
	if (list == NULL || list->head == NULL)
	{
		return NULL;
	}

	struct node* temp = list->head;
	char* headData = temp->data;
	struct node* newHead = temp->next;

	list->head = newHead;

	// Handle emptied list case
	if (newHead == NULL)
	{
		list->tail = NULL;
	}

	free(temp);
	return headData;
}

void insertTail(slist* list, char* data)
{
	//---- create new node
	struct node* newnode;
	newnode = malloc(sizeof(struct node));
	if (newnode == NULL)
	{
		fprintf(stderr, "slist: Memory allocation failed");
		exit(1);
	}

	newnode->data = data;

	// Empty list case
	if (list->head == NULL)
	{
		list->head = newnode;
		list->tail = newnode;
		return;
	}

	// Add and set tail to list
	struct node* currentTail = list->tail;
	currentTail->next = newnode;
	list->tail = newnode;
}

char* removeTail(slist* list)
{
	// Null list case
	if (list == NULL || list->head == NULL)
	{
		return NULL;
	}

	struct node* trackedTail = list->tail;
	struct node* currentNode = list->head;

	// Handle emptied list case
	if (trackedTail == currentNode)
	{
		list->head = NULL;
		list->tail = NULL;

		char* tailData = trackedTail->data;
		free(trackedTail);
		return tailData;
	}

	// Go to node before tail
	while (currentNode->next != trackedTail)
	{
		currentNode = currentNode->next;
	}

	currentNode->next = NULL;
	list->tail = currentNode;

	char* tailData = trackedTail->data;
	free(trackedTail);
	return tailData;
}

void printList(slist* list)
{
	// empty case
	if (list == NULL)
	{
		return;
	}

	if (list->head == NULL || list->tail == NULL)
	{
		printf("Error: improperly initiated list, skipping print\n");
		return;
	}

	struct node* tmp = list->head;
	bool endOfList = false;

	while (!endOfList)
	{
		if (tmp == list->tail)
			endOfList = true;
		
		if (tmp->data != NULL)
		{
			printf("%s->", tmp->data);
			tmp = tmp->next;
		}
		else
		{
			printf("NULL->");
			tmp = tmp->next;
		}
	}
	printf("NULL\n");
}

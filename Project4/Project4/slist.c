#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

void insertHead(slist* list, int data)
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
	if (list->tail == NULL)
		list->tail = newnode;
}

char* removeHead(slist* list)
{
	if (list == NULL || list->head == NULL)
	{
		return NULL;
	}

	struct node* temp = list->head;
	struct node* newHead = temp->next;
	if (newHead != NULL)
	{
		list->head = newHead;
	}
	free(temp);
}

void insertTail(slist* list, int data)
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
}

char* removeTail(slist* list)
{
	if (list == NULL || list->head == NULL)
	{
		return NULL;
	}

	struct node* trackedTail = list->tail;
	struct node* currentNode = list->head;

	// Go to node before tail
	while (currentNode->next != trackedTail)
	{
		currentNode = currentNode->next;
	}

	currentNode->next = NULL;
	list->tail = currentNode;
}

void printList(slist* list)
{
	struct node* tmp = list->head;
	while (tmp != NULL)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

#ifndef slist_h
#define slist_h
#include <stdio.h>

struct node
{
	char* data;
	struct node* next;
};

struct singlylinkedlist
{
	struct node* head;
	struct node* tail;
};

typedef struct singlylinkedlist slist;

void insertHead(slist* list, char* data);

char* removeHead(slist* list);

void insertTail(slist* list, char* data);

char* removeTail(slist* list);

void printList(slist* list);

#endif
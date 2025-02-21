/*
* Aidan Yung
* 2/21/2025
* Deque Project
*/

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

// ------------ DEQUE WRAPPERS ------------

typedef slist Deque;

void push_back(Deque* q, char* data)
{
	insertTail(&q, &data);
}

void push_front(Deque* q, char* data)
{
	insertHead(&q, &data);
}

char* pop_back(Deque* q)
{
	removeTail(&q);
}

char* pop_front(Deque* q)
{
	removeHead(&q);
}

// ------------ MAIN PROGRAM ------------

int main()
{
	return 0;
}
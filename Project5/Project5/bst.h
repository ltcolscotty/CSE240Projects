/*
* Aidan Yung
* 2/27/2025
* Twenty Questions Project
*/


#ifndef bst_h
#define bst_h
#pragma once

typedef struct node node;

struct node
{
	int data;
	char* question;
	char* guess;
	node* left;
	node* right;
};

#endif
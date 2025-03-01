/*
* Aidan Yung
* 2/27/2025
* Twenty Questions Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

node* InsertNode(node* root, int dataval,char* question, char* item)
{
	node* newNode = malloc(sizeof(node));
	if (newNode == NULL)
	{
		fprintf(stderr, "Memory allocation failed");
		exit(1);
	}

	newNode->left = newNode->right = NULL;
	newNode->data = dataval;
	newNode->question = question;
	newNode->guess = item;

	if (root == NULL)
	{
		root = newNode;
		return root;
	}

	if (dataval < root->data)
	{
		root->left = InsertNode(root->left, dataval, question, item);
	}
	else
	{
		root->right = InsertNode(root->right, dataval, question, item);
	}

	return root;
}

void printInOrder(node* node)
{
	if (node == NULL)
		return;

	printInOrder(node->left);
	printf("%d -> ", node->data);
	printInOrder(node->right);
}
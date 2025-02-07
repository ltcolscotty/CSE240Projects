/*
* Aidan Yung
* 2/6/2025
* 
* 5x5 array
* going R->L, initial starting positions techincally based on memory addresses
* 
* Adjacent cells = 3x3 grid with subject at center
* 
* Rules:
* if more than 3 or less than 2, then cell dies
* if exactly 3 cells are alive around a dead cell, that new cell lives
* always use previous generation to produce new generation, eg. use two arrays, and compute new array based on old array
* 
* Dead cells will be represented with a 'x', and alive characters will be represented with a 'o' when printed out
* The underlying board will be using a 1 and 0 state for alive and dead, respectively
* 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ROWS 5
#define NUM_COLS 5
#define DEAD_CHAR 'x'
#define ALIVE_CHAR 'o'
#define GENERATIONS 7
#define TOKEN_DELIM ","



// use strtok
// Will do its best to translate inputs into valid inputs
// Out of range numbers will be discarded and characters will be casted to ints
int GetInitialState(int init_state[])
{
	int validTokenCount = 0;
	char inputStr[30];
	printf("Input your start configuration: \n");
	scanf(" %29s", &inputStr);

	char* token;

	// First token
	token = strtok(inputStr, TOKEN_DELIM);

	while (token != 0) {
		int pos = atoi(token);
		if ((pos < (NUM_ROWS * NUM_COLS)) && 
			(pos >= 0) && 
			(validTokenCount < (NUM_ROWS * NUM_COLS)))
		{
			init_state[validTokenCount] = pos;
			validTokenCount++;
		}

		token = strtok(0, TOKEN_DELIM);
	}

	//clear buffer
	while (getchar() != '\n');
	return validTokenCount;
}

void SetInitialState(int board[][NUM_COLS], int init_state[], int num_alive)
{

}

void PrintBoard(int board[][NUM_COLS])
{

}

// Produce a second 2d array then replace first array memory with it
void NextGeneration(int board1[][NUM_COLS])
{

}

int CountLiveNeighbors(int board[][NUM_COLS], int r, int c)
{
	int aliveNeighborCt = 0;


	return aliveNeighborCt;
}

void PlayGameOfLife()
{

}

int main()
{
	int board[NUM_ROWS][NUM_COLS];
	int initialState[NUM_ROWS * NUM_COLS];
	int count = GetInitialState(initialState);

	// testing call
	for (int i = 0; i < (count); i++)
	{
		printf("%d\n",initialState[i]);
	}

	return 0;
}
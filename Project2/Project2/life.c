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

bool isValidInteger(char* token)
{
	// Check if the token contains only digits
	for (char* c = token; *c != '\0'; c++) {
		if (*c < '0' || *c > '9') {
			return false;
		}
	}

	return true;
}


// Out of range numbers will be discarded
int GetInitialState(int init_state[])
{
	int validTokenCount = 0;
	char inputStr[30];
	printf("Input your start configuration: \n");
	scanf(" %29s", inputStr);

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

void SetInitialState(char board[][NUM_COLS], int init_state[], int num_alive)
{
	for (int r = 0; r < NUM_ROWS; r++)
	{
		for (int c = 0; c < NUM_COLS; c++)
		{
			board[r][c] = DEAD_CHAR;
		}
	}

	// secondary pass to set alive
	for (int i = 0; i < num_alive; i++)
	{
		board[init_state[i] / NUM_COLS][init_state[i] % NUM_COLS] = ALIVE_CHAR;
	}
}

void PrintBoard(char board[][NUM_COLS])
{
	for (int r = 0; r < NUM_ROWS; r++)
	{
		for (int c = 0; c < NUM_COLS; c++)
		{
			printf("%c", board[r][c]);
		}
		printf("\n");
	}
}

// Produce a second 2d array then replace first array memory with it
void NextGeneration(char board[][NUM_COLS])
{

}

int CountLiveNeighbors(char board[][NUM_COLS], int r, int c)
{
	int aliveNeighborCt = 0;

	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if ((r + dr >= 0) &&
				(r + dr < NUM_ROWS) &&
				(c + dc >= 0) &&
				(c + dc < NUM_COLS))
			{
				if (board[r + dr][c + dc] == 'o')
				{
					aliveNeighborCt++;
				}
			}
		}
	}

	return aliveNeighborCt;
}

void PlayGameOfLife()
{

}

int main()
{
	char board[NUM_ROWS][NUM_COLS];
	int initialState[NUM_ROWS * NUM_COLS];
	int count = GetInitialState(initialState);
	SetInitialState(board, initialState, count);

	PrintBoard(board);

	return 0;
}
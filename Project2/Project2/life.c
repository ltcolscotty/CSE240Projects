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
* if more than 3 or less than 2 neighbors, then cell dies
* if exactly 3 cells are alive around a dead cell, that new cell lives
* always use previous generation to produce new generation, eg. use two arrays, and compute new array based on old array
* 
* Dead cells will be represented with a 'x', and alive characters will be represented with a 'o' when printed out
* 
* 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NUM_ROWS 5
#define NUM_COLS 5
#define DEAD_CHAR '-'
#define ALIVE_CHAR 'O'
#define GENERATIONS 7
#define TOKEN_DELIM ","
#define INPUT_LIMIT 40


void clean_string(char *str)
{
	char copied[INPUT_LIMIT];
	int filteredIndex = 0;
	char *charPointer = str;

	while (1)
	{
		if (*charPointer != '\0')
		{
			if ((*charPointer >= 48 && *charPointer <= 57) || (*charPointer == 44))
			{
				copied[filteredIndex] = *charPointer;
				filteredIndex++;
			}
		}
		else
		{
			// Check for end of line
			if (*(charPointer + 1) == '\0' && *(charPointer + 2) == '\0')
			{
				break;
			}
		}
		charPointer++;
	}


	if (filteredIndex > 0)
	{
		copied[filteredIndex] = '\0';
		strcpy(str, copied);
	}
	else 
	{
		strcpy(str, "");
	}

}


// Out of range numbers will be discarded
int GetInitialState(int init_state[])
{
	int validTokenCount = 0;
	char inputStr[INPUT_LIMIT];
	printf("Input your start configuration: \n");

	// %s terminates at \0, this should take spaced inputs
	// REMEMBER TO SET THIS IF YOU UPDATE INPUT_LIMIT
	int inputCt = scanf(" %39[^\n]", inputStr);

	clean_string(inputStr);

	char *token;

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
				(c + dc < NUM_COLS) &&
				!((dr == 0) && (dc == 0)))
			{
				if (board[r + dr][c + dc] == ALIVE_CHAR)
				{
					aliveNeighborCt++;
				}
			}
		}
	}

	return aliveNeighborCt;
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


// Produce an initialList type array and produce a new array with it after gathering what should be alive
void NextGeneration(char board[][NUM_COLS])
{
	int pos = 0;

	int aliveTiles[NUM_ROWS * NUM_COLS];

	for (int r = 0; r < NUM_ROWS; r++)
	{
		for (int c = 0; c < NUM_COLS; c++)
		{
			int count = CountLiveNeighbors(board, r, c);
			if (((board[r][c] == DEAD_CHAR) && (count == 3)) ||
				((board[r][c] == ALIVE_CHAR) && ((count == 3) || (count == 2))))
			{
				aliveTiles[pos] = (r*NUM_COLS) + c;
				pos++;
			}
		}
	}

	SetInitialState(board, aliveTiles, pos);
}


void PlayGameOfLife(char board[][NUM_COLS])
{
	for (int i = 0; i < GENERATIONS; i++)
	{
		printf("Generation: %d\n", i);
		PrintBoard(board);
		NextGeneration(board);
	}
}


int main()
{
	char board[NUM_ROWS][NUM_COLS];
	int initialState[NUM_ROWS * NUM_COLS];
	int count = GetInitialState(initialState);
	SetInitialState(board, initialState, count);
	
	PlayGameOfLife(board);

	return 0;
}
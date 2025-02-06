/*
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
*/

#include <stdio.h>

#define NUM_ROWS = 5
#define NUM_COLS = 5

//use strtok
int GetInitialState(int init_state[])
{

}

void SetInitialState(char board[][NUM_COLS], int init_state[], int num_alive)
{

}

void PrintBoard(char board[][NUM_COLS])
{

}

int CountLiveNeighbors(char board[][NUM_COLS], int r, int c)
{

}

void PlayGameOfLife()
{

}

int main()
{
	printf("hi");
	return 0;
}
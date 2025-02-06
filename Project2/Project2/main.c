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

int main()
{
	printf("hi");
	return 0;
}
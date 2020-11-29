#ifndef __ARRAYS__
#define __ARRAYS__

#include "functions.h"

void	PrintArray(const int arr[], int size);
void	InitArray(int arr[], int size);
void	printMat(int** mat, int rows, int cols);
void	PrintNumGameMat(int** mat, int rows, int cols);
void	InitMat(int mat[][R], int rows, int cols);
void	InitNumGameMat(int** mat, int rows, int cols);
int	swap(int* a, int* b);
void	flipRow(int* row, int columns);
void	flipColumns(int* row, int columns);

#endif

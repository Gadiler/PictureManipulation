#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h> 
#include "arrays.h" 
#include "functions.h" 

void PrintArray(const int arr[], int size)
{
	int i;
	printf("\nPrintArray; print array: ");
	for (i = 0; i < size; i++)
		printf("%4d", arr[i]);

	printf("\nInitArray; Done to initialize\n");
}

void InitArray(int arr[], int size)
{
	srand(time(NULL));
	int i;
	for (i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

void printMat(int** mat, int rows, int cols)
{
	int i, j, t1 = 0;
	int* pMat = (int*)mat;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			t1 = i * R + j;
			printf("%5d", *(pMat+t1));
		}
		printf("\n");
	}

}

void	InitMat(int mat[][R], int rows, int cols)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mat[i][j] = rand() % 100;
		}
	}
}

void	InitNumGameMat(int** mat, int rows, int cols)
{
	int i, j, t1, n = 0;
	int* pMat = (int*)mat;
	for (i = 0; i < rows && n < (N * N) - 1; i++)
	{
		
		for (j = 0; j < cols; j++)
		{
			t1 = i * N + j;
			*(pMat + t1) = n++;
		}
	}
	shuffle(mat);
}

void	PrintNumGameMat(int** mat, int rows, int cols)
{
	int i, j, t1 = 0;
	int* pMat = (int*)mat;
	for (i = N-1; i >= 0; i--)
	{
		for (j = N-1; j >= 0; j--)
		{
			t1 = i * N + j;
			if (*(pMat + t1) == 0)
				printf("    X");
			else
				printf("%5d", *(pMat + t1));
		}
		printf("\n");
	}
}

int swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void flipRow(int* row, int columns)
{
	for (int i = 0; i < columns / 2; i++)
	{
		swap(row + i, row + columns - 1 - i);
	}
}

void flipColumns(int* row, int columns)
{
	int t1, t2;
	for (int i = 0; i < R / 2; i++)
	{
		t1 = (R - 1 - i) * R;
		t2 = i * R;
		swap(row + t2 + columns, row + columns + t1);
	}
}

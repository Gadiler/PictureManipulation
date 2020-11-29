#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "functions.h"
#include "arrays.h"


void rotateMatrixOffSet(int mat[][C])
{
	/*

	1 2 3       4 1 2   |
	4 5 6  ->   7 5 3   | 1 2 3 4 5 6 7 8 9 -> 4 1 2 7 5 3 8 9 6
	7 8 9       8 9 6   |

	*/
	int temp;
	for (int i = 0; i < R / 2; i++)
	{
		for (int j = i; j < R - i - 1; j++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[R - 1 - j][i];
			mat[R - 1 - j][i] = mat[R - 1 - i][R - 1 - j];
			mat[R - 1 - i][R - 1 - j] = mat[j][R - 1 - i];
			mat[j][R - 1 - i] = temp;
		}
	}
}

// Rotate the matrix clock-wise.
void rotateClockwise(int** mat)
{
	int* pMat = (int*)mat;
	int t1, t2, t3, t4, temp;
	for (int i = 0; i < R/2; i++)
	{
		for (int j = i; j < R - i - 1; j++)
		{
			t1 = i * R + j;
			t2 = (R - 1 - j) * R + i;
			t3 = (R - 1 - i) * R + R - 1 - j;
			t4 = j * R + R - 1 - i;

			temp = *(pMat + t1);
			*(pMat + t1) = *(pMat + t2);
			*(pMat + t2) = *(pMat + t3);
			*(pMat + t3) = *(pMat + t4);
			*(pMat + t4) = temp;
        	}
	}
}

// Rotate the matrix anti-clock-wise.
void rotateAntiClockwise(int** mat)
{	
	int* pMat = (int*)mat;
	int t1, t2, t3, t4, temp;

	for (int i = 0; i < R / 2; i++)
	{
		for (int j = i; j < R - i - 1; j++)
		{
			t1 = i * R + j;
			t2 = j * R + (R - 1 - i);
			t3 = (R - 1 - i) * R + (R - j - 1);
			t4 = (R - 1 - j) * R + i;

			temp = *(pMat + t1);
			*(pMat + t1) = *(pMat + t2);
			*(pMat + t2) = *(pMat + t3);
			*(pMat + t3) = *(pMat + t4);
			*(pMat + t4) = temp;
		}
	}
}

// Rotate the matrix vertically.
void verticalFlip(int** mat)
{
	int t1;
	int* pMat = (int*)mat;

	for (int row = 0; row < R; row++)
	{
		t1 = (row * R);
		flipRow(pMat + t1, R);
	}
}

// Rotate the matrix horizontally.
void horizontalFlip(int** mat)
{
	int t1;
	int* pMat = (int*)mat;

	for (int column = 0; column < R; column++)
		flipColumns(pMat, column);
}

// Checking if the game is OVER.
int ascendingOrder(int** mat)
{
	int* pMat = (int*)mat;
	int t1, t2, ans = 0;
	for (int i = 0; i < R-1; i++)
	{
		for (int j = 0; j < R-1; j++)
		{
			t1 = (i * R + j);
			t2 = (i * R + j + 1);
			if (*(pMat + t1) > *(pMat + t2))
				return 0;
		}
	}
	printf("\nYou win! The game is over!\n");
	return 1;
}

// Moves the number to the right.
void moveRight(int** mat) 
{
	int temp, i, j, t1 = 0, t2 = 0;
	int* pMat = (int*)mat;
	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < N; j++) 
		{
			t1 = i * N + j;
			t2 = i * N + (j - 1);
			if (*(pMat+t1) == 0 && j != 0)
				swap((pMat + t2), (pMat + t1));
		}
	}
}

// Moves the number to the left.
void moveLeft(int** mat) 
{
	int temp, i, j, t1 = 0, t2 = 0;
	int* pMat = (int*)mat;
	for (i = N-1; i >= 0; i--) 
	{
		for (j = N-1; j >= 0; j--) 
		{
			t1 = i * N + j;
			t2 = i * N + j + 1;
			if (*(pMat + t1) == 0 && j != N - 1)
				swap((pMat + t2), (pMat + t1));
		}
	}
}

// Moves the number up.
void moveUp(int** mat) 
{
	int temp, i, j, t1 = 0, t2 = 0;
	int* pMat = (int*)mat;
	for (i = N-1; i >= 0; i--) 
	{
		for (j = N-1; j >= 0; j--) 
		{
			t1 = i * N + j;
			t2 = (i + 1) * N + j;
			if (*(pMat + t1) == 0 && i != N - 1)
				swap((pMat + t2), (pMat + t1));
		}
	}
}

// Moves the number down.
void moveDown(int** mat) 
{
	int temp, i, j, t1 = 0, t2 = 0;
	int* pMat = (int*)mat;
	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < N; j++) 
		{
			t1 = i * N + j;
			t2 = (i - 1) * N + j;
			if (*(pMat + t1) == 0 && i != 0)
				swap((pMat + t2), (pMat + t1));
		}
	}
}

int getInvCount(int* arr)
{
	int inv_count = 0, t1 = 0, t2 = 0;
	for (int i = 0; i < N * N - 1; i++)
	{
		for (int j = i + 1; j < N * N; j++)
		{
			// count pairs(i, j) such that i appears
			// before j, but i > j.
			t1 = i * N;
			t2 = j * N;
			if ((arr + t2) && (arr + t1) && (arr + t1) > (arr + t2))
				inv_count++;
		}
	}
	return inv_count;
}

// find Position of blank from bottom
int findXPosition(int** numMat)
{
	// start from bottom-right corner of matrix
	for (int i = N - 1; i >= 0; i--)
		for (int j = N - 1; j >= 0; j--)
		{
			int t1 = i * N + j;
			if (numMat + t1 == 0)
			{
				return N - i;
			}
		}
			
}

// This function returns true if given
// instance of N*N - 1 puzzle is solvable
int isSolvable(int** numMat)
{
	// Count inversions in given puzzle
	int invCount = getInvCount((int*)numMat);

	// If grid is odd, return true if inversion
	// count is even.
	if (N & 1)
	{
		return !(invCount & 1);
	}
	else     // grid is even
	{
		int pos = findXPosition(numMat);
		if (pos && 1)
		{
			return !(invCount && 1);
		}
		else
		{
			return (invCount && 1);
		}
	}
}

void shuffle(int** numMat)
{
	srand(time(NULL));
	int n = N;
	int* pMat = (int*)numMat;

	while (n > 1)
	{
		int r = rand() % n--;
		int t1 = N * r;
		int t2 = N * n;
		swap((pMat + t1), (pMat + t2));
	}
}

void newGame(int** numMat)
{
	do
	{
		InitNumGameMat(numMat, N, N); 
	} while (!isSolvable(numMat));
}

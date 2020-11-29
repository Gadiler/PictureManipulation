#ifndef __FUNC__
#define __FUNC__
#define R 5 
#define C 5 
#define N 4

void rotateMatrixOffSet(int mat[][C]);
void rotateClockwise(int** mat);
void rotateAntiClockwise(int** mat);
void verticalFlip(int** mat);
void horizontalFlip(int** mat);
int  ascendingOrder(int** mat);
void moveRight(int** mat);
void moveLeft(int** mat);
void moveUp(int** mat);
void moveDown(int** mat);
int  isSolvable(int** numMat);
void shuffle(int** numMat);
void newGame(int** numMat);
int  getInvCount(int* arr);
int  findXPosition(int** numMat);

#endif 

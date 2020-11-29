#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <ctype.h>
#include "PictureManipulation.h"
#include "NumberGame.h"
#include "functions.h"
#include "arrays.h"

#define N 4

int  main()
{
    char ch = 0;
    int picMat[R][C] = { 0 }, numMat[R][C] = { 0 }, c = 0;

    srand(time(NULL));
    InitMat(picMat, R, C);
    InitMat(numMat, N, N);
	
    while (ch != 'e')
    {
        printf( "\nPlease choose one of the following options\n"
                "P / p - Picture Manipulation\n"
                "N / n - Number Game\n"
                "E / e - Quit\n");
        ch = tolower(getchar());

        switch (ch)
        {
        case 'p':   // 90 degree clockwise
            picManipulat((int**)picMat);
            break;

        case 'n':   // 90 degree counter clockwise
			numGame((int**)numMat);
            break;

        case 'e':  // Quit
            printf("\nBay-Bay!\n");
            break;

         // operator doesn't match any case constant p, n, e.
        default:
			while ((c = getchar()) != '\n' && c != EOF) {}
            printf("\nError! operator is not correct\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include "NumberGame.h"
#include "functions.h"
#include "arrays.h"

void numGame(int** numMat)
{
    int ans = 0, c = 0;
    newGame(numMat);

    while (ans != -1)
    {
        PrintNumGameMat(numMat, N, N);
        printf("\n1 - Up   \n"
                 "2 - Down \n"
                 "3 - Left \n"
                 "4 - Right\n"
                "-1 - Quit \n"
                "Your step: ");
        scanf("%d", &ans);

        if (ascendingOrder(numMat) == 1)
            ans = -1;

        switch (ans)
        {
        case 1:   // Up
            moveUp(numMat);
        break;

        case 2:   // Down
            moveDown(numMat);
        break;

        case 3:   // Left
            moveLeft(numMat);
        break;

        case 4:   // Right
            moveRight(numMat);
        break;

        case -1:  // Quit
            while ((c = getchar()) != '\n' && c != EOF) {}
        break;

        // operator doesn't match any case constant 1, 2, 3, 4, -1.
        default:
            printf("\nError! operator is not correct.\n");
        }
    }
}

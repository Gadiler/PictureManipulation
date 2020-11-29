#include <stdio.h>
#include <ctype.h>
#include "PictureManipulation.h"
#include "arrays.h"

void picManipulat(int** mat)
{   
    int rows = sizeof(**mat) / sizeof(mat[0]);
    int cols = sizeof(**mat) / sizeof(mat[0][0]);
    int ans = 0, c = 0;
    
    printMat(mat, R, R);
    while (ans != -1)
    {

        printf( "\n1 - 90 degree clockwise\n"
                  "2 - 90 degree counter clockwise \n"
                  "3 - Flip Horizontal \n"
                  "4 - Flip Vertical \n"
                 "-1 - Quit\n");
        scanf("%d", &ans);

        printMat(mat, rows, cols);
        switch (ans)
        {
        case 1:   // 90 degree clockwise
            printf("\nBefore Rotate:\n");
            printMat(mat, R, C);
            rotateClockwise(mat);
            printf("\nAfter Rotate:\n");
            printMat(mat, R, C);
            printf("\n-------------------------------------\n\n");
            break;

        case 2:   // 90 degree counter clockwise
            printf("\nBefore Anti-Rotate:\n");
            printMat(mat, R, C);
            rotateAntiClockwise(mat);
            printf("\nAfter Anti-Rotate:\n");
            printMat(mat, R, C);
            printf("\n-------------------------------------\n\n");
            break;

        case 3:   // Flip Horizontal
            printf("\nBefore Horizontal-Flip:\n");
            printMat(mat, R, C);
            horizontalFlip(mat);
            printf("\nAfter Horizontal-Flip:\n");
            printMat(mat, R, C);
            printf("\n-------------------------------------\n\n");
            break;

        case 4:   // Flip Vertical
            printf("\nBefore Vertical-Flip:\n");
            printMat(mat, R, C);
            verticalFlip(mat);
            printf("\nAfter Vertical-Flip:\n");
            printMat(mat, R, C);
            printf("\n-------------------------------------\n\n");
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

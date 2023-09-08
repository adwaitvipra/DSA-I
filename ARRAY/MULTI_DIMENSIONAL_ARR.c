#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
    // 1. Array inside stack.

    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}}; // declare and init A

    for (int i = 0; i < 3; i++) // printing array in 2D
    {
        for (int j = 0; j < 4; j++)
            printf ("%d ", A[i][j]);

        printf("\n");
    }
    printf("\n\n");

    // 2. Array of pointers in stack and actual integer array in heap

    int *B[3], x = 1; // inside stack
		      //
    for (int i = 0; i < 3; i++)
        B[i] = (int *) malloc (4 * sizeof(int)); // inside heap

    for (int i = 0; i < 3; i++)                    // init B
        for (int j = 0; j < 4; j++)
            B[i][j] = x++;

    for (int i = 0; i < 3; i++) // printing arr in 2D
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", B[i][j]);

        printf("\n");
    }
    printf("\n\n");

    for (int k = 0; k < 3; k++)
	    free (B[k]);
    // 3. Double pointer in stack and other arrays in heap

    int **C = NULL, y = 101;

    C = (int **) malloc (3 * sizeof(int *)); // arr of int ptr in heap

    for (int i = 0; i < 3; i++)
        C[i] = (int *) malloc(4 * sizeof(int)); // arr of int in heap

    for (int i = 0; i < 3; i++) // init C
        for (int j = 0; j < 4; j++)
            C[i][j] = y++;

    for (int i = 0; i < 3; i++) // printing arr in 2D
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }
    printf("\n\n");

    for (int k = 0; k < 3; k++)
	    free (C[k]);

    free (C);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // 1. Array inside stack.
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}}; // declrn and init A
    int i, j;

    for (i = 0; i < 3; i++) // printing arr in 2D
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // 2. arr of pointers in stack and actual int arr in heap
    int *B[3], x = 1; // inside stack
    for (i = 0; i < 3; i++)
        B[i] = (int *)malloc(4 * sizeof(int)); // inside heap
    for (i = 0; i < 3; i++)                    // init B
    {
        for (j = 0; j < 4; j++)
            B[i][j] = x++;
    }
    for (i = 0; i < 3; i++) // printing arr in 2D
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // 3. a double pointer in stack and other arrs in heap
    int **C, y = 101;
    C = (int **)malloc(3 * sizeof(int *)); // arr of int ptr in heap
    for (i = 0; i < 3; i++)
        C[i] = (int *)malloc(4 * sizeof(int)); // arr of int in heap

    for (i = 0; i < 3; i++) // init C
    {
        for (j = 0; j < 4; j++)
            C[i][j] = y++;
    }
    for (i = 0; i < 3; i++) // printing arr in 2D
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 128 

struct Matrix
{
	int diag[SIZE];
	int size;
};

void Display (struct Matrix mat)
{
	int row, col;

	for (row = 0; row < mat.size; row++)
	{
		for (col = 0; col < mat.size; col++)
		{
			if (row == col)
				printf ("%d ", mat.diag[row]);
			else
			{
				printf ("0 ");
			}
		}
		printf ("\n");
	}

	return ;
}

void Set (struct Matrix *mat, int row, int col, int val)
{
	if (mat)
	{
		if (row == col)
			mat->diag[row - 1] = val;
	}

	return ;
}

int Get (struct Matrix mat, int row, int col)
{
	int ret = INT_MIN;

	if ((row <= mat.size) && (col <= mat.size))
	{
		if (row != col)
			ret = 0;
		else
		{
			ret = mat.diag[row - 1];
		}
	}

	return ret;
}

int main (const int argc, const char *argv[])
{
	struct Matrix m = {{0}, 3};

	Set (&m, 1, 1, 9);
	Set (&m, 2, 2, 1);
	Set (&m, 3, 3, 2);

	printf ("%d \n", Get (m, 1, 1));
	printf ("%d \n", Get (m, 1, 2));

	Display (m);

	return 0;
}

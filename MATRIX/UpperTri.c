#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW_MAJ(N, I, J) (((N) * ((I) - 1)) - ((((I) - 1) * ((I) - 2)) / 2) + ((J) - (I)))
#define COL_MAJ(I, J) ((((J) * ((J) - 1)) / 2) + ((I) - 1))

struct Matrix
{
	int *arr;
	int n;
};

void Display (struct Matrix mat)
{
	if (mat.arr && (mat.n > 0))
	{
		for (int i = 1; i <= mat.n; i++)
		{
			for (int j = 1; j <= mat.n; j++)
			{
				if (i > j)
					printf ("0 ");
				else
				{
					/*
					   printf ("%d ", mat.arr[COL_MAJ (i, j)]);
					   */

					printf ("%d ", mat.arr[ROW_MAJ (mat.n, i, j)]);
				}
			}
			printf ("\n");
		}
	}

	return ;
}

void Set (struct Matrix *mat, int i, int j, int val)
{
	if (mat && mat->arr && (i <= mat->n) && (j <= mat->n))
	{
		/*
		   mat->arr[COL_MAJ (i, j)] = val;
		   */

		mat->arr[ROW_MAJ (mat->n, i, j)] = val;
	}

	return ;
}

int Get (struct Matrix mat, int i, int j)
{
	int ret = INT_MIN;

	if (mat.arr && (mat.n > 0) && (i <= mat.n) && (j <= mat.n))
	{
		if (i > j)
			ret = 0;
		else
		{
			/*
			   ret = mat.arr[COL_MAJ (i, j)];
			   */

			ret = mat.arr[ROW_MAJ (mat.n, i, j)];
		}
	}

	return ret;
}

int main (const int argc, const char *argv[])
{
	int i, j, x;
	struct Matrix m;

	printf ("Enter Dimension: ");
	scanf ("%d", &m.n);

	m.arr = (int *) malloc (sizeof (int) * m.n * (m.n + 1) / 2);

	printf ("Enter all Elements:\n");
	for (i = 1; i <= m.n; i++)
	{
		for (j = 1; j <= m.n; j++)
		{
			scanf (" %d", &x);
			Set (&m, i, j, x);
		}
	}

	printf ("%d \n", Get (m, 1, 1));
	printf ("%d \n", Get (m, 2, 2));

	Display (m);

	free (m.arr);

	return 0;
}

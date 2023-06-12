#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Matrix
{
	int diag [SIZE];
	int size;
};

void Display (struct Matrix mat)
{
	int row, col;
	for (row = 0; row < mat.size; row++)
	{
		for (col= 0; col < mat.size; col++)
		{
			if (row == col)
				printf("%d ", mat.diag [row]);
			else
				printf("0 ");
		}
		printf("\n");
	}
	return ;
}

void Set (struct Matrix *mat, int row, int col, int val)
{
	if (row == col)
		mat->diag [row - 1] = val;
	return ;
}

int Get (struct Matrix mat, int row, int col)
{
	if (row == col)
		return mat.diag [row - 1];
	return 0;
}
int main(int argc, char const *argv[])
{
	struct Matrix m={{0},3};
	Set(&m,1,1,9);
	Set(&m,2,2,1);
	Set(&m,3,3,2);
	printf("%d \n",Get(m,1,1));
	printf("%d \n",Get(m,1,2));
	Display(m);
	return 0;
}

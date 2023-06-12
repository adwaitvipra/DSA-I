#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff, exp;
    struct Node *next;
} *polynomial = NULL;

void Display (struct Node *poly)
{
	struct Node *itr = NULL;

	if (poly)
	{
		printf ("\n\nP (X) = ");
		for (itr = poly; itr->next; itr = itr->next)
			printf("%dX^(%d) + ", itr->coeff, itr->exp);
		printf("%dX^(%d)\n\n", itr->coeff, itr->exp);
	}

	return ;
}

long Evaluate (struct Node *poly, int val)
{
	long ans = 0;
	struct Node *itr = NULL;

	if (poly)
		for (itr = poly; itr; itr = itr->next)
			ans += (itr->coeff) * pow (val, itr->exp);
	return ans;
}

void Create (struct Node *poly)
{
	int num, i;
	struct Node *new = NULL, *last = NULL;
	printf("Enter total number of terms in polynomial :\n");
	scanf("%d", &num);
	printf("Enter coefficients and exponents of all the terms :\n");

	for (i = 0; i < num; i++)
	{
		new = (struct Node *)malloc(sizeof(struct Node));
		scanf("%d %d", &new->coeff, &new->exp);
		new->next = NULL;

		if (!polynomial)
			polynomial = last = new;
		else
		{
			last->next = new;
			last = new;
		}
	}
}

int main (int argc, char const *argv[])
{
	long val;
	Create (polynomial);
	Display (polynomial);
	printf ("X?\n");
	scanf ("%ld", &val);
	printf ("\nP (%ld) = %ld\n", val, Evaluate (polynomial, val));
	return 0;
}

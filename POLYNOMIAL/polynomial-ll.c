#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct Node
{
    int coeff, exp;
    struct Node *next;
} *polynomial = NULL;

void display (struct Node *poly)
{
	struct Node *itr = NULL;

	if (poly)
	{
		printf ("\n\nP (X) = ");

		for (itr = poly; itr->next; itr = itr->next)
			printf ("%dX^(%d) + ", itr->coeff, itr->exp);

		printf ("%dX^(%d)\n\n", itr->coeff, itr->exp);
	}

	return ;
}

long evaluate (struct Node *poly, int val)
{
	long ans = LONG_MIN;
	struct Node *itr = NULL;

	if (poly)
	{
		ans = 0;

		for (itr = poly; itr; itr = itr->next)
			ans += (itr->coeff) * pow (val, itr->exp);
	}

	return ans;
}

struct Node *create (struct Node **poly)
{
	int num;
	struct Node *head = NULL, *tail = NULL, *new = NULL;

	printf("enter total number of terms in polynomial: ");
	scanf("%d", &num);
	printf("enter coefficients and exponents of all the terms:\n");

	for (int i = 0; i < num; i++)
	{
		if ((new = (struct Node *) malloc (sizeof (struct Node))))
		{
			scanf ("%d %d", &new->coeff, &new->exp);
			new->next = NULL;

			if (!head)
			{
				head = new;

				if (poly)
					*poly = head;

				tail = new;
			}
			else
			{
				tail->next = new;
				tail = new;
			}
		}
		else
			printf ("dynamic allocation failed!\n");
	}

	return head;
}

void delete (struct Node **poly)
{
	struct Node *tmp = NULL, *ptr = NULL;

	if (poly)
	{
		ptr = *poly;

		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			free (tmp);
		}

		*poly = NULL;
	}

	return ;
}

int main (int argc, char const *argv[])
{
	long val;

	create (&polynomial);

	display (polynomial);

	printf ("X?\n");
	scanf ("%ld", &val);
	printf ("\nP (%ld) = %ld\n", val, evaluate (polynomial, val));

	delete (&polynomial);

	return 0;
}

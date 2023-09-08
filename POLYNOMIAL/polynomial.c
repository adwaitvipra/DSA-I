#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

// Need to improve this for unsorted exponents and their addition
struct term
{
    int coeff;
    int exp;
};

struct polynomial
{
	int count;
	struct term *terms;
};

void create (struct polynomial *poly)
{
	if (poly)
	{
		printf ("enter total number of terms in polynomial: ");
		scanf ("%d", &poly->count);

		if ((poly->count > 0)
				&& (poly->terms = (struct term *)
					malloc (poly->count * sizeof (struct term))))
			for (int i = 0; i < poly->count; i++)
				scanf ("%d %d", &poly->terms[i].coeff, &poly->terms[i].exp);
	}

	return ;
}

void display (struct polynomial poly)
{
	if (poly.count > 0)
	{
		printf ("\n\nP (X) = ");

		for (int i = 0; i < poly.count; i++)
		{
			if (i == (poly.count - 1))
				printf ("%dX^(%d)", poly.terms[i].coeff, poly.terms[i].exp);
			else
				printf ("%dX^(%d) + ", poly.terms[i].coeff, poly.terms[i].exp);
		}
		printf("\n");
	}

	return ;
}

float evaluate (struct polynomial poly, float x)
{
	float sum = FLT_MIN;

	if (poly.count > 0)
	{
		sum = 0;

		for (int i = 0; i < poly.count; i++)
			sum += (poly.terms[i].coeff) * pow (x, poly.terms[i].exp);

	}

	return sum;
}

struct polynomial *add (struct polynomial *px, struct polynomial *py)
{
	int i, j, k;
	struct polynomial *sum = NULL;

	if (px && py && (sum = (struct polynomial *) malloc (sizeof (struct polynomial))))
	{
		i = j = k = 0;

		// maximum px's n plus py's n terms can be present in sum poly
		if ((sum->terms = (struct term *)
					malloc ((px->count + py->count) * sizeof (struct term))))
		{
			while (i < px->count && j < py->count)
			{
				if (px->terms[i].exp > py->terms[j].exp)
					sum->terms[k++] = px->terms[i++];
				else if (px->terms[i].exp < py->terms[j].exp)
					sum->terms[k++] = py->terms[j++];
				else
				{
					sum->terms[k].exp = px->terms[i].exp;
					sum->terms[k++].coeff = px->terms[i++].coeff + py->terms[j++].coeff;
				}
			}

			// there may be some remaining elements in either of polys
			while (i < px->count)
				sum->terms[k++] = px->terms[i++];
			while (j < py->count)
				sum->terms[k++] = py->terms[j++];

			sum->count = k;
		}
		else
		{
			free (sum);
			sum = NULL;
		}
	}

	return sum;
}

int main (int argc, char const *argv[])
{
	float val;
	struct polynomial px;

	create (&px);
	display (px);

	printf ("\nX ? ");
	scanf ("%f", &val);
	printf ("\nP (%f) = %f\n", val, evaluate (px, val));

	if (px.terms)
		free (px.terms);

	return 0;
}

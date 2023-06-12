#include <stdio.h>
#include <stdlib.h>
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
    int i;
    printf("Enter total number of terms in polynomial :\n");
    scanf("%d", &poly->count);

    if ((poly->terms = (struct term *) malloc (sizeof(struct term) * poly->count)))
    {
	    printf("Enter terms of polynomial in the pair of coeff and exponent:\n");
	    for (i = 0; i < poly->count; i++)
		    scanf("%d %d", &poly->terms[i].coeff, &poly->terms[i].exp);
    };
    return ;
}

void display (struct polynomial poly)
{
	printf ("\n\nP (X) = ");
	for (int i = 0; i < poly.count; i++)
	{
		if (i == poly.count - 1)
			printf("%dX^(%d)", poly.terms[i].coeff, poly.terms[i].exp);
		else
			printf("%dX^(%d) + ", poly.terms[i].coeff, poly.terms[i].exp);
	}
	printf("\n");

	return ;
}

float evaluate (struct polynomial poly, float x)
{
	int i;
	float sum = 0;

	for(i = 0; i < poly.count; i++)
		sum += (poly.terms[i].coeff) * pow (x, poly.terms[i].exp);

	return sum;
}

struct polynomial *add (struct polynomial *p1, struct polynomial *p2)
{
	int i, j, k;
	struct polynomial *sum;
	i = j = k = 0;

	if ((sum = (struct polynomial *)malloc(sizeof(struct polynomial))))
	{
	       	// maximum p1's n plus p2's n terms can be present in sum poly
		sum->terms = (struct term *) malloc ((p1->count + p2->count) * sizeof(struct term));
		while (i < p1->count && j < p2->count)
		{
			if (p1->terms[i].exp > p2->terms[j].exp)
				sum->terms[k++] = p1->terms[i++];
			else if (p1->terms[i].exp < p2->terms[j].exp)
				sum->terms[k++] = p2->terms[j++];
			else
			{
				sum->terms[k].exp = p1->terms[i].exp;
				sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
			}
		}
		// There may be some remaining elements in either of polys
		for (; i < p1->count; i++)
			sum->terms[k++] = p1->terms[i];
		for (; j < p2->count; j++)
			sum->terms[k++] = p2->terms[j];

		sum->count = k;
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	float val;
	struct polynomial p1;

	create (&p1);
	display (p1);

	printf ("X?\n");
	scanf ("%f", &val);
	printf ("\nP (%f) = %f\n", val, evaluate (p1,val));

	return 0;
}

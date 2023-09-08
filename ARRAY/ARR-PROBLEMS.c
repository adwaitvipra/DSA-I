#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// natural numbers array must start form 1
void SingleMissingNatural (int A[], int n)
{
	int s, sum;

	if (A && (n > 0))
	{
		sum = 0;
		s = A[n - 1] * (A[n - 1] + 1) / 2;

		for (int i = 0; i < n; i++)
			sum += A[i];

		printf("missing element = %d \n", s - sum);
	}

	return ;
}

// increasing sequence of natural no.s
void SingleMissingSorted (int A[], int n)
{
	int diff;

	if (A && (n > 0))
	{
		diff = A[0] - 0;

		for (int i = 0; i < n; i++)
		{
			if ((A[i] - i) != diff)
			{
				printf ("missing element = %d \n", diff + i);
				break;
			}
		}


	}

	return ;
}

// increasing sequence of natural no.s with one or more missing elements in between any two elements anywhere
void MultipleMissingSorted (int A[], int n)
{
	int diff;

	if (A && (n > 0))
	{
		diff = A[0] - 0;

		for (int i = 0; i < n; i++)
		{
			if ((A[i] - i) != diff)
			{
				while (diff < (A[i] - i))
				{
					printf ("%d ", diff + i);
					diff += 1;
				}
			}
		}

		printf ("\n");
	}

	return ;
}

// sequence of natural no.s starting from l upto h
void MultipleMissingUnsortedHash (int A[], int n, int l, int h)
{
	int *H = NULL;

	if (A && (n > 0) && (l > 0) && (h >= l)
			&& (H = (int *) calloc ((h + 1), sizeof (int))))
	{
		for (int i = 0; i < n; i++)
			H[A[i]] += 1;

		for (int i = l; i <= h; i++)
			if (!H[i])
				printf ("%d ", i);

		printf ("\n");

		free (H);
	}

	return ;
}

// prints duplicate element in sorted array
void DuplicateSorted (int A[], int n)
{
	int duplicate;

	if (A && (n > 0))
	{
		duplicate = INT_MIN;

		for (int i = 0; i < (n - 1); i++)
		{
			if ((A[i] == A[i + 1]) && (A[i] != duplicate))
			{
				duplicate = A[i];
				printf ("%d ", A[i]);
			}
		}

		printf("\n");
	}

	return ;
}

void DuplicateCountSorted (int A[], int n)
{
	if (A && (n > 0))
	{
		for (int i = 0, j = 0; i < (n - 1); i++)
		{
			if (A[i] == A[i + 1])
			{
				j = i + 1;

				while (A[j] == A[i])
					j += 1;

				printf ("%d repeats %d times\n", A[i], j - i);

				i = j - 1;
			}
		}

	}

	return ;
}

void DuplicateCountHashing (int A[], int n, int l, int h)
{
	// array may or may not be sorted
	// create an hashing array of length h + 1

	int *H = NULL;

	if (A && (n > 0) && (l > 0) && (h >= l)
			&& (H = (int *) calloc ((h + 1), sizeof (int))))
	{
		for (int i = 0; i < n; i++)
			H[A[i]] += 1;

		for (int i = l; i <= h; i++)
			if (H[i] > 1)
				printf ("%d repeats %d times\n", i, H[i]);
		printf ("\n");

		free (H);
	}

	return ;
}

// if duplicate is found it is made -1 to avoid getting it counted again
void DuplicateCountUnsorted(int A[], int n)
{
	int count;

	if (A && (n > 0))
	{
		for (int i = 0; i < (n - 1); i++)
		{
			count = 1;

			if (A[i] != -1)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (A[j] == A[i])
					{
						A[j] = -1;
						count += 1;
					}
				}

				if (count > 1)
					printf("%d repeats %d times\n", A[i], count);
			}
		}

	}

	return ;
}

// arr with no duplicates may be sorted or unsorted
// n is length and k is sum to of pair to be found
void PairSum (int A[], int n, int k)
{
	if (A && (n > 0))
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if ((A[i] + A[j]) == k)
					printf ("%d + %d = %d\n", A[i], A[j], k);

	return ;
}

// arr with no duplicates
void PairSumHash (int A[], int n, int k, int h)
{
	int *H  = NULL;

	if (A && (n > 0) && (H = (int *) calloc ((h + 1), sizeof (int))))
	{
		for (int i = 0; i < n; i++)
		{
			H[A[i]] += 1;

			if (H[k - A[i]])
				printf("%d + %d = %d\n", A[i], k - A[i], k);
		}

		free (H);
	}

	return ;
}

void PairSumSorted(int A[], int n, int k)
{
	int i, j;

	if (A && (n > 0))
	{
		i = 0, j = n - 1;

		while (i < j)
		{
			if ((A[i] + A[j]) == k)
			{
				printf ("%d + %d = %d\n", A[i], A[j], k);
				i += 1, j -= 1;
			}
			else if ((A[i] + A[j]) < k)
				i++;
			else
				j--;
		}
	}

	return ;
}

void MinMax (int A[], int n)
{
	int min, max;

	if (A && (n > 0))
	{
		min = max = A[0];

		for (int i = 1; i < n; i++)
		{
			// best case if array is sorted descending
			if (A[i] < min)
				min = A[i];
			// worst case if array sorted ascending
			else if (A[i] > max)
				max = A[i];
		}

		printf ("%d, %d\n", min, max);
	}

	return ;
}

int main (int argc, char const *argv[])
{
	int A[10] = {1, 50, 4, -5, 6, 7, 18, 9, -12, 14};

	MinMax (A, 10);

	return 0;
}

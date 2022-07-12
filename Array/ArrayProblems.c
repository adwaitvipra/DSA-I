#include <stdio.h>
#include <stdlib.h>

void SingleMissingNatural(int A[], int n) // natural numbers array must start form 1
{
    int sum = 0, s;
    s = A[n - 1] * (A[n - 1] + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    printf("%d \n", s - sum);
}
void SingleMissingSorted(int A[], int n) // increasing sequence of natural no.s
{
    int diff; // arr can start from anywhere
    diff = A[0] - 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] - i != diff)
        {
            printf("%d \n", diff + i);
            break;
        }
    }
}
void MultipleMissingSorted(int A[], int n) // increasing sequence of natural no.s with one or more missing elements in between any two elements anywhere
{
    int diff = A[0] - 0; // arr can start from anywhere
    for (int i = 0; i < n; i++)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                printf("%d \n", diff + i);
                diff++;
            }
        }
    }
}
void MultipleMissingUnsortedHash(int A[], int n, int l, int h) // sequence of natural no.s starting from l upto h
{
    // create an Hashing array of length h+1
    int *H;
    H = (int *)malloc(sizeof(int) * (h + 1));
    for (int i = 0; i <= h; i++) // init its all elements to 0
        H[i] = 0;
    for (int i = 0; i < n; i++) // scan through all ele of A and increment
        H[A[i]]++;
    for (int i = l; i <= h; i++)
    {
        if (H[i] == 0)
            printf("%d ", i);
    }
    printf("\n");
}
void DuplicateSorted(int A[], int n) // prints duplicate element in sorted array
{
    int lastDuplicate = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate)
        {
            printf("%d ", A[i]);
            lastDuplicate = A[i];
        }
    }
    printf("\n");
}
void DuplicateCountSorted(int A[], int n)
{
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            j = i + 1;
            while (A[j] == A[i])
                j++;
            printf("%d is appeared %d times\n", A[i], j - i);
            i = j - 1;
        }
    }
}
void DuplicateCountHashing(int A[], int n, int l, int h)
{ // array may or may not be sorted
    // create an Hashing array of length h+1
    int *H;
    H = (int *)malloc(sizeof(int) * (h + 1));
    for (int i = 0; i <= h; i++) // init its all elements to 0
        H[i] = 0;
    for (int i = 0; i < n; i++) // scan through all ele of A and increment index of H
        H[A[i]]++;
    for (int i = l; i <= h; i++)
    {
        if (H[i] > 1)
            printf("%d appears %d times\n", i, H[i]);
    }
    printf("\n");
}
void DuplicateCountUnsorted(int A[], int n) // if duplicate is found it is made -1 to avoid getting it counted again
{
    int i, j;
    int count;
    for (i = 0; i < n - 1; i++)
    {
        count = 1;
        if (A[i] != -1)
        {
            for (j = i + 1; j < n; j++)
            {
                if (A[j] == A[i])
                {
                    count++;
                    A[j] = -1;
                }
            }
            if (count > 1)
                printf("%d appears %d times\n", A[i], count);
        }
    }
}
void PairSum(int A[], int n, int k) // n is length and k is sum to of pair to be found
{                                   // arr with no duplicates may be sorted or unsorted
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == k)
                printf("%d + %d = %d\n", A[i], A[j], k);
        }
    }
}
void PairSumHash(int A[], int n, int k, int h) // arr with no duplicates
{
    int *H, i, j;
    H = (int *)malloc(sizeof(int) * (h + 1));
    for (i = 0; i < n - 1; i++)
    {
        if (H[k - A[i]] != 0)
        {
            printf("%d + %d = %d\n", A[i], k - A[i], k);
        }
        H[A[i]]++;
    }
}
void PairSumSorted(int A[], int n, int k)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (A[i] + A[j] == k)
        {
            printf("%d + %d = %d\n", A[i], A[j], k);
            i++;
            j++;
        }
        else if (A[i] + A[j] < k)
            i++;
        else
            j--;
    }
}
void MinMax(int A[], int n)
{
    int min, max, i;
    min = max = A[0];
    for (i = 1; i < n; i++)
    {
        if (A[i] < min) // best case if array is sorted descending
            min = A[i];
        else if (A[i] > max) // worst case if array sorted ascending
            max = A[i];
    }
    printf("%d %d", min, max);
}
int main(int argc, char const *argv[])
{
    int A[10] = {1, 50, 4, -5, 6, 7, 18, 9, -12, 14};
    MinMax(A, 10);
    return 0;
}

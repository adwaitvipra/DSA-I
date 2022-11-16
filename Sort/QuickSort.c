#include <stdio.h>
/* Quick Sort */
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
int Partition(int *A, int start, int end) // returns partition index of a pivot ele which is on rightmost position in the arr
{
    int i, pivot, partitionIndex;
    pivot = A[end];
    partitionIndex = start;
    for (i = start; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            Swap(&A[i], &A[partitionIndex]);
            partitionIndex++;
        }
    }
    Swap(&A[partitionIndex], &A[end]);
    return partitionIndex;
}
void QuickSort(int *A, int start, int end)
{
    if (start < end)
    {
        int partitionIndex = Partition(A, start, end);
        QuickSort(A, start, partitionIndex - 1);
        QuickSort(A, partitionIndex + 1, end);
    }
}
int main(int argc, char const *argv[])
{
    int A[]={9,1,8,2,7,3,6,4,5};
    QuickSort(A,0,8);
    for(int i=0;i<9;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

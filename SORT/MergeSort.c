// Merge sort algorithm
#include <stdio.h>
#include <stdlib.h>

void Merge(int *A, int start, int mid , int end)
{
    int len = end - start + 1;
    int *B = (int *)malloc(sizeof(int) * len);
    int i, j, k;
    i = start, j = mid+1, k = 0;
    while (i <= mid && j <= end)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else if (A[i] > A[j])
            B[k++] = A[j++];
        else
        {
            B[k++] = A[i]++;
            j++;
        }
    }
    while (i <= mid)
        B[k++] = A[i++];
    while (j <= end)
        B[k++] = A[j++];
    
    for(i=start,j=0;i<=end;i++,j++)
            A[i]=B[j];
    return;
}
void MergeSort(int *A, int start, int end)
{
    int mid = (start + end) / 2;
    if (start < end)
    {
        MergeSort(A, start, mid);
        MergeSort(A, mid + 1, end);
        Merge(A, start, mid, end);
    }
}
int main(int argc, char const *argv[])
{
    int A[]={44,64,86,25,52,40,12,9,7,3,6,4,0};
    int len=sizeof(A)/sizeof(int);
    MergeSort(A,0,len-1);
    for(int i=0;i<len;i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}

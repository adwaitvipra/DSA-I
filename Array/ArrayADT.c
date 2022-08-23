#include <stdio.h>
#include <stdlib.h>

struct Array
{

    int *A; // for arr in heap
    int size;
    int length;
};

int Overflow(struct Array arr)
{
    if (arr.length == arr.size)
    {
        printf("\nOverflow!\n");
        return 1;
    }
    return 0;
}
int Underflow(struct Array arr)
{
    if (arr.length == 0)
    {
        printf("\nUnderflow!\n");
        return 1;
    }
    return 0;
}
void Display(struct Array arr)
{
    if (Underflow(arr))
        return;
    int i;
    printf("Elements of array are:\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
    return;
}
void Append(struct Array *arr, int x)
{
    if (Overflow(*arr))
        return;
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
    printf("\n");
    return;
}
void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (Overflow(*arr))
        return;
    if (index >= 0 && index <= arr->length) // to insert index passed must be between 0 to length -> [0, lenght)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
        return;
    }
    printf("Bad Index!\n");
    return;
}
int Delete(struct Array *arr, int index)
{
    if (Underflow(*arr))
        return -1;
    int i, x;
    if (index >= 0 && index < arr->length) // Check if index is valid or not
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    printf("Bad Index!\n");
    return -1;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinSearch(struct Array arr, int key)
{
    if (Underflow(arr))
        return -1;
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
            return i;
    }
    return -1;
}
int ImLinSearchTransposition(struct Array *arr, int key)
{
    if (Underflow(*arr))
        return -1;
    int i, temp;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            if (i > 0)
            {
                swap(&arr->A[i], &arr->A[i - 1]);
                return i - 1;
            }
            return 0;
        }
    }
    return -1;
}
int ImLinSearchMove2Front(struct Array *arr, int key)
{
    if (Underflow(*arr))
        return -1;
    int i, temp;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            if (i > 0)
            {
                swap(&arr->A[i], &arr->A[0]);
                return 0;
            }
            return 0;
        }
    }
    return -1;
}
int IBinSearch(struct Array arr, int l, int h, int key)
{
    if (Underflow(arr))
        return -1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid]) // key is on left
            h = mid - 1;
        else // key is on right
            l = mid + 1;
    }
    return -1;
}
int RBinSearch(struct Array arr, int l, int h, int key) // Better to convert into loop because it uses stack internally
{
    if (Underflow(arr))
        return -1;
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            return RBinSearch(arr, l, mid - 1, key);
        else
            return RBinSearch(arr, mid + 1, h, key);
    }
    return -1;
}
int Get(struct Array arr, int index)
{
    if (Underflow(arr))
        return -1;
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}
void Set(struct Array *arr, int index, int x)
{
    if (Underflow(*arr))
        return;
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
    return;
}
int ISum(struct Array arr)
{
    if (Underflow(arr))
        return -1;
    int i, s = 0;
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}
int RSum(struct Array arr, int n) // n must be length-1 tail recursive better to convert into loop
{
    if (Underflow(arr))
        return -1;
    if (n < 0)
        return 0;
    return RSum(arr, n - 1) + arr.A[n];
}
float Avg(struct Array arr)
{
    return (float)ISum(arr) / arr.length;
}
int Max(struct Array arr)
{
    if (Underflow(arr))
        return -1;
    int max = arr.A[0], i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}
int Min(struct Array arr)
{
    if (Underflow(arr))
        return -1;
    int min = arr.A[0], i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
void ReverseAux(struct Array *arr) // auxillary arr is used to reverse copy ele of orignal arr and again copied in orignal arr.
{
    if (Underflow(*arr))
        return;

    int *B;
    B = (int *)malloc(arr->length * sizeof(int));
    int i, j;
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
    return;
}
void ReverseInterchange(struct Array *arr) // better than above
{
    if (Underflow(*arr))
        return;
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--) // loop runs until i is less than j
        swap(&arr->A[i], &arr->A[j]);
    return;
}
void ShiftLeft(struct Array *arr)
{
    if (Underflow(*arr))
        return;
    int i;
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = 0;
    return;
}
void RotateLeft(struct Array *arr)
{
    if (Underflow(*arr))
        return;
    int i, temp;
    temp = arr->A[0];
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = temp;
    return;
}
void InsertSorted(struct Array *arr, int x) // each elem is shifted one place further until x is less than elem
{
    if (Overflow(*arr))
        return;
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
    return;
}
int IsSorted(struct Array arr)
{
    if (Underflow(arr))
        return -1;
    int i;
    for (i = 0; i < arr.length - 1; i++)
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    return 1;
}
void Rearrange(struct Array *arr) // -ve on left and +ve on right
{
    if (Underflow(*arr))
        return;
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++; // incr i until +ve ele found
        while (arr->A[j] >= 0)
            j--; // decr j until -ve ele found
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
    return;
}

struct Array *Merge(struct Array *arr1, struct Array *arr2) // actual param should be sorted arrays
{
    if (Underflow(*arr1) && Underflow(*arr2))
        return NULL;
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = arr1->length + arr2->length;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    return arr3;
}
int SetMembership(struct Array arr, int key)
{
    if (Underflow(arr))
        return 0;
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
            return 1;
    }
    return 0;
}

struct Array *UnionUnsorted(struct Array *arr1, struct Array *arr2)
{
    if (Underflow(*arr1) && Underflow(*arr2))
        return NULL;
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    for (; i < arr1->length; i++) // copying A in C
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    for (; j < arr2->length; j++)
        if (!(SetMembership(*arr3, arr2->A[j]))) // copying elements of B that are not in C
        {
            arr3->A[k++] = arr2->A[j];
            arr3->length = k; // updating length of C
        }
    arr3->size = arr1->length + arr2->length;
    return arr3;
}
struct Array *IntersectionUnsorted(struct Array *arr1, struct Array *arr2)
{
    if (Underflow(*arr1) && Underflow(*arr2))
        return NULL;
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    for (; i < arr1->length; i++)
    {
        if (SetMembership(*arr2, arr1->A[i])) // copying elements common to A and B into C.
        {
            arr3->A[k++] = arr1->A[i];
        }
    }
    arr3->length = k;
    arr3->size = arr1->length + arr2->length;
    return arr3;
}
struct Array *DifferenceUnsorted(struct Array *arr1, struct Array *arr2)
{
    if (Underflow(*arr1) && Underflow(*arr2))
        return NULL;
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    for (; i < arr1->length; i++) // copying elements of A to C that are not present in B
        if (!SetMembership(*arr2, arr1->A[i]))
            arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = arr1->length + arr2->length;
    return arr3;
}
struct Array *Union(struct Array *arr1, struct Array *arr2) // sorted arrays are passed as actual param
{
    if (Underflow(*arr1) && Underflow(*arr2))
        return NULL;
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else // if both element are equal only one is copied and ptrs are incremented
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    } // Remaining Elements of either of A and B are copied into C
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->size = arr1->length + arr2->length;
    arr3->length = k;
    return arr3;
}
struct Array *Intersection(struct Array *arr1, struct Array *arr2) // sorted arrays are passed as actual param
{
    if (Underflow(*arr1) && Underflow(*arr2))
        return NULL;
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else // Elements that are present in both A and B are copied to C
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    } // Remaining elements in any array are not copied
    arr3->size = arr1->length + arr2->length;
    arr3->length = k;
    return arr3;
}
struct Array *Difference(struct Array *arr1, struct Array *arr2) // sorted array are passed
{
    if (Underflow(*arr1) && Underflow(*arr2))
        return NULL;
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j]) // Only elements that belong to A are copied to C
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++) // Remaining elements in A are copied into C
        arr3->A[k++] = arr1->A[i];
    arr3->size = arr1->length + arr2->length;
    arr3->length = k;
    return arr3;
}
int main(int argc, char const *argv[])
{
    struct Array arr;

    printf("Enter Size of Array :");
    scanf(" %d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));

    printf("Enter Length of Array :");
    scanf(" %d", &arr.length);

    printf("Enter All Elements:");
    for (int i = 0; i < arr.length; i++)
        scanf(" %d", &arr.A[i]);

    return 0;
}

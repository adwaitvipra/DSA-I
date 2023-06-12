#include <iostream>

using namespace std;
template <class T>
class Array
{
private:
    T *A; // for arr in heap
    int size;
    int length;
    void swap(T *, T *);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new T[size];
    }
    Array(int s)
    {
        size = s;
        length = 0;
        A = new T[size];
    }
    ~Array()
    {
        delete[] A;
    }
    int Overflow();
    int Underflow();
    void Display();
    void Append(T);
    void Insert(int, T);
    T Delete(int);
    int LinSearch(T);
    int ImLinSearch(T);
    int ImLinSearchTransposition(T);
    int ImLinSearchMove2Front(T);
    int IBinSearch(int, int, T);
    int RBinSearch(int, int, T);
    T Get(int);
    void Set(int, T);
    T ISum();
    T RSum(int);
    double Avg();
    T Max();
    T Min();
    void ReverseAux();
    void ReverseInterchange();
    void ShiftLeft();
    void RotateLeft();
    void InsertSorted(T);
    int IsSorted();
    void Rearrange();
    int SetMembership(T);
    Array *Merge(Array *);
    Array *UnionUnsorted(Array *);
    Array *IntersectionUnsorted(Array *);
    Array *DifferenceUnsorted(Array *);
    Array *Union(Array *);
    Array *Intersection(Array *);
    Array *Difference(Array *);
};
template<class T>
int Array<T>::Overflow()
{
    if (length == size)
    {
        cout << "\nOverflow!\n";
        return 1;
    }
    return 0;
}
template<class T>
int Array<T>::Underflow()
{
    if (length == 0)
    {
        cout << "\nUnderflow!\n";
        return 1;
    }
    return 0;
}
template<class T>
void Array<T>::Display()
{
    if (Underflow())
        return;
    int i;
    cout << "Elements of array are:\n";
    for (i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
    return;
}
template<class T>
void Array<T>::Append(T x)
{
    if (Overflow())
        return;
    if (length < size)
        A[length++] = x;
    return;
}
template<class T>
void Array<T>::Insert(int index, T x)
{
    int i;
    if (Overflow())
        return;
    if (index >= 0 && index <= length) // to insert index passed must be between 0 to length
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
        return;
    }
    cout << "Bad Index!\n";
    return;
}
template<class T>
T Array<T>::Delete(int index)
{
    if (Underflow())
        return -1;
    int i;
    T x;
    if (index >= 0 && index < length) // Check if index is valid or not
    {
        x = A[index];
        for (i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }
    cout << "Bad Index!\n";
    return -1;
}
template<class T>
void Array<T>::swap(T *x, T *y)
{
    T temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
template<class T>
int Array<T>::LinSearch(T key)
{
    if (Underflow())
        return -1;
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
            return i;
    }
    return -1;
}
template<class T>
int Array<T>::ImLinSearchTransposition(T key)
{
    if (Underflow())
        return -1;
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            if (i > 0)
            {
                swap(&A[i], &A[i - 1]);
                return i - 1;
            }
            return 0;
        }
    }
    return -1;
}
template<class T>
int Array<T>::ImLinSearchMove2Front(T key)
{
    if (Underflow())
        return -1;
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            if (i > 0)
            {
                swap(&A[i], &A[0]);
                return 0;
            }
            return 0;
        }
    }
    return -1;
}
template<class T>
int Array<T>::IBinSearch(int l, int h, T key)
{
    if (Underflow())
        return -1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid]) // key is on left
            h = mid - 1;
        else // key is on right
            l = mid + 1;
    }
    return -1;
}
template<class T>
int Array<T>::RBinSearch(int l, int h, T key) // Better to convert into loop because it uses stack internally
{
    if (Underflow())
        return -1;
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return RBinSearch(l, mid - 1, key);
        else
            return RBinSearch(mid + 1, h, key);
    }
    return -1;
}
template<class T>
T Array<T>::Get(int index)
{
    if (Underflow())
        return -1;
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}
template<class T>
void Array<T>::Set(int index, T x)
{
    if (Underflow())
        return;
    if (index >= 0 && index < length)
        A[index] = x;
    return;
}
template<class T>
T Array<T>::ISum()
{
    if (Underflow())
        return -1;
    int i;
    T s = 0;
    for (i = 0; i < length; i++)
        s += A[i];
    return s;
}
template<class T>
T Array<T>::RSum(int n) // n must be length-1 tail recursive better to convert into loop
{
    if (Underflow())
        return -1;
    if (n < 0)
        return 0;
    return RSum(n - 1) + A[n];
}
template<class T>
double Array<T>::Avg()
{
    return (double) ISum() / length;
}
template<class T>
T Array<T>::Max()
{
    if (Underflow())
        return -1;
    T max = A[0];
    int i;
    for (i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
template<class T>
T Array<T>::Min()
{
    if (Underflow())
        return -1;
    T min = A[0]; int i;
    for (i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}
template<class T>
void Array<T>::ReverseAux() // auxillary arr is used to reverse copy ele of orignal arr and again copied in orignal arr.
{
    if (Underflow())
        return;

    int *B;
    B = new T[length];
    int i, j;
    for (i = length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    for (i = 0; i < length; i++)
        A[i] = B[i];
    return;
}
template<class T>
void Array<T>::ReverseInterchange() // better than above
{
    if (Underflow())
        return;
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) // loop runs until i is less than j
        swap(&A[i], &A[j]);
    return;
}
template<class T>
void Array<T>::ShiftLeft()
{
    if (Underflow())
        return;
    int i;
    for (i = 0; i < length - 1; i++)
    {
        A[i] = A[i + 1];
    }
    A[length - 1] = 0;
    return;
}
template<class T>
void Array<T>::RotateLeft()
{
    if (Underflow())
        return;
    int i;
    T temp;
    temp = A[0];
    for (i = 0; i < length - 1; i++)
    {
        A[i] = A[i + 1];
    }
    A[length - 1] = temp;
    return;
}
template<class T>
void Array<T>::InsertSorted(T x) // each elem is shifted one place further until x is less than elem
{
    if (Overflow())
        return;
    int i = length - 1;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
    return;
}
template<class T>
int Array<T>::IsSorted()
{
    if (Underflow())
        return -1;
    int i;
    for (i = 0; i < length - 1; i++)
        if (A[i] > A[i + 1])
            return 0;
    return 1;
}
template<class T>
void Array<T>::Rearrange() // -ve on left and +ve on right
{
    if (Underflow())
        return;
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++; // incr i until +ve ele found
        while (A[j] >= 0)
            j--; // decr j until -ve ele found
        if (i < j)
            swap(&A[i], &A[j]);
    }
    return;
}
template<class T>
Array<T> *Array<T>::Merge(Array *arr2) // actual param should be sorted arrays
{
    if (Underflow() && arr2->Underflow())
        return NULL;
    int i, j, k;
    i = j = k = 0;
    Array *arr3;
    arr3 = new Array(length + arr2->length);
    arr3->size = size + arr2->size;
    arr3->length = length + arr2->length;
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    return arr3;
}
template<class T>
int Array<T>::SetMembership(T key)
{
    if (Underflow())
        return 0;
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
            return 1;
    }
    return 0;
}
template<class T>
Array<T> *Array<T>::UnionUnsorted(Array *arr2)
{
    if (Underflow() && arr2->Underflow())
        return NULL;
    int i, j, k;
    i = j = k = 0;
    Array *arr3;
    arr3 = new Array(length + arr2->length);
    for (; i < length; i++) // copying A in C
    {
        arr3->A[k++] = A[i];
    }
    arr3->length = k;
    for (; j < arr2->length; j++)
        if (!(arr3->SetMembership(arr2->A[j]))) // copying elements of B that are not in C
        {
            arr3->A[k++] = arr2->A[j];
            arr3->length = k; // updating length of C
        }
    arr3->size = length + arr2->length;
    return arr3;
}
template<class T>
Array<T> *Array<T>::IntersectionUnsorted(Array *arr2)
{
    if (Underflow() && arr2->Underflow())
        return NULL;
    int i, j, k;
    i = j = k = 0;
    Array *arr3;
    arr3 = new Array(length + arr2->length);
    for (; i < length; i++)
    {
        if (arr2->SetMembership(A[i])) // copying elements common to A and B into C.
        {
            arr3->A[k++] = A[i];
        }
    }
    arr3->length = k;
    arr3->size = length + arr2->length;
    return arr3;
}
template<class T>
Array<T> *Array<T>::DifferenceUnsorted(Array *arr2)
{
    if (Underflow() && arr2->Underflow())
        return NULL;
    int i, j, k;
    i = j = k = 0;
    Array *arr3;
    arr3 = new Array(length + arr2->length);
    for (; i < length; i++) // copying elements of A to C that are not present in B
        if (!arr2->SetMembership(A[i]))
            arr3->A[k++] = A[i];
    arr3->length = k;
    arr3->size = length + arr2->length;
    return arr3;
}
template<class T>
Array<T> *Array<T>::Union(Array *arr2) // sorted arrays are passed as actual param
{
    if (Underflow() && arr2->Underflow())
        return NULL;
    int i, j, k;
    i = j = k = 0;
    Array *arr3;
    arr3 = new Array(length + arr2->length);
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (arr2->A[j] < A[i])
            arr3->A[k++] = arr2->A[j++];
        else // if both element are equal only one is copied and ptrs are incremented
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    } // Remaining Elements of either of A and B are copied into C
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->size = length + arr2->length;
    arr3->length = k;
    return arr3;
}
template <class T>
Array<T> *Array<T>::Intersection(Array *arr2) // sorted arrays are passed as actual param
{
    if (Underflow() && arr2->Underflow())
        return NULL;
    int i, j, k;
    i = j = k = 0;
    Array *arr3;
    arr3 = new Array(length + arr2->length);
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < A[i])
            j++;
        else // Elements that are present in both A and B are copied to C
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    } // Remaining elements in any array are not copied
    arr3->size = length + arr2->length;
    arr3->length = k;
    return arr3;
}
template <class T>
Array<T> *Array<T>::Difference(Array *arr2) // sorted array are passed
{
    if (Underflow() && arr2->Underflow())
        return NULL;
    int i, j, k;
    i = j = k = 0;
    Array *arr3;
    arr3 = (Array *)malloc(sizeof(Array));
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j]) // Only elements that belong to A are copied to C
            arr3->A[k++] = A[i++];
        else if (arr2->A[j] < A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++) // Remaining elements in A are copied into C
        arr3->A[k++] = A[i];
    arr3->size = length + arr2->length;
    arr3->length = k;
    return arr3;
}
int main(int argc, char const *argv[])
{

    return 0;
}

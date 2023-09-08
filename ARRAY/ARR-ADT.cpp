#include <iostream>
#include <climits>

using namespace std;

template <typename T>
class Array
{
	private:
		T *A;
		int size;
		int capacity;

		void Swap (T *, T *);

	public:
		Array ()
		{
			capacity = 10;
			size = 0;
			A = new T[capacity];
		}

		Array (int s)
		{
			capacity = s;
			size = 0;
			A = new T[capacity];
		}

		~Array ()
		{
			delete[] A;
		}

		bool Overflow ();
		bool Underflow ();

		void Display ();

		void Append (T);
		void Insert (int, T);
		void InsertSorted (T);

		T Delete (int);

		int LinSearch (T);
		int ImLinSearch (T);
		int ImLinSearchTransposition (T);
		int ImLinSearchMove2Front (T);
		int IBinSearch (int, int, T);
		int RBinSearch (int, int, T);

		T Get (int);
		void Set (int, T);

		T ISum ();
		T RSum (int);

		double Average ();

		T Max ();
		T Min ();

		void ReverseAux ();
		void ReverseInterchange ();

		void ShiftLeft ();
		void RotateLeft ();

		bool IsSorted ();

		void Rearrange ();

		Array *Merge (Array *);

		bool SetMembership (T);

		Array *UnionUnsorted (Array *);
		Array *IntersectionUnsorted (Array *);
		Array *DifferenceUnsorted (Array *);

		Array *Union (Array *);
		Array *Intersection (Array *);
		Array *Difference (Array *);
};

	template <typename T>
bool Array <T> :: Overflow ()
{
	bool flag = false;

	if (size == capacity)
	{
		flag = true;
		cout << "\nOverflow!\n";
	}

	return flag;
}

	template <typename T>
bool Array <T> :: Underflow ()
{
	bool flag = false;

	if (size == 0)
	{
		flag = true;
		cout << "\nUnderflow!\n";
	}

	return flag;
}

	template <typename T>
void Array <T> :: Display ()
{
	if (!Underflow ())
	{
		cout << "Elements of array are:\n";
		for (int i = 0; i < size; i++)
			cout << A[i] << " ";
		cout << '\n';
	}

	return ;
}

	template <typename T>
void Array <T> :: Append (T x)
{
	if (!Overflow () && (size < capacity))
	{
		A[size] = x;
		size += 1;
	}

	return;
}

	template <typename T>
void Array <T> :: Insert (int index, T x)
{
	// to insert index passed must be between 0 to size
	if (!Overflow())
	{
		if (index >= 0 && index <= size)
		{
			for (int i = size; i > index; i--)
				A[i] = A[i - 1];
			A[index] = x;
			size += 1;
		}
		cout << "Bad Index!\n";
	}

	return;
}

	template <typename T>
T Array <T> :: Delete (int index)
{
	T ret;

	if (!Underflow ())
	{
		if (index >= 0 && index < size)
		{

			ret = A[index];

			for (int i = index; i < (size - 1); i++)
				A[i] = A[i + 1];

			size -= 1;
		}
		cout << "Bad Index!\n";
	}

	return ret;
}

	template <typename T>
void Array <T> :: Swap (T *x, T *y)
{
	T tmp;

	if (x && y)
	{
		tmp = *x;
		*x = *y;
		*y = tmp;
	}

	return ;
}

	template <typename T>
int Array <T> :: LinSearch (T key)
{
	int ret = INT_MIN; 

	if (!Underflow ())
	{
		for (int i = 0; i < size; i++)
		{
			if (key == A[i])
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}

	template <typename T>
int Array <T> :: ImLinSearchTransposition (T key)
{
	int ret = INT_MIN;

	if (!Underflow ())
	{
		for (int i = 0; i < size; i++)
		{
			if (key == A[i])
			{
				if (i)
				{
					Swap (&A[i], &A[i - 1]);
					ret = i - 1;
				}
				else
				{
					ret  = 0;
				}
			}
		}
	}

	return ret;
}

	template <typename T>
int Array <T> :: ImLinSearchMove2Front (T key)
{
	int ret = INT_MIN;

	if (!Underflow ())
	{
		for (int i = 0; i < size; i++)
		{
			if (key == A[i])
			{
				ret = 0;

				if (i)
					swap(&A[i], &A[0]);
			}
		}

	}

	return ret;
}

	template <typename T>
int Array <T> :: IBinSearch (int l, int h, T key)
{
	int mid, ret = INT_MIN;

	if (!Underflow ())
	{
		while (l <= h)
		{
			mid = (l + h) / 2;

			if (key == A[mid])
				ret = mid;
			// key is on left
			else if (key < A[mid])
				h = mid - 1;
			// key is on right
			else
				l = mid + 1;
		}
	}

	return ret;
}

// better to convert into loop because it uses stack internally
	template <typename T>
int Array <T> :: RBinSearch (int l, int h, T key)
{
	int mid, ret = INT_MIN;

	if (!Underflow ())
	{
		if (l <= h)
		{
			mid = (l + h) / 2;

			if (key == A[mid])
				ret = mid;
			else if (key < A[mid])
				ret = RBinSearch (l, mid - 1, key);
			else
				ret = RBinSearch (mid + 1, h, key);
		}

	}

	return ret;
}

	template <typename T>
T Array <T> :: Get (int index)
{
	T ret;

	if (!Underflow () && (index >= 0 && index < size))
		ret = A[index];

	return ret;
}

	template <typename T>
void Array <T> :: Set (int index, T x)
{
	if (!Underflow () && (index >= 0 && index < size))
		A[index] = x;

	return ;
}

	template <typename T>
T Array <T> :: ISum ()
{
	T sum = 0;

	if (!Underflow ())
		for (int i = 0; i < size; i++)
			sum += A[i];

	return sum;
}

// n must be size-1 tail recursive better to convert into loop
	template <typename T>
T Array <T> :: RSum (int n)
{
	T sum = 0;

	if (!Underflow ())
		sum  = RSum (n - 1) + A[n];

	return sum;
}

	template <typename T>
double Array <T> :: Average ()
{
	return (double) ISum () / size;
}

	template <typename T>
T Array <T> :: Max ()
{
	T mx;

	if (!Underflow ())
	{
		mx = A[0];
		for (int i = 1; i < size; i++)
			if (A[i] > mx)
				mx = A[i];
	}

	return mx;
}

	template <typename T>
T Array <T> :: Min ()
{
	T mn;

	if (!Underflow ())
	{
		for (int i = 1; i < size; i++)
			if (A[i] < mn)
				mn = A[i];
	}

	return mn;
}

// auxillary arr is used to reverse copy ele of orignal arr and again copied in orignal arr.
	template <typename T>
void Array <T> :: ReverseAux ()
{
	T *B;
	int i, j;

	if (!Underflow ())
	{
		B = new T[size];

		for ((i = size - 1), j = 0; i >= 0; i--, j++)
			B[j] = A[i];

		for (i = 0; i < size; i++)
			A[i] = B[i];
	}

	return ;
}

// better than above
	template <typename T>
void Array <T> :: ReverseInterchange ()
{
	if (!Underflow ())
		for (int i = 0, j = size - 1; i < j; i++, j--)
			swap(&A[i], &A[j]);

	return ;
}

	template <typename T>
void Array <T> :: ShiftLeft ()
{
	if (!Underflow ())
	{
		for (int i = 0; (i < size - 1); i++)
			A[i] = A[i + 1];
		A[size - 1] = 0;
	}

	return ;
}

	template <typename T>
void Array <T> :: RotateLeft ()
{
	T tmp;

	if (!Underflow ())
	{
		tmp = A[0];

		for (int i = 0; (i < size - 1); i++)
			A[i] = A[i + 1];

		A[size - 1] = tmp;
	}

	return ;
}

// each elem is shifted one place further until x is less than elem
	template <typename T>
void Array <T> :: InsertSorted (T x)
{
	int i;

	if (!Overflow ())
	{
		i = size - 1;
		while (i >= 0 && A[i] > x)
		{
			A[i + 1] = A[i];
			i--;
		}
		size += 1;
	}

	return ;
}

	template <typename T>
bool Array <T> :: IsSorted ()
{
	bool flag = true;

	if (!Underflow ())
	{
		for (int i = 0; (i < size - 1) && flag; i++)
			if (A[i] > A[i + 1])
				flag = false;
	}

	return flag;
}

// -ve on left and +ve on right
	template <typename T>
void Array <T> :: Rearrange ()
{
	int i, j;

	if (!Underflow ())
	{
		i = 0, j = size - 1;

		while (i < j)
		{
			while (A[i] < 0)
				i++;
			while (A[j] >= 0)
				j--;

			if (i < j)
				Swap (&A[i], &A[j]);
		}
	}

	return ;
}

// actual param should be sorted arrays
	template <typename T>
Array<T> *Array <T> :: Merge (Array *arrx)
{
	Array *arrz = nullptr;
	int i, j, k;

	if (arrx && !(arrx->Underflow ()) && !Underflow ())
	{
		i = j = k = 0;

		arrz = new Array (size + arrx->size);
		arrz->capacity = arrz->size = size + arrx->size;

		while ((i < size) && (j < arrx->size))
		{
			if (A[i] <= arrx->A[j])
			{
				if (A[i] == arrx->A[j])
					arrz->A[k++] = A[j++];

				arrz->A[k++] = A[i++];
			}
			else
				arrz->A[k++] = arrx->A[j++];
		}

		while (i < size)
			arrz->A[k++] = A[i++];

		while (j < arrx->size)
			arrz->A[k++] = arrx->A[j++];
	}

	return arrz;
}

	template <typename T>
bool Array <T> :: SetMembership (T key)
{
	bool flag = false;

	if (!Underflow ())
		for (int i = 0; (i < size) && !flag; i++)
			if (key == A[i])
				flag = true;

	return flag;
}

	template <typename T>
Array <T> *Array <T> :: UnionUnsorted (Array *arrx)
{
	int i, j, k;
	Array *arrz = nullptr;

	if (!Underflow () && !(arrx->Underflow ()))
	{
		arrz = new Array (size + arrx->size);
		arrz->size = 0;
		arrz->capacity = size + arrx->size;

		while (i < size)
			arrz->A[k++] = A[i++];

		while (j < arrx->size)
			if (!(arrz->SetMembership (arrx->A[j])))
				arrz->A[k++] = arrx->A[j++];

		arrz->size = k;
	}

	return arrz;
}

	template <typename T>
Array <T> *Array <T> :: IntersectionUnsorted (Array *arrx)
{
	int i, j;
	Array *arrz = nullptr;

	if (arrx && !(arrx->Underflow ()) && !Underflow ())
	{
		i = j = 0;

		arrz = new Array (size + arrx->size);
		arrz->capacity = size < arrx->size ? size : arrx->size;
		arrz->size = 0;

		while (i < size)
			if (arrx->SetMembership (A[i]))
				arrz->A[j++] = A[i++];
		arrz->size = j;
	}

	return arrz;
}

// copying elements of A to C that are not present in B
	template <typename T>
Array <T> *Array <T> :: DifferenceUnsorted (Array *arrx)
{
	int i, j;
	Array *arrz = nullptr;

	if (arrx && !(arrx->Underflow ()) && !Underflow ())
	{
		i = j = 0;

		arrz = new Array (size +  arrx->size);
		arrz->capacity = size;
		arrz->size = 0;

		while (i < size)
			if (!(arrx->SetMembership (A[i])))
				arrz->A[j++] = A[i++];
		arrz->size = j;
	}

	return arrz;
}

// sorted arrays are passed as actual param
	template <typename T>
Array <T> *Array <T> :: Union (Array *arrx)
{
	int i, j, k;
	Array *arrz = nullptr;

	if (arrx && !(arrx->Underflow ()) && !Underflow ())
	{
		i = j = k = 0;

		arrz = new Array (size + arrx->size);
		arrz->capacity = size + arrx->size;
		arrz->size = 0;

		while ((i < size) && (j < arrx->size))
		{
			if (A[i] <= arrx->A[j])
			{
				if (A[i] == arrx->A[j])
					j++;

				arrz->A[k++] = A[i++];
			}
			else
				arrz->A[k++] = arrx->A[j++];

		}

		while (i < size)
			arrz->A[k++] = A[i++];

		while (j < arrx->size)
			arrz->A[k++] = A[j++];

		arrz->size = k;

	}

	return arrz;
}

// sorted arrays are passed as actual param
	template <class T>
Array <T> *Array <T> :: Intersection (Array *arrx)
{
	int i, j, k;
	Array *arrz = nullptr;

	if (arrx && !(arrx->Underflow ()) && !Underflow ())
	{
		i = j = k = 0;
		arrz = new Array (size + arrx->size);
		arrz->capacity = size + arrx->size;
		arrz->size = 0;

		while ((i < size) && (j < arrx->size))
		{
			if (A[i] < arrx->A[j])
				i++;
			else if (arrx->A[j] < A[i])
				j++;
			// elements that are present in both A and B are copied to C
			else
			{
				j++;
				arrz->A[k++] = A[i++];
			}
		}
		// remaining elements in any array are not copied

		arrz->size = k;
	}

	return arrz;
}

// sorted array are passed
	template <class T>
Array <T> *Array <T> :: Difference (Array *arrx)
{
	int i, j, k;
	Array *arrz = nullptr;

	if (arrx && !(arrx->Underflow ()) && Underflow ())
	{
		i = j = k = 0;

		arrz = new Array (size);
		arrz->capacity = size;
		arrz->size = 0;

		while ((i < size) && (j < arrx->size))
		{
			// only elements that belong to A are copied to C
			if (A[i] < arrx->A[j])
				arrz->A[k++] = A[i++];
			else if (arrx->A[j] < A[i])
				j++;
			else
				i++, j++;
		}

		// remaining elements in A are copied into C
		while (i < size)
			arrz->A[k++] = A[i++];

		arrz->size = k;

	}

	return arrz;
}

int main (int argc, char const *argv[])
{
	return 0;
}

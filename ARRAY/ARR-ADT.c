#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct array{
	int *arr;
	int size;
	int length;
}array;
// DECLARATION
bool overflow(array );
bool underflow(array );
bool display(array );
bool append(array *, int );
bool insert(array *, int , int );
int delete(array *, int );

// DEFINATION
bool overflow(array arr)
{
	if (arr.length == arr.size)
	{
		printf("\nOverflow!\n");
		return true;
	}
	return false;
}

bool underflow(array arr)
{
	if (!arr.length)
	{
		printf("\nUnderflow!\n");
		return true;
	}
	return false;
}

bool display(array arr)
{
	if (!underflow(arr))
	{
		printf("\ndisplaying array elements (index, value)...\n");
		for (int i = 0; i < arr.length; i++)
			printf("(%d, %d) ", i, arr.arr[i]);
		printf("\n");

		return true;
	}
	return false;
}

bool append(array *arr, int val)
{
	if (!overflow(*arr))
	{
		arr->arr[(arr->length)++] = val;
		return true;
	}
	return false;
}

bool insert(array *arr, int idx, int val)
{
	if(!overflow(*arr) && ((idx >= 0) && (idx <= arr->length)))
	{
		for(int i=(arr->length)++; i>idx; i--)
			arr->arr[i] = arr->arr[i-1];
		arr->arr[idx] = val;

		return true;
	}
	return false;
}

int delete(array *arr, int idx)
{
	int retval=INT_MIN;

	if(!underflow(!arr) && ((idx >= 0) && (idx < arr->length)))
	{
		retval = arr->arr[idx];
		for(int i=idx; i<arr->length-1;i++)
			arr->arr[i] = arr->arr[i+1];

		arr->length--;
	}
	return retval;
}
array *copy(array arr)
{
	array* cp_arr = NULL;
	if((cp_arr = (int *)malloc(sizeof(array))) 
			&& (cp_arr->arr = (int *)malloc(sizeof(arr.size))))
	{
		for(int i=0; i<arr.length; i++)
			cp_arr->arr[i] = arr.arr[i];
		cp_arr.length = arr.length;
		cp_arr.size = arr.size;
	}
	else if(cp_arr)
	{
		free(cp_arr);
		cp_arr = NULL;
	}
	return cp_arr;
}

bool swap(int *xref,int *yref)
{
	if(xref && yref)
	{
		*xref = *xref + *yref;
		*yref = *xref - *yref;
		*xref = *xref - *yref;

		return true;
	}
	return false;
}

int sequential_search(array arr, int key)
{
	if(!underflow(arr))
		for(int i=0; i<arr.length; i++)
			if(arr.arr[i] == key)
				return i;
	return INT_MIN;
}

int xposition_seq_search(array *arr, int key)
{
	if(!underflow(*arr))
	{
		for(int i=0; i<arr->length; i++)
		{

			if(arr->arr[i] == key)
			{
				if(i > 0 && swap(&(arr->arr[i]), &(arr->arr[i-1])))
					return i-1;

				return i;
			}
		}
	}

	return INT_MIN;
}

int move_to_front_seq_search(array *arr, int key)
{	
	if(!underflow(*arr))
	{
		for(int i=0; i<arr->length; i++)
		{
			if(arr->arr[i] == key)
			{
				if(i > 0 && swap(&(arr->arr[i]), &(arr->arr[0])))
					return 0;
				return i;
			}
		}
	}
	return INT_MIN;
}

int iterative_binary_search(array arr, int low, int high, int key)
{
	int mid;
	if (!underflow(arr))
	{
		while (low <= high)
		{
			mid = (low + high) / 2;

			if (key == arr.arr[mid])
				return mid;
			else if (key < arr.arr[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return INT_MIN;
}

int recursive_binary_search(array arr, int low, int high, int key)
{
	int mid;
	if (!underflow(arr))
	{
		if (low <= high)
		{
			mid = (low + high) / 2;
			if (key == arr.arr[mid])
				return mid;
			else if (key < arr.arr[mid])
				return recursive_binary_search(arr, low, mid - 1, key);
			else
				return recursive_binary_search(arr, mid + 1, high, key);
		}
	}
	return INT_MIN;
}

int get_element(array arr, int idx)
{
	if (!underflow(arr) && (idx >= 0 && idx < arr.length))
		return arr.arr[idx];
	return INT_MIN;
}

bool set_index(array *arr, int idx, int val)
{
	if (!underflow(arr) && (idx >= 0 && idx < arr.length))
	{
		arr.arr[idx] = val;
		return true;
	}

	return false;
}

int iterative_sum(array arr)
{
	int sum = 0;
	if(!underflow(arr))
		for(int i=0; i<arr.length; i++)
			sum += arr.arr[i];
	return sum;
}

int recursive_sum(array arr) // n must be length-1 tail recursive better to convert into loop
{
	if(!underflow(arr))
		return recursive_sum_true(arr.arr, arr.length - 1);
	return 0;
}

int recursive_sum_true(int *arr, int n)
{
	if(n >= 0)
		return recursive_sum_true(arr, n - 1) + arr->arr[n]; 
	return 0;
}

float average(array arr)
{
	return (float)iterative_sum(arr) / arr.length;
}

int max(array arr)
{
	int max = INT_MIN;
	if(!underflow(arr))
	{
		for(int i=0; i<arr.length; i++)
		{
			if(arr.arr[i] > max)
				max = arr.arr[i];
		}
	}

	return max;
}

int min(array arr)
{
	int min= INT_MAX;
	if(!underflow(arr))
	{
		for(int i=0; i<arr.length; i++)
		{
			if(arr.arr[i] < min)
				min = arr.arr[i];
		}
	}

	return min;
}

bool auxillary_arr_reverse(array *arr) 
{
	int i, *aux_arr = NULL;
	if(!underflow(*arr))
	{
		if(!(aux_arr = (int*)malloc(sizeof(int) * arr->length)))
			return false;
		for(i=0; i<arr->length; i++)
			aux_arr[i] = arr->arr[i];
		for(; i>0; i--)
			arr->arr[arr->length - i] = aux_arr[i-1];

		free(aux_arr);
		return true;
	}
	return false;
}

bool reverse_interchange(array *arr) 
{
	if(!underflow(*arr))
	{
		for(int i=0, j=(arr->length-1); i < j; i++, j--)
			swap(&(arr->arr[i]),&(arr->arr[j]));

		return true;
	}

	return false;
}

bool left_shift(array *arr)
{
	if(!underflow(*arr))
	{
		for(int i=0; i < arr->length - 1; i++)
		{
			arr->arr[i] = arr->arr[i+1];
		}
		arr[arr->length-1] = 0;

		return true;
	}

	return false;
}

bool right_shift(array *arr)
{
	if(!underflow(*arr))
	{
		for(int i=arr->length - 1; i>0; i--)
		{
			arr->arr[i] = arr->arr[i-1];
		}
		arr[0] = 0;

		return true;
	}

	return false;
}

bool rotate_left(array *arr)
{
	int tmp;
	if(!underflow(*arr))
	{
		tmp = arr->arr[0];
		for(int i=0; i < arr->length - 1; i++)
		{
			arr->arr[i] = arr->arr[i+1];
		}
		arr[arr->length-1] = tmp;

		return true;
	}

	return false;
}

bool rotate_right(array *arr)
{
	int tmp;
	if(!underflow(*arr))
	{
		tmp = arr->arr[arr->length - 1];
		for(int i = arr->length - 1; i>0; i--)
		{
			arr->arr[i] = arr->arr[i-1];
		}
		arr[0] = tmp;

		return true;
	}

	return false;
}

bool insert_into_sorted_arr(array *arr, int val)
{

	if(!overflow(*arr))
	{
		for(int i=(arr->length)++(-1); i>0 && val<arr->arr[i]; i--)
			arr->arr[i] = arr->arr[i-1]
				arr->arr[i] = val;

		return true;
	}
	return false;
}

bool is_sorted(array arr)
{
	if(!underflow(arr))
	{
		for(inti=1; i<arr.length; i++)
			if(arr.arr[i] < arr.arr[i-1])
				return false;	
		return true;
	}
	return false;
}

bool rearrage(array *arr) // -ve on left and +ve on right
{
	int i = 0;
	int j = arr->length - 1;
	if(!underflow(*arr))
	{
		while (i < j)
		{
			while (arr->arr[i] < 0)
				i++; // incr i until +ve ele found
			while (arr->arr[j] >= 0)
				j--; // decr j until -ve ele found
			if (i < j)
				swap(&arr->arr[i], &arr->arr[j]);
		}
		return true;
	}
	return false;
}

array *merge(array *arr1, array *arr2) // actual param should be sorted arrays
{
	if (underflow(*arr1) && underflow(*arr2))
		return NULL;
	int i, j, k;
	i = j = k = 0;
	array *arr3;
	arr3 = (array *)malloc(sizeof(array));
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
int set_membership(array arr, int key)
{
	if (underflow(arr))
		return 0;
	int i;
	for (i = 0; i < arr.length; i++)
	{
		if (key == arr.A[i])
			return 1;
	}
	return 0;
}

array *union_unsorted(array *arr1, array *arr2)
{
	if (underflow(*arr1) && underflow(*arr2))
		return NULL;
	int i, j, k;
	i = j = k = 0;
	array *arr3;
	arr3 = (array *)malloc(sizeof(array));
	for (; i < arr1->length; i++) // copying A in C
	{
		arr3->A[k++] = arr1->A[i];
	}
	arr3->length = k;
	for (; j < arr2->length; j++)
		if (!(set_membership(*arr3, arr2->A[j]))) // copying elements of B that are not in C
		{
			arr3->A[k++] = arr2->A[j];
			arr3->length = k; // updating length of C
		}
	arr3->size = arr1->length + arr2->length;
	return arr3;
}
array *intersection_unsorted(array *arr1, array *arr2)
{
	if (underflow(*arr1) && underflow(*arr2))
		return NULL;
	int i, j, k;
	i = j = k = 0;
	array *arr3;
	arr3 = (array *)malloc(sizeof(array));
	for (; i < arr1->length; i++)
	{
		if (set_membership(*arr2, arr1->A[i])) // copying elements common to A and B into C.
		{
			arr3->A[k++] = arr1->A[i];
		}
	}
	arr3->length = k;
	arr3->size = arr1->length + arr2->length;
	return arr3;
}
array *difference_unsorted(array *arr1, array *arr2)
{
	if (underflow(*arr1) && underflow(*arr2))
		return NULL;
	int i, j, k;
	i = j = k = 0;
	array *arr3;
	arr3 = (array *)malloc(sizeof(array));
	for (; i < arr1->length; i++) // copying elements of A to C that are not present in B
		if (!set_membership(*arr2, arr1->A[i]))
			arr3->A[k++] = arr1->A[i];
	arr3->length = k;
	arr3->size = arr1->length + arr2->length;
	return arr3;
}
array *arr_union(array *arr1, array *arr2) // sorted arrays are passed as actual param
{
	if (underflow(*arr1) && underflow(*arr2))
		return NULL;
	int i, j, k;
	i = j = k = 0;
	array *arr3;
	arr3 = (array *)malloc(sizeof(array));
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
array *intersection(array *arr1, array *arr2) // sorted arrays are passed as actual param
{
	if (underflow(*arr1) && underflow(*arr2))
		return NULL;
	int i, j, k;
	i = j = k = 0;
	array *arr3;
	arr3 = (array *)malloc(sizeof(array));
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
array *difference(array *arr1, array *arr2) // sorted array are passed
{
	if (underflow(*arr1) && underflow(*arr2))
		return NULL;
	int i, j, k;
	i = j = k = 0;
	array *arr3;
	arr3 = (array *)malloc(sizeof(array));
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
	array arr;
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define M 128
#define N 256

typedef struct array
{
	int *arr;
	int size;
	int capacity;
} array;

// DECLARATIONS

bool overflow (array);
bool underflow (array);
bool display (array);
bool append (array *, int);
bool insert (array *, int, int);
int delete (array *, int);

// DEFINATIONS

bool overflow (array arr)
{
	bool flag = false;

	if (arr.size == arr.capacity)
	{
		flag = true;

		printf ("\nOverflow!\n");
	}

	return flag;
}

bool underflow (array arr)
{
	bool flag = false;

	if (!arr.size)
	{
		flag = true;

		printf ("\nUnderflow!\n");
	}

	return flag;
}

bool display (array arr)
{
	bool flag = false;

	if (!underflow (arr))
	{
		flag = true;

		printf ("\nDisplaying Array Elements (Index, Value) ...\n");

		for (int i = 0; i < arr.size; i++)
			printf ("(%d, %d) ", i, arr.arr[i]);
		printf ("\n");

	}

	return flag;
}

bool append (array *arr, int val)
{
	bool flag = false;

	if (arr && !overflow (*arr))
	{
		flag = true;

		arr->arr[(arr->size)++] = val;
	}

	return flag;
}

bool insert (array *arr, int idx, int val)
{
	bool flag = false;

	if (arr && !overflow (*arr)
			&& ((idx >= 0) && (idx <= arr->size)))
	{
		flag = true;

		for (int i = (arr->size)++; i > idx; i--)
			arr->arr[i] = arr->arr[i - 1];
		arr->arr[idx] = val;
	}

	return flag;
}

int delete (array *arr, int idx)
{
	int retval = INT_MIN;

	if (arr && !underflow (*arr)
			&& ((idx >= 0) && (idx < arr->size)))
	{
		retval = arr->arr[idx];

		for(int i = idx; i < (arr->size - 1); i++)
			arr->arr[i] = arr->arr[i + 1];
		arr->size--;
	}

	return retval;
}

array *copy (array arr)
{
	array* cp_arr = NULL;

	if((cp_arr = (array *) malloc (sizeof (array)))
			&& (cp_arr->arr = (int *) malloc (sizeof (arr.capacity))))
	{
		for (int i = 0; i < arr.size; i++)
			cp_arr->arr[i] = arr.arr[i];

		cp_arr->size = arr.size;
		cp_arr->capacity = arr.capacity;
	}
	else if (cp_arr)
	{
		free (cp_arr);
		cp_arr = NULL;
	}

	return cp_arr;
}

bool swap (int *xref, int *yref)
{
	bool flag = false;

	if (xref && yref)
	{
		flag = true;
		*xref = *xref + *yref;
		*yref = *xref - *yref;
		*xref = *xref - *yref;
	}

	return flag;
}

int sequential_search (array arr, int key)
{
	int idx = INT_MIN;
	if (!underflow (arr))
	{
		for (int i = 0; i < arr.size; i++)
		{
			if (arr.arr[i] == key)
			{
				idx = i;
				break;
			}
		}
	}

	return idx;
}

// transposition sequential search
int xposition_seq_search (array *arr, int key)
{
	int idx = INT_MIN;

	if (arr && !underflow (*arr))
	{
		for (int i = 0; i < arr->size; i++)
		{

			if (arr->arr[i] == key)
			{
				((i > 0) && swap (&(arr->arr[i]), &(arr->arr[i - 1])))
					? (idx = i - 1) : (idx = i);
				break;
			}
		}
	}

	return idx;
}

int move_to_front_seq_search (array *arr, int key)
{	
	int idx = INT_MIN;

	if (arr && !underflow (*arr))
	{
		for (int i = 0; i < arr->size; i++)
		{
			if (arr->arr[i] == key)
			{
				((i > 0) && swap (&(arr->arr[i]), &(arr->arr[0])))
					? (idx = 0) : (idx = i);
				break;
			}
		}
	}

	return idx;
}

int iterative_binary_search (array arr, int low, int high, int key)
{
	int mid, idx =  INT_MIN;

	if (!underflow (arr))
	{
		while (low <= high)
		{
			mid = (low + high) / 2;

			if (key == arr.arr[mid])
			{
				idx = mid;
				break;
			}
			else if (key < arr.arr[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}

	return idx;
}

int recursive_binary_search (array arr, int low, int high, int key)
{
	int mid, idx = INT_MIN;

	if (!underflow (arr))
	{
		if (low <= high)
		{
			mid = (low + high) / 2;

			if (key == arr.arr[mid])
				idx = mid;
			else if (key < arr.arr[mid])
				idx = recursive_binary_search (arr, low, mid - 1, key);
			else
				idx = recursive_binary_search (arr, mid + 1, high, key);
		}
	}

	return idx;
}

int get_element (array arr, int idx)
{
	int ele = INT_MIN;

	if (!underflow(arr) && (idx >= 0 && idx < arr.size))
	{
		ele = arr.arr[idx];
	}

	return ele;
}

bool set_index (array *arr, int idx, int val)
{
	bool flag = false;
	if (arr && !underflow (*arr)
			&& (idx >= 0 && idx < arr->size))
	{
		flag = true;

		arr->arr[idx] = val;
	}

	return flag;
}

int iterative_sum (array arr)
{
	int sum = 0;

	if (!underflow (arr))
		for (int i = 0; i < arr.size; i++)
			sum += arr.arr[i];

	return sum;
}

int recursive_sum_core (array *arr, int n)
{
	int sum = 0;

	if (arr && (n >= 0))
		sum = recursive_sum_core (arr, n - 1) + arr->arr[n];

	return sum;
}

// n must be size - 1 tail recursive better to convert into loop
int recursive_sum (array arr) 
{
	int sum = 0;

	if (!underflow (arr))
		sum = recursive_sum_core (&arr, arr.size - 1);

	return sum;
}

float average (array arr)
{
	return (float) iterative_sum (arr) / arr.size;
}

int max (array arr)
{
	int max = INT_MIN;

	if (!underflow(arr))
	{
		for (int i = 0; i < arr.size; i++)
		{
			if (arr.arr[i] > max)
				max = arr.arr[i];
		}
	}

	return max;
}

int min (array arr)
{
	int min = INT_MAX;

	if (!underflow (arr))
	{
		for (int i = 0; i < arr.size; i++)
		{
			if (arr.arr[i] < min)
				min = arr.arr[i];
		}
	}

	return min;
}

bool auxillary_arr_reverse (array *arr) 
{
	bool flag = false;
	int i, *aux_arr = NULL;

	if (arr && !underflow (*arr)
			&& (aux_arr = (int*) malloc (sizeof (int) * arr->size)))
	{
		flag = true;

		for( i = 0; i < arr->size; i++)
			aux_arr[i] = arr->arr[i];

		for(; i > 0; i--)
			arr->arr[arr->size - i] = aux_arr[i - 1];

		free (aux_arr);
	}

	return flag;
}

bool reverse_interchange (array *arr) 
{
	bool flag = false;

	if (arr && !underflow (*arr))
	{
		flag = true;

		for (int i = 0, j = (arr->size - 1); i < j; i++, j--)
			swap (&(arr->arr[i]), &(arr->arr[j]));
	}

	return flag;
}

bool left_shift (array *arr)
{
	bool flag = false;

	if (arr && !underflow (*arr))
	{
		flag = true;

		for (int i = 0; i < (arr->size - 1); i++)
			arr->arr[i] = arr->arr[i + 1];
		arr->arr[arr->size - 1] = 0;
	}

	return flag;
}

bool right_shift (array *arr)
{
	bool flag = false;

	if (arr && !underflow (*arr))
	{
		flag = true;

		for (int i = arr->size - 1; i > 0; i--)
			arr->arr[i] = arr->arr[i - 1];
		arr->arr[0] = 0;
	}

	return flag;
}

bool rotate_left (array *arr)
{
	bool flag = false;
	int tmp;

	if (arr && !underflow (*arr))
	{
		flag = true;

		tmp = arr->arr[0];

		for (int i = 0; i < arr->size - 1; i++)
			arr->arr[i] = arr->arr[i + 1];

		arr->arr[arr->size - 1] = tmp;
	}

	return flag;
}

bool rotate_right (array *arr)
{
	bool flag = false;
	int tmp;

	if (arr && !underflow (*arr))
	{
		flag = true;

		tmp = arr->arr[arr->size - 1];

		for (int i = arr->size - 1; i > 0; i--)
			arr->arr[i] = arr->arr[i - 1];

		arr->arr[0] = tmp;
	}

	return flag;
}

bool insert_into_sorted_arr (array *arr, int val)
{
	int i;
	bool flag = false;

	if (arr && !overflow (*arr))
	{
		flag = true;

		for (i = ((arr->size)++ - 1); (i > 0)
				&& (val < arr->arr[i]); i--)
			arr->arr[i] = arr->arr[i-1];
		arr->arr[i] = val;
	}

	return flag;
}

bool is_sorted (array arr)
{
	bool flag = true;

	if (!underflow (arr))
	{
		for (int i = 1; i < arr.size; i++)
		{
			if (arr.arr[i] < arr.arr[i - 1])
			{
				flag = false;
				break;
			}
		}
	}

	return flag;
}

// -ve on left and +ve on right
bool rearrange (array *arr) 
{
	bool flag = false;
	int i, j;

	if (arr && !underflow(*arr))
	{
		flag = true;
		i = 0, j = arr->size - 1;

		while (i < j)
		{
			// incr i until +ve ele found
			while (arr->arr[i] < 0)
				i++;
			// decr j until -ve ele found
			while (arr->arr[j] >= 0)
				j--;

			if (i < j)
				swap (&arr->arr[i], &arr->arr[j]);
		}
	}

	return flag;
}

// arrays should be sorted
array *merge (array *arrx, array *arry)
{
	int i, j, k;
	array *arrz = NULL;

	if (arrx && arry && !underflow (*arrx) && !underflow (*arry)
			&& (arrz = (array *) malloc (sizeof (array))))
	{
		i = j = k = 0;

		arrz->size = arrz->capacity = arrx->size + arry->size;

		if ((arrz->arr = (int *) malloc (sizeof (int) * arrz->capacity)))
		{
			while (i < arrx->size && j < arry->size)
			{
				if (arrx->arr[i] <= arry->arr[j])
				{
					if (arrx->arr[i] == arry->arr[j])
						arrz->arr[k++] = arry->arr[j++];

					arrz->arr[k++] = arrx->arr[i++];
				}
				else
					arrz->arr[k++] = arry->arr[j++];
			}

			while (i < arrx->size)
				arrz->arr[k++] = arrx->arr[i++];

			while (j < arry->size)
				arrz->arr[k++] = arry->arr[j++];
		}
		else
		{
			free (arrz);
			arrz = NULL;
		}

	}

	return arrz;
}

bool set_membership (array arr, int key)
{
	bool flag = false;

	if (!underflow (arr))
		for (int i = 0; (i < arr.size) && !flag; i++)
			if (key == arr.arr[i])
				flag = true;

	return flag;
}

array *union_unsorted (array *arrx, array *arry)
{
	int i, j, k;
	array *arrz = NULL;

	if (arrx && arry && !underflow(*arrx) && !underflow(*arry)
			&& (arrz = (array *) malloc (sizeof (array))))
	{
		i = j = k = 0;

		arrz->size = 0;
		arrz->capacity = arrx->size + arry->size;

		if ((arrz->arr = (int *) malloc (sizeof (int) * arrz->capacity)))
		{
			while (i < arrx->size)
				arrz->arr[k++] = arrx->arr[i++];

			while (j < arry->size)
				if (!(set_membership (*arrz, arry->arr[j])))
					arrz->arr[k++] = arry->arr[j++];

			arrz->size = k;
		}
		else
		{
			free (arrz);
			arrz = NULL;
		}

	}

	return arrz;
}

array *intersection_unsorted (array *arrx, array *arry)
{
	int i, j;
	array *arrz = NULL;

	if (arrx && arry && !underflow (*arrx) && !underflow (*arry)
			&& (arrz = (array *) malloc (sizeof (array))))
	{
		i = j = 0;

		arrz->size = 0;
		arrz->capacity = arrx->size < arry->size ? arrx->size : arry->size;

		if ((arrz->arr = (int *) malloc (sizeof (int) * arrz->capacity)))
		{
			while (i < arrx->size)
				if (set_membership (*arry, arrx->arr[i]))
					arrz->arr[j++] = arrx->arr[i++];

			arrz->size = j;
		}
		else
		{
			free (arrz);
			arrz = NULL;
		}
	}

	return arrz;
}

array *difference_unsorted (array *arrx, array *arry)
{
	int i, j;
	array *arrz = NULL;

	if (arrx && arry && !underflow (*arrx) && !underflow (*arry)
			&& (arrz = (array *) malloc (sizeof (array))))
	{
		arrz->size = 0;
		arrz->capacity = arrx->capacity;

		if ((arrz->arr = (int *) malloc (sizeof (int) * arrz->capacity)))
		{
			while (i < arrx->size)
				if (!set_membership (*arry, arrx->arr[i]))
					arrz->arr[j++] = arrx->arr[i++];

			arrz->size = j;
		}
		else
		{
			free (arrz);
			arrz = NULL;
		}
	}

	return arrz;
}

// sorted arrays are passed as actual param
array *array_union (array *arrx, array *arry)
{
	int i, j, k;
	array *arrz = NULL;

	if (arrx && arry && !underflow (*arrx) && !underflow (*arry)
			&& (arrz = (array *) malloc (sizeof (array))))
	{
		i = j = k = 0;
		arrz->size = 0;
		arrz->capacity = arrx->size + arry->size;

		if ((arrz->arr = (int *) malloc (sizeof (int) * arrz->capacity)))
		{
			while ((i < arrx->size) && (j < arry->size))
			{
				if (arrx->arr[i] < arry->arr[j])
					arrz->arr[k++] = arrx->arr[i++];
				else if (arry->arr[j] < arrx->arr[i])
					arrz->arr[k++] = arry->arr[j++];
				else
				{
					// if both element are equal only one is copied and ptrs are incremented
					j++;
					arrz->arr[k++] = arrx->arr[i++];
				}
			}

			// remaining elements of either of A or B are copied into C
			while (i < arrx->size)
				arrz->arr[k++] = arrx->arr[i++];

			while (j < arry->size)
				arrz->arr[k++] = arry->arr[j++];

			arrz->size = k;
		}
		else
		{
			free (arrz);
			arrz = NULL;
		}
	}

	return arrz;
}

// sorted arrays are passed as actual param
array *intersection (array *arrx, array *arry)
{
	int i, j, k;
	array *arrz = NULL;

	if (arrx && arry && !underflow (*arrx) && !underflow (*arry)
			&& (arrz = (array *) malloc (sizeof (array))))
	{
		if ((arrz->arr = (int *) malloc (sizeof (int) * arrz->size)))
		{
			while ((i < arrx->size) && (j < arry->size))
			{
				if (arrx->arr[i] < arry->arr[j])
					i++;
				else if (arry->arr[j] < arrx->arr[i])
					j++;
				else
				{
					// elements that are present in both A and B are copied to C
					j++;
					arrz->arr[k++] = arrx->arr[i++];
				}

				arrz->size = k;
			}
		}
		else
		{
			free (arrz);
			arrz = NULL;
		}

	}

	return arrz;
}

// sorted arrays are passed
array *difference (array *arrx, array *arry)
{
	int i, j, k;
	array *arrz = NULL;

	if (arrx && arry && !underflow (*arrx) && !underflow (*arry)
			&& (arrz = (array *) malloc (sizeof (array))))
	{
		i = j = k = 0;
		arrz->size = 0;
		arrz->capacity = arrx->size;

		if ((arrz->arr = (int *) malloc (sizeof (int) * arrz->capacity)))
		{
			while ((i < arrx->size) && (j < arry->size))
			{
				// only elements that belong to A are copied to C
				if (arrx->arr[i] < arry->arr[j])
				{
					arrz->arr[k++] = arrx->arr[i++];
				}
				else if (arry->arr[j] == arrx->arr[i])
				{
					i++;
					j++;
				}
				else
				{
					j++;
				}
			}

			// remaining elements in A are copied into C
			while (i < arrx->size)
				arrz->arr[k++] = arrx->arr[i++];

			arrz->size = k;
		}
		else
		{
			free (arrz);
			arrz = NULL;
		}
	}

	return arrz;
}

int main (int argc, char const *argv[])
{
	array arrx, arry;

	if ((arrx.arr = (int *) malloc (sizeof (int) * M))
			&& (arry.arr = (int *) malloc (sizeof (int) * N)))
	{
		free (arrx.arr);
		free (arry.arr);
	}

	return 0;
}

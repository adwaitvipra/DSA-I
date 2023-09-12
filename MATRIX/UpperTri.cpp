#include <iostream>
#include <cstdlib>
#include <climits>

#define ROW_MAJ(N, I, J) (((N) * ((I) - 1)) - ((((I) - 1) * ((I) - 2)) / 2) + ((J) - (I)))
#define COL_MAJ(I, J) ((((J) * ((J) - 1)) / 2) + ((I) - 1))

using namespace std;
class UpperTri
{
	private:
		int *arr = nullptr;
		int n;

	public:
		UpperTri ()
		{
			n = 2;
			arr = new int [(2 * (2 + 1)) / 2];
		}

		UpperTri (int n)
		{
			this->n = n;
			arr = new int [(n * (n + 1)) / 2];
		}

		~UpperTri ()
		{
			delete [] arr;
		}

		void Display ();

		void Set (int, int, int);
		int Get (int, int);

		int GetDimension () { return n; }
};

void UpperTri :: Display ()
{
	if (arr && (n > 0))
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i > j)
					printf ("0 ");
				else
				{
					/*
					   printf ("%d ", arr[COL_MAJ (i, j)]);
					   */

					printf ("%d ", arr[ROW_MAJ (n, i, j)]);
				}
			}
			printf ("\n");
		}
	}

	return ;
}

void UpperTri :: Set (int i, int j, int val)
{
	if (arr && (i <= n) && (j <= n))
	{
		/*
		   arr[COL_MAJ (i, j)] = val;
		   */

		arr[ROW_MAJ (n, i, j)] = val;
	}

	return ;
}

int UpperTri :: Get (int i, int j)
{
	int ret = INT_MIN;

	if (arr && (n > 0) && (i <= n) && (j <= n))
	{
		if (i > j)
			ret = 0;
		else
		{
			/*
			   ret = arr[COL_MAJ (i, j)];
			   */

			ret = arr[ROW_MAJ (n, i, j)];
		}
	}

	return ret;
}

int main (const int argc, const char *argv[])
{
	int x, d;

	cout << "Enter Dimension: ";
	cin >> d;

	UpperTri mat (d);

	cout << "Enter all the elements:" << endl;

	for (int i = 1; i <= mat.GetDimension(); i++)
	{
		for (int j = 1; j <= mat.GetDimension(); j++)
		{
			cin >> x;
			mat.Set (i, j, x);
		}
	}

	mat.Display ();

	return 0;
}

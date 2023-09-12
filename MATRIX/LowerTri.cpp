#include <iostream>
#include <cstdlib>
#include <climits>

#define ROW_MAJ(I, J) ((((I) * ((I) - 1)) / 2) + ((J) - 1))
#define COL_MAJ(N, I, J) (((N) * ((J) - 1)) - ((((J) - 1) * ((J) - 2)) / 2) + ((I) - (J)))

using namespace std;
class LowerTri
{
	private:
		int *arr = nullptr;
		int n;

	public:
		LowerTri ()
		{
			n = 2;
			arr = new int [(2 * (2 + 1)) / 2];
		}

		LowerTri (int n)
		{
			this->n = n;
			arr = new int [(n * (n + 1)) / 2];
		}

		~LowerTri ()
		{
			delete [] arr;
		}

		void Display ();

		void Set (int, int, int);
		int Get (int, int);

		int GetDimension () { return n; }
};

void LowerTri :: Display ()
{
	if (arr && (n > 0))
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i < j)
					printf ("0 ");
				else
				{
					/*
					   printf ("%d ", arr[ROW_MAJ (i, j)]);
					   */

					printf ("%d ", arr[COL_MAJ (n, i, j)]);
				}
			}
			printf ("\n");
		}
	}

	return ;
}

void LowerTri :: Set (int i, int j, int val)
{
	if (arr && (i <= n) && (j <= n))
	{
		/*
		   arr[ROW_MAJ (i, j)] = val;
		   */

		arr[COL_MAJ (n, i, j)] = val;
	}

	return ;
}

int LowerTri :: Get (int i, int j)
{
	int ret = INT_MIN;

	if (arr && (n > 0) && (i <= n) && (j <= n))
	{
		if (i < j)
			ret = 0;
		else
		{
			/*
			   ret = arr[ROW_MAJ (i, j)];
			   */

			ret = arr[COL_MAJ (n, i, j)];
		}
	}

	return ret;
}

int main (const int argc, const char *argv[])
{
	int x, d;

	cout << "Enter Dimension: ";
	cin >> d;

	LowerTri mat (d);

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

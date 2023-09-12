#include <iostream>
#include <cstdlib>
#include <climits>

#define SIZE 128

using namespace std;

class Diagonal
{
	private:
		int *diag = nullptr;
		int size;

	public:
		Diagonal ()
		{
			size = SIZE;
			diag = new int [size];
		}

		Diagonal (int size)
		{
			this->size = size;
			diag = new int [size];
		}

		~Diagonal ()
		{
			delete [] diag;
		}

		void Display ();

		int Get (int, int);
		void Set (int, int, int);
};

void Diagonal :: Display ()
{
	int row, col;

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (row == col)
				cout << diag[row] << " ";
			else
			{
				cout << "0 ";
			}
		}
		cout << endl;
	}

	return ;
}

void Diagonal :: Set (int row, int col, int val)
{
	if ((row <= size) && (col <= size))
	{
		if (row == col)
			diag[row - 1] = val;
	}

	return ;
}

int Diagonal :: Get (int row, int col)
{
	int ret = INT_MIN;

	if ((row <= size) && (col <= size))
	{
		if (row != col)
			ret = 0;
		else
		{
			ret = diag[row - 1];
		}
	}

	return ret;
}

int main (const int argc, const char *argv[])
{
	Diagonal m (3);

	m.Set (1, 1, 1);
	m.Set (2, 2, 2);
	m.Set (3, 3, 3);

	cout << m.Get (2, 2) << endl;

	m.Display ();

	return 0;
}

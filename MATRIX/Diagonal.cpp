#include <iostream>
#include <stdlib.h>
#define SIZE 10

using namespace std;

class Diagonal
{
private:
    int *diag, size;

public:
    Diagonal ()
    {
        size = SIZE;
        diag = new int [size];
    }

    Diagonal (int size)
    {
        this->size = size;
        diag = new int[size];
    }

    ~Diagonal ()
    {
        delete[] diag;
    }

    void Display ();
    int Get (int, int);
    void Set (int, int, int);
};

void Diagonal::Display ()
{
    int row, col;
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (row == col)
            {
                cout << diag [row] << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return ;
}

void Diagonal::Set (int row, int col, int val)
{
    if (row == col)
        diag [row - 1] = val;
}

int Diagonal::Get (int row, int col)
{
    if (row == col)
        return diag [row - 1];
    return 0;
}

int main (int argc, char const *argv[])
{
    Diagonal m(3);
    m.Set(1, 1, 10);
    m.Set(2, 2, 1);
    m.Set(3, 3, 2);
    cout << m.Get(2, 2) << endl;
    m.Display();
    return 0;
}

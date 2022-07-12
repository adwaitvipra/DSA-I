#include <iostream>
#include <stdlib.h>
using namespace std;
class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal()
    {
        n = 2;
        A = new int[n];
    }
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Diagonal()
    {
        delete[] A;
    }

    void Display();
    void Set(int, int, int);
    int Get(int, int);
};
void Diagonal::Display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}
int Diagonal::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}
int main(int argc, char const *argv[])
{
    Diagonal m(3);
    m.Set(1, 1, 10);
    m.Set(2, 2, 1);
    m.Set(3, 3, 2);
    cout << m.Get(2, 2) << endl;
    m.Display();
    return 0;
}

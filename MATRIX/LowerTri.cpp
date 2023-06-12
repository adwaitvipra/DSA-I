#include <iostream>
#include <stdlib.h>
using namespace std;
class LowerTri
{
private:
    int *A;
    int n;

public:
    LowerTri()
    {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    LowerTri(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~LowerTri()
    {
        delete[] A;
    }

    void Display();
    void Set(int, int, int);
    int Get(int, int);
    int GetDimension() { return n; }
};
void LowerTri::Display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                // cout << A[i * (i - 1) / 2 + j - 1] << " ";
                cout << A[n * (j - 1) - (j - 1) * (j - 2) / 2 + (i - j)] << " "; // col major
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
void LowerTri::Set(int i, int j, int x)
{
    if (i >= j)
        // A[i * (i - 1) / 2 + j - 1] = x;
        A[n * (j - 1) - (j - 1) * (j - 2) / 2 + (i - j)] = x; // col major
}
int LowerTri::Get(int i, int j)
{
    if (i >= j)
        // return A[i * (i - 1) / 2 + j - 1];
        return A[n * (j - 1) - (j - 1) * (j - 2) / 2 + (i - j)]; // col major
    else
        return 0;
}
int main(int argc, char const *argv[])
{
    int i, j, x, d;
    cout << "Enter Dimensions:";
    cin >> d;
    LowerTri m(d);
    printf("Enter all the elements:\n");
    for (i = 1; i <= m.GetDimension(); i++)
    {
        for (j = 1; j <= m.GetDimension(); j++)
        {
            cin >> x;
            m.Set(i, j, x);
        }
    }

    m.Display();
    return 0;
}

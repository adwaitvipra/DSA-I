#include <iostream>
#include <stdlib.h>
using namespace std;

class UpperTri
{
private:
    int n;
    int *A;

public:
    UpperTri()
    {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    UpperTri(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~UpperTri()
    {
        delete A;
    }

    int GetDimension() { return n; }
    void Diplay();
    void Set(int, int, int);
    int Get(int, int);
};
void UpperTri::Diplay()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                //cout << A[n * (i - 1) - (i - 1) * (i - 2) / 2 + (j - i)] << " "; // Row Major
                cout << A[j * (j - 1) / 2 + (i - 1)] << " ";
            }
            else
            cout<<"0 ";
        }
        cout<<endl;
    }
}
void UpperTri::Set(int i, int j, int x)
{
    if (i <= j)
    {
        //A[n * (i - 1) - (i - 1) * (i - 2) / 2 + (j - i)] = x; // row major
        A[j*(j-1)/2+(i-1)]=x;
    }
}
int UpperTri::Get(int i, int j)
{
    if (i <= j)
    {
        //return A[n * (i - 1) - (i - 1) * (i - 2) / 2 + (j - i)];
        return A[j*(j-1)/2 + (i-1)];
    }
    else
        return 0;
}
int main(int argc, char const *argv[])
{
    int i, j, x, d;
    cout << "Enter Dimension of UpperTri Matrix:\n";
    cin >> d;
    UpperTri m(d);
    cout << "Enter all the Elements:\n";
    for (i = 1; i <= m.GetDimension(); i++)
    {
        for (j = 1; j <= m.GetDimension(); j++)
        {
            cin >> x;
            m.Set(i, j, x);
        }
    }
    m.Diplay();
    return 0;
}

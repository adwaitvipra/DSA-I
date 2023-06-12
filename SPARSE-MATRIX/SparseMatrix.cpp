#include <iostream>
using namespace std;
class Element
{
public:
    int i;
    int j;
    int x;
};
class Sparse
{
private:
    int m;
    int n;
    int num; // no. of non zero ele
    Element *ele;

public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }
    Sparse operator+(Sparse &s); // Addition operator
    friend istream &operator>>(istream &is, Sparse &s);
    friend ostream &operator<<(ostream &os, Sparse &s);
};
ostream &operator<<(ostream &os, Sparse &s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
                cout << s.ele[k++].x << " ";
            else
                printf("0 ");
        }
        cout << endl;
    }
    return os;
}
istream &operator>>(istream &is, Sparse &s)
{
    cout << "Enter All The Elements:\n";
    for (int i = 0; i < s.num; i++)
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    return is;
}
Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    if (m != s.m || n != s.n)
    {
        return Sparse(0, 0, 0);
    }
    Sparse *sum = new Sparse(m, n, num + s.num);
    i = j = k = 0;

    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i)
            sum->ele[k++] = ele[i++];
        else if (ele[i].i > s.ele[j].i)
            sum->ele[k++] = s.ele[j++];
        else
        {
            if (ele[i].j < s.ele[j].j)
                sum->ele[k++] = ele[i++];
            else if (ele[i].j > s.ele[j].j)
                sum->ele[k++] = s.ele[j++];
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }
    for (; i < num; i++)
        sum->ele[k++] = ele[i];
    for (; j < s.num; j++)
        sum->ele[k++] = s.ele[j];
    sum->num = k;
    return *sum;
}

int main(int argc, char const *argv[])
{
    Sparse s1(4, 4, 4);
    Sparse s2(4, 4, 4);
    cin >> s1;
    cin >> s2;
    Sparse sum = s1 + s2;
    cout << "Matrix 1:\n"
         << s1 << endl;
    cout << "Matrix 2:\n"
         << s2 << endl;
    cout << "Matrix Sum:\n"
         << sum << endl;
    return 0;
}

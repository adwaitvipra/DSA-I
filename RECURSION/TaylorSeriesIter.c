#include <stdio.h>

double e(int x, int n)
{
    int i;
    double s, Nr, Dr;
    s = Nr = Dr = 1;

    for (i = 1; i <= n; i++)
    {
        Nr *= x;
        Dr *= i;
        s += Nr / Dr;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    printf("%lf \n", e(1, 20));
    return 0;
}

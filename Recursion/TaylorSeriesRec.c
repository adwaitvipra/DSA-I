#include <stdio.h>

double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    r = e(x, n - 1);
    p *= x;
    f *= n;
    return r + p / f;
}
int main(int argc, char const *argv[])
{
    printf("%.10lf\n", e(3, 20));
    return 0;
}

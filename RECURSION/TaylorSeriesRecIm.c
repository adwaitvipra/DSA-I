#include <stdio.h>
// Taylor Series Using Horner's Rule
double e(int x, int n)
{
    static double s = 0;
    if (n == 0)
        return s;
    s = 1 + s * x / n;
    return e(x, n - 1);
}
int main(int argc, char const *argv[])
{
    printf("%lf \n", e(1, 0));
    return 0;
}

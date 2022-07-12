#include <stdio.h>

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}
int FnCr(int n, int r)
{
    int Nr, Dr;
    Nr = fact(n);
    Dr = fact(r) * fact(n - r);
    return Nr / Dr;
}
int RnCr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return RnCr(n - 1, r - 1) + RnCr(n - 1, r);
}
int main(int argc, char const *argv[])
{
    int r1, r2;
    printf("%d is found using Formula and Recursive Factorial\n", FnCr(4, 2));
    printf("%d is found using Recursion\n", RnCr(4, 2));
    return 0;
}

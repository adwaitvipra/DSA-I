#include <stdio.h>

int Rsum(int n)
{
    if (n == 0)
        return 0;
    return Rsum(n - 1) + n;
}

int Isum(int n)
{
    int i, s = 0;
    for (i = 1; i <= n; i++)
        s = s + i;
    return s;
}
int Fsum(int n)
{
    return n * (n + 1) / 2;
}
int main(int argc, char const *argv[])
{
    int r1, r2, r3, n = 10;
    r1 = Rsum(n);
    r2 = Isum(n);
    r3 = Fsum(n);
    printf("%d is Recursive Sum\n%d is Iterative Sum\n%d is Formula Sum\n", r1, r2, r3);
    return 0;
}

#include <stdio.h>

int Rfact(int n)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 1;
    return Rfact(n - 1) * n;
}

int Ifact(int n)
{
    if (n < 0)
        return -1;

    int i, f = 1;
    for (i = 1; i <= n; i++)
        f *= i;
    return f;
}
int main(int argc, char const *argv[])
{
    int r1, r2;
    r1 = Rfact(-10);
    r2 = Ifact(-10);
    printf("%d is Recursive Factorial\n%d is Iterative Factorial\n", r1, r2);
    return 0;
}
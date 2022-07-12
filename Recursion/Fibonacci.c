#include <stdio.h>
int F[10]; // Init all elements with -1

int Ifib(int n)
{
    int t0, t1, s, i;
    s = t0 = 0;
    t1 = 1;
    if (n <= 1)
        return n;
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int Rfib(int n)
{
    if (n <= 1)
        return n;
    return Rfib(n - 2) + Rfib(n - 1);
}
int RfibIm(int n) // Memoization to avoid Excessive Calls
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = RfibIm(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = RfibIm(n - 1);

        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
        F[i] = -1;

    int r1, r2, r3;
    r1 = Ifib(10);
    r2 = Rfib(10);
    r3 = RfibIm(10);
    printf("%d is found using Iteration\n", r1);
    printf("%d is found using Recursion\n", r2);
    printf("%d is found using Improved Recursion, avoiding Excessive Recursion\n", r3);
    return 0;
}

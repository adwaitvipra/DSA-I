#include <stdio.h>

int fun(int n) // sum of first n natural numbers using recursion
{
    if (n > 0)
        return fun(n - 1) + n; // multiple copies of n are created function stack frames.
    return 0;
}
int static_var(int n)
{
    static int s = 0; // single memory is allocated in BSS at first function call and it is incremented.
    if (n > 0)
    {
        s++;
        return static_var(n - 1) + s;
    }
    return 0;
}
int g = 0; // single memory is allocated in BSS at runtime and it is incremented.
int global_var(int n)
{
    if (n > 0)
    {
        g++;
        return global_var(n - 1) + g;
    }
    return 0;
}
int main()
{
    int sum, svar, gvar;
    int x = 5;
    sum = svar = gvar = 0;

    sum = fun(x);
    printf("%d\n", sum);
    svar = static_var(x);
    printf("%d\n", svar);
    gvar = global_var(x);
    printf("%d\n", gvar);

    return 0;
}

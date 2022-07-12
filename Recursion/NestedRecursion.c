#include <stdio.h>
int fun(int);
int fun(int n)
{
    if (n > 100)
        return n - 10;
    return fun(fun(n + 11));
}
int main(int argc, char const *argv[])
{
    int x;
    x = fun(30);
    printf("%d\n", x);
    return 0;
}

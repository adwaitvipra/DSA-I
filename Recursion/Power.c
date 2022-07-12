#include <stdio.h>

int power(int m, int n)
{
    if (n == 0)
        return 1;
    return power(m, n - 1) * m;
}
int powerIm(int m, int n) // Improved and Faster
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return powerIm(m * m, n / 2);
    return m * powerIm(m * m, (n - 1) / 2);
}

int Ipower(int m, int n)
{
    int p = 1, i;
    for (i = 0; i < n; i++)
        p *= m;
    return p;
}
// int IpowerIm(int m, int n) //Improved Iteration
// {
//     int p=1,i;
// }
int main(int argc, char const *argv[])
{
    int r1, r2, r3, r4;
    r1 = power(2, 11);
    r2 = powerIm(2, 11);
    r3 = Ipower(2, 11);
    // r4 = IpowerIm(2, 11);
    printf("%d is power by Recursion\n", r1);
    printf("%d is power by Improved Recursion\n", r2);
    printf("%d is power by Iteration\n", r3);
    // printf("%d is power by Improved Iteration\n", r4);

    return 0;
}

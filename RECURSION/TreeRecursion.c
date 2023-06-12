#include <stdio.h>

void fun(int n) // Tree Recursive Function as  function has more than one recursive calls
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1); // first recursive call
        fun(n - 1); // second recursive call
    }
}

int main(int argc, char const *argv[])
{
    int x = 3;
    fun(x);
    printf("\n");
    return 0;
}

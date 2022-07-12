#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int A[10];
    int n;
};
void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void Set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}
int Get(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}
int main(int argc, char const *argv[])
{
    struct Matrix m={{0},3};
    Set(&m,1,1,9);
    Set(&m,2,2,1);
    Set(&m,3,3,2);
    printf("%d \n",Get(m,1,1));
    printf("%d \n",Get(m,1,2));
    Display(m);
    return 0;
}

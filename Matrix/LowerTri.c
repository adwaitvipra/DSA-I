#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};
void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
                // printf("%d ", m.A[i*(i-1)/2+j-1]); // Row major
                printf("%d ", m.A[m.n * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j)]); // Col major
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void Set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
        // m->A[i * (i - 1) / 2 + j - 1] = x;// Row major
        m->A[m->n * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j)] = x; // col major
}
int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
        // return m.A[i * (i - 1) / 2 + j - 1]; // row major
        return m.A[m.n * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j)];
    else
        return 0;
}
int main(int argc, char const *argv[])
{
    struct Matrix m;
    int i, j, x;
    printf("Enter Dimension:");
    scanf(" %d", &m.n);
    m.A = (int *)malloc(sizeof(int) * m.n * (m.n + 1) / 2);

    printf("Enter all Elements:\n");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf(" %d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("%d \n", Get(m, 1, 1));
    printf("%d \n", Get(m, 1, 2));
    Display(m);
    return 0;
}

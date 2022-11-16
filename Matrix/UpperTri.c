#include <stdio.h>
#include <stdlib.h>
struct UpperTri
{
    int n;
    int *A;
};
void Display(struct UpperTri m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i <= j)
                //printf("%d ", m.A[m.n * (i - 1) - (i - 1) * (i - 2) / 2 + (j - i)]); // row major
                                                                                     printf("%d ", m.A[j*(j-1)/2 + (i-1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void Set(struct UpperTri *m, int i, int j, int x)
{
    if (i <= j)
    {
       // m->A[m->n * (i - 1) - (i - 1) * (i - 2) / 2 + (j - i)] = x; // row major
         m->A[j*(j-1)/2 + i-1]=x;
    }
}
int Get(struct UpperTri m, int i, int j)
{
    if (i <= j)
    {
        //return m.A[m.n * (i - 1) - (i - 1) * (i - 2) / 2 + (j - i)]; // row major
        return m.A[j*(j-1)/2-(i-1)];
    }
}
int main(int argc, char const *argv[])
{
    struct UpperTri m;
    int i, j, x;
    printf("Enter Dimension of Upper Triangular Matrix:\n");
    scanf(" %d", &m.n);
    m.A = (int *)malloc(sizeof(int) * m.n * (m.n + 1) / 2);
    printf("Enter all the elements:");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf(" %d", &x);
            Set(&m, i, j, x);
        }
    }
    Display(m);
    return 0;
}

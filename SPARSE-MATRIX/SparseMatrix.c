#include <stdio.h>
#include <stdlib.h>
struct Element
{
    int i;
    int j;
    int x;
};
struct Sparse
{
    int m;
    int n;
    int num;             // no. of nonzero elem
    struct Element *ele; // ptr to element structure
};
void Create(struct Sparse *s)
{
    int i;
    printf("Enter Dimensions:\n");
    scanf(" %d %d", &s->m, &s->n);
    printf("Enter number of nonzero elements:\n");
    scanf(" %d", &s->num);
    s->ele = (struct Element *)malloc(sizeof(struct Element) * s->num); // dynamically allocate arr of Element struct
    printf("Enter all the nonzero elements and with their row , col and value:\n");
    for (i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}
void Display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
struct Sparse *Add(struct Sparse *s1, struct Sparse *s2)
{
    int i, j, k;
    struct Sparse *sum;
    i = j = k = 0;
    if (s1->m != s2->m || s1->n != s2->n)
        return NULL;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));
    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i) // row of s1 is smaller
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i) // row of s2 is smaller
            sum->ele[k++] = s2->ele[j++];
        else
        {                                    // rows of both are same
            if (s1->ele[i].j < s2->ele[j].j) // col of s1 is smaller
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j) // col of s2 is smaller
                sum->ele[k++] = s2->ele[j++];
            else
            {
                sum->ele[k] = s1->ele[i];                          // copying s1->ele[i] in sum->ele[k] and incrementing i
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x; // adding x of s2 ele at j with x of sum ele k, incrementing both
            }
        }
    }
    for (; i < s1->num; i++) // for remaining ele of s1
        sum->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++) // for remaining ele of s2
        sum->ele[k++] = s2->ele[j];
    sum->m = s1->m; // setting sum's m and n as s1 or s2 m and n
    sum->n = s1->n;
    sum->num = k; // sum's num as k which is lastly incremented and gives actual number
    return sum;
}
int main(int argc, char const *argv[])
{
    struct Sparse s1, s2, *s3;

    Create(&s1);
    Display(s1);
    Create(&s2);
    Display(s2);
    s3 = Add(&s1, &s2);
    Display(*s3);
    return 0;
}

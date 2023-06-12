#include <stdio.h>
#include <stdlib.h>
#include<math.h> // compile by : gcc -o Poly Polynomial.c -lm

// Need to improve this for unsorted exponents and their addition
struct Term
{
    int coeff;
    int exp;
};
struct Poly
{
    int n;
    struct Term *terms;
};
void create(struct Poly *p)
{
    int i;
    printf("Enter no. of Terms:\n");
    scanf(" %d", &p->n);
    p->terms = (struct Term *)malloc(sizeof(struct Term) * p->n);
    printf("Enter Terms of Polynomial:\n");
    for (i = 0; i < p->n; i++)
        scanf(" %d %d", &p->terms[i].coeff, &p->terms[i].exp);
}
void display(struct Poly p)
{
    int i;
    for (i = 0; i < p.n; i++)
    {
        if (i == p.n - 1)
            printf(" %dX^(%d)", p.terms[i].coeff, p.terms[i].exp);
        else
            printf(" %dX^(%d) + ", p.terms[i].coeff, p.terms[i].exp);
    }
    printf("\n");
}
float evaluate(struct Poly p,float x)
{
    int i;
    float sum=0;
    for(i=0;i<p.n;i++)
    {
        sum+=(p.terms[i].coeff)*pow(x,p.terms[i].exp);
    }
    return sum;
}
struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    struct Poly *sum;
    sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term)); // maximum p1's n plus p2's n terms can be present in sum poly
    i = j = k = 0;
    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if (p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++];
        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    // There may be some remaining elements in either of polys
    for (; i < p1->n; i++)
        sum->terms[k++] = p1->terms[i];
    for (; j < p2->n; j++)
        sum->terms[k++] = p2->terms[j];

    sum->n = k;
    return sum;
}
int main(int argc, char const *argv[])
{
    struct Poly p1;
    create(&p1);
    display(p1);
    printf("%f\n",evaluate(p1,10));
    return 0;
}

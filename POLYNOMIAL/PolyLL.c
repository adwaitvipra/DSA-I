#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;
void Display(struct Node *p)
{
    while (p->next)
    {
        printf("%dX^(%d)+", p->coeff, p->exp);
        p = p->next;
    }
    printf("%dX^(%d)\n", p->coeff, p->exp);
}
long Eval(struct Node *p, int x)
{
    long val=0.0;
    while (p)
    {
        val += (p->coeff) * pow(x, p->exp);
        p = p->next;
    }
    return val;
}
void Create(struct Node *p)
{
    int num,i;
    struct Node *t=NULL,*last=NULL;
    printf("Enter No. of Terms:\n");
    scanf(" %d", &num);
    printf("Enter Coeff and Exp of all the terms:\n");
    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf(" %d %d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}
int main(int argc, char const *argv[])
{
    Create(poly);
    Display(poly);
    printf("\n %ld is value\n",Eval(poly, 2));
    return 0;
}

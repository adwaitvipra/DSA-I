#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
void Create(struct Node *st)
{
    int i, num;
    struct Node *t = NULL;
    printf("Enter Size of Stack\n");
    scanf(" %d", &num);
    printf("Enter Elements:\n");
    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf(" %d", &t->data);
        t->next = top;
        top = t;
    }
}
void Display(struct Node *st)
{
    struct Node *p = st;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int IsEmpty(struct Node *st)
{
    return st ? 0 : 1;
}
int IsFull()
{
    int r;
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    r = !t ? 1 : 0; // if t is NULL return 1 that is heap is full else return 0
    free(t);
    return r;
}
char StackTop(struct Node *st)
{
    if (st)
        return st->data;
    return -1;
}
void push(struct Node *st, int x)
{
    if (IsFull())
    {
        printf("Stack Overflow!");
        return;
    }
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = st;
    top = t;
}
int pop(struct Node *st)
{
    int x = -1;
    if (IsEmpty(st))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        top = top->next;
        x = st->data;
    }
    return x;
}
int peek(struct Node *st, int index)
{
    int i;
    if (IsEmpty(st)) // return -1 when stack is empty
        return -1;
    for (i = 0; i < index - 1 && st; i++) // move st until it reaches on index or st is is not null
        st = st->next;
    return st->data;
}
int IsBalanced(char *exp) // for paranthesis only
{                         // convert stack data into char
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(top, exp[i]);
        else if (exp[i] == ')')
        {
            if (!top)
                return 0;
            pop(top);
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}
int AreBracketsBalanced(char *exp) // extended for {},[] and ().
{                                  // convert stack data into char
    int i;
    char x;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(top, exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (IsEmpty(top))
                return 0;
            x = pop(top);
            if ((exp[i] - x) != 1 && (exp[i] - x) != 2 && (exp[i] - x) != 2)
                return 0;
        }
    }
    return IsEmpty(top) ? 1 : 0;
}
int Precedance(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}
int IsOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else

        return 1;
}
char *InfixToPostfix(char *infix)
{ // convert stack data into char
    int i, j;
    i = j = 0;
    char *postfix;
    postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 2)); // extra 2 cells for initial symbol and \0

    while (infix[i] != '\0')
    {
        if (IsOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (Precedance(infix[i]) > Precedance(top->data)) // stack should contain something before hand in order to avoid error
                push(top, infix[i++]);
            else
            {
                postfix[j++] = pop(top);
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop(top);
    }
    postfix[j] = '\0';
    return postfix;
}
void KillStack(struct Node *st)
{
    if (!st)
        return;
    while (st)
    {
        pop(st);
    }
}
int EvalPostfix(char *postfix) //works for only single digit numbers
{// stack data must be of int type
    int i=0;
    int x1,x2,r;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(IsOperand(postfix[i]))
            push(top,postfix[i]-'0');// push int value of char
        else
        {
            x2=pop(top);
            x1=pop(top);
            switch(postfix[i])
            {
                case '+':r=x1+x2;break;
                case '-':r=x1-x2;break;
                case '*':r=x1*x2;break;
                case '/':r=x1/x2;break;
            }
            push(top,r);
        }
    }
    return top->data;
}
int main(int argc, char const *argv[])
{
    return 0;
}

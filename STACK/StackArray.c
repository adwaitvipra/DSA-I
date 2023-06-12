#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *S; // arr of integers in heap
};
void Create(struct Stack *st)
{
    printf("Enter Size:\n");
    scanf(" %d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(sizeof(int) * (st->size));
}
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}
int IsEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
int IsFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    return 0;
}
void push(struct Stack *st, int x)
{
    if (IsFull(*st))
        printf("Stack Overflow!\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
int pop(struct Stack *st)
{
    int x = -1;
    if (IsEmpty(*st))
        printf("Stack Underflow!");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
int peek(struct Stack st, int index) // this index is from top to bottom starts with 1 and ends to size of stack
{
    int x = -1;
    if (IsEmpty(st))
        return x;
    if (st.top - index + 1 < 0 || st.top - index + 1 > st.size)
        return x;
    x = st.S[st.top - index + 1];
    return x;
}
int StackTop(struct Stack st)
{
    if (!IsEmpty(st))
    {
        return st.S[st.top];
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    struct Stack st;
    Create(&st);
    push(&st, 50);
    push(&st, 40);
    push(&st, 30);
    push(&st, 20);
    push(&st, 10);
    push(&st, 0);
    printf("%d is stack top", StackTop(st));
    Display(st);

    printf("%d is peek\n", peek(st, 0));
    printf("%d is peek\n", peek(st, 1));
    printf("%d is peek\n", peek(st, 2));
    printf("%d is peek\n", peek(st, 3));
    printf("%d is peek\n", peek(st, 4));
    printf("%d is peek\n", peek(st, 5));
    printf("%d is peek\n", peek(st, 6));
    return 0;
}

struct StackNode
{
    struct Node* data;
    struct StackNode *next;
}*top=NULL;
int IsEmptyStk(struct StackNode *st)
{
    return st ? 0 : 1;
}
int IsFullStk()
{
    int r;
    struct StackNode *t;
    t = (struct StackNode *)malloc(sizeof(struct StackNode));
    r = !t ? 1 : 0; // if t is NULL return 1 that is heap is full else return 0
    free(t);
    return r;
}
void push(struct StackNode *st, struct Node* x)
{
    if (IsFullStk())
    {
        printf("Stack Overflow!");
        return;
    }
    struct StackNode *t;
    t = (struct StackNode *)malloc(sizeof(struct StackNode));
    t->data = x;
    t->next = st;
    top = t;
}
struct Node* pop(struct StackNode *st)
{
    struct Node* x = NULL;
    if (IsEmptyStk(st))
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
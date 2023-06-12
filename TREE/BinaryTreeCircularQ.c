#include <stdio.h>
#include <stdlib.h>
#include "CircularQ.h"
#include "StackLL.h"

void createTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQ(&q, 100);

    printf("Enter root value:");
    scanf(" %d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!IsEmptyQ(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d:", p->data);
        scanf(" %d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d:", p->data);
        scanf(" %d", &x);
        if (x != -1) // Enter -1 to make the right or left of node null
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preOrder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void inOrder(struct Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}
void postOrder(struct Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}

// iterative tree traversals
void IPreOrder(struct Node *p)
{
    while (p || !IsEmptyStk(top))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(top, p);
            p = p->lchild;
        }
        else
        {
            p = pop(top);
            p = p->rchild;
        }
    }
}
void IInOrder(struct Node *p)
{
    while (p || !IsEmptyStk(top))
    {
        if (p)
        {
            push(top, p);
            p = p->lchild;
        }
        else
        {
            p = pop(top);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}
void IPostOrder(struct Node *p)
{
    // there is specific address for negative as well as positive long int and I found that address <-----> long int
    long int temp = 0;
    while (p || !IsEmptyStk(top))
    {
        if (p)
        {
            push(top, p);
            p = p->lchild;
        }
        else
        {
            temp = (long int)pop(top);
            if (temp > 0) // address was pushed first time
            {
                push(top, (struct Node *)(-temp)); // make addresss negative as it is pushed second time
                p = ((struct Node *)(temp))->rchild;
            }
            else // address is negative so make the p point on positive value of address by negating negative temp
            {
                p = (struct Node *)(-temp);
                printf("%d ", p->data);
                p = NULL;
            }
        }
    }
}
void LevelOrder(struct Node *p)
{
    struct Queue q;
    createQ(&q, 100);

    printf("%d ", p->data);
    enqueue(&q, p);

    while (!IsEmptyQ(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}
int countNode(struct Node *p)
{
    if (p)
    {
        return countNode(p->lchild) + countNode(p->rchild) + 1;
    }
    return 0;
}
int height(struct Node *p)
{
    int x, y;
    if (!p)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int count2childNodes(struct Node *p)
{
    int x, y;
    if (!p)
        return 0;
    x = count2childNodes(p->lchild);
    y = count2childNodes(p->rchild);
    if (p->lchild && p->rchild) // cnt the node which has two childs
        return x + y + 1;
    else
        return x + y;
}
int SumTree(struct Node *t)
{
    if (!t)
        return 0;
    return SumTree(t->lchild) + SumTree(t->rchild) + t->data;
}
int main(int argc, char const *argv[])
{
    createTree();


    return 0;
}

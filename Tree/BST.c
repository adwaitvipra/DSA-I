#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;
void displayLevel(struct Node* t, int level)
{
    if (!t)
        return;
    if (level == 1)
    {
        printf("%d ", t->data);
    }
    displayLevel(t->lchild, level - 1);
    displayLevel(t->rchild, level - 1);
}
int Height(struct Node *p)
{
    int x, y;
    if (!p)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
struct Node *FindMax(struct Node *p) // inorder predecessor
{
    while (p && p->rchild)
        p = p->rchild;
    return p;
}
struct Node *FindMin(struct Node *p) // inorder successor
{
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

void Iinsert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->rchild = p->lchild = NULL;
        root = p;
        return;
    }
    while (t)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->rchild = p->lchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
    return;
}
struct Node *Rinsert(struct Node *t, int x) // root must be passed and root should take return value
{                                           // multiple links are modified in this function, returning ptr to a struct Node
    if (!t)
    {
        struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
        nn->data = x;
        nn->lchild = nn->rchild = NULL;
        return nn;
    }
    if (t->data < x)
    {
        t->rchild = Rinsert(t->rchild, x);
    }
    else if (t->data > x)
    {
        t->lchild = Rinsert(t->lchild, x);
    }
    return t;
}
void RInsertStatic(struct Node *t, int x) // pass root
{
    static struct Node *p, *q = NULL; // This line will be executed in first call only
    p = t;                            // in all the calls after first call p will take value of lchild or rchild
    if (!p)                           // p becomes null
    {
        struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
        nn->data = x;
        nn->lchild = nn->rchild = NULL;
        if (!q) // root is null, so make root point to nn
            root = nn;
        else
        {
            if (q->data < x)
                q->rchild = nn;
            else
                q->lchild = nn;
        }
        return;
    }
    q = p;           // q will follow p
    if (p->data < x) // go to right
    {
        p = p->rchild;
        RInsertStatic(p, x);
    }
    else if (p->data > x) // go to lchild
    {
        p = p->lchild;
        RInsertStatic(p, x);
    }
    return; // if duplicate found p will never become null
}
void Rinorder(struct Node *p)
{
    if (p)
    {
        Rinorder(p->lchild);
        printf("%d ", p->data);
        Rinorder(p->rchild);
    }
}
struct Node *Isearch(int key)
{
    struct Node *t = root;
    while (t)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}
struct Node *DeleteInorder(struct Node *p, int key) // delete struct Node using inorder predecessor and successor using depending upont the height
{
    if (!p) // empty tree or key not found
        return NULL;
    // searching the struct Node
    if (p->data > key)
        p->lchild = DeleteInorder(p->lchild, key);
    else if (p->data < key)
        p->rchild = DeleteInorder(p->rchild, key);
    else // struct Node found
    {    // case 1: No child
        if (!p->lchild && !p->rchild)
        {
            if (p == root)
                root = NULL;
            free(p);
            p = NULL;
            return NULL;
        }
        else // case 2: One or Two childs
        {
            struct Node *temp = NULL;

            if (Height(p->lchild) > Height(p->rchild)) // inorder predecessor
            {
                temp = FindMax(p->lchild);
                p->data = temp->data;
                p->lchild = DeleteInorder(p->lchild, temp->data);
            }
            else // inorder successor
            {
                temp = FindMin(p->rchild);
                p->data = temp->data;
                p->rchild = DeleteInorder(p->rchild, temp->data);
            }
        }
    }
    return p;
}
struct Node *Delete(struct Node *link, int key)
{
    if (!link) // empty tree or key not found
        return link;
    // search for struct Node
    else if (link->data < key)
        link->rchild = Delete(link->rchild, key);
    else if (link->data > key)
        link->lchild = Delete(link->lchild, key);
    else // struct Node found
    {
        // case 1:No child
        if (!link->rchild && !link->lchild)
        {
            free(link);
            link = NULL; // set dangling ptr link to null
        }
        // case 2:One child
        else if (!link->rchild)
        {
            struct Node *temp = NULL;
            temp = link;
            link = link->lchild; // move link to lchild
            free(temp);
            temp = NULL;
        }
        else if (!link->lchild)
        {
            struct Node *temp = NULL;
            temp = link;
            link = link->rchild; // move link to right
            free(temp);
            temp = NULL;
        }
        // case 3: Two childs
        else
        {
            struct Node *temp = NULL;
            // inorder predecessor or inorder successor
            temp = FindMin(link->rchild); // FindMax(link->lchild);
            link->data = temp->data;
            link->rchild = Delete(link->rchild, temp->data);
        }
    }
    return link;
}
struct Node *newNode(int x)
{
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    if (!nn)
        return NULL;
    nn->data = x;
    nn->lchild = nn->rchild = NULL;
    return nn;
}
int main(int argc, char const *argv[])
{
    Cinsert(root,10);
    Cinsert(root,20);
    Cinsert(root,30);
    Cinsert(root,40);
    Cinsert(root,50);
    Cinsert(root,60);
    Cinsert(root,70);
    printf("\n");
    Rinorder(root);
    printf("\n");
    return 0;
}

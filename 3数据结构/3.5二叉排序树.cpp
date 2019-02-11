#include <stdio.h>
#include <string.h>

struct Node
{
    Node *lchild;
    Node *rchild;
    int c;
} Tree[110];
int loc; //静态数组中被使用元素个数
Node *creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}
//后序
void postOrder(Node *T)
{
    if (T->lchild != NULL)
    {
        postOrder(T->lchild);
    }
    if (T->rchild != NULL)
    {
        postOrder(T->rchild);
    }
    printf("%d ", T->c);
}
//中序
void inOrder(Node *T)
{
    if (T->lchild != NULL)
    {
        inOrder(T->lchild);
    }
    printf("%d ", T->c);
    if (T->rchild != NULL)
    {
        inOrder(T->rchild);
    }
}
//前序
void preOrder(Node *T)
{
    printf("%d ", T->c);
    if (T->lchild != NULL)
    {
        preOrder(T->lchild);
    }
    if (T->rchild != NULL)
    {
        preOrder(T->rchild);
    }
}
Node *Insert(Node *T, int x)
{
    if (T == NULL)
    {
        T = creat();
        T->c = x;
        return T;
    }
    else if (x < T->c)
    {
        T->lchild = Insert(T->lchild, x);
    }
    else if (x > T->c)
    {
        T->rchild = Insert(T->rchild, x);
    }
    return T;
}
int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        loc = 0;
        Node *T = NULL;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            T = Insert(T, x);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

struct Node
{
    Node *lchild;
    Node *rchild;
    int c;
} Tree[110];

int loc;

Node *creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}
//1 前序，2 中序
char str1[25], str2[5];
int size1, size2; //保存在字符数组中的遍历得到的字符个数
char *str;        //当前正在保存字符串
int *size;        //当前正在保存字符串中字符个数
void postOrder(Node *T)
//后序
{
    if (T->lchild != NULL)
    {
        postOrder(T->lchild);
    }
    if (T->rchild != NULL)
    {
        postOrder(T->rchild);
    }
    str[(*size)++] = T->c + '0';
}
//中序
void inOrder(Node *T)
{
    if (T->lchild != NULL)
    {
        inOrder(T->lchild);
    }
    str[(*size)++] = T->c + '0';
    if (T->rchild != NULL)
    {
        inOrder(T->rchild);
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
    char tmp[12];
    while (scanf("%d", &n) != EOF && n != 0)
    {
        loc = 0;
        Node *T = NULL;
        scanf("%s", tmp);
        for (int i = 0; tmp[i] != 0; i++)
        {
            T = Insert(T, tmp[i] - '0');
        }
        size1 = 0; //保存在第一个字符串中的字符初始化为零
        str = str1;
        size = &size1;
        postOrder(T);
        inOrder(T);
        str1[size1] = 0;
        while (n-- != 0)
        {
            scanf("%s", tmp);
            Node *T2 = NULL;
            for (int i = 0; tmp[i] != 0; i++)
            {
                T2 = Insert(T2, tmp[i] - '0');
            }
            size2 = 0;
            str = str2;
            size = &size2;
            postOrder(T2);
            inOrder(T2);
            str2[size2] = 0;
            puts(strcmp(str1, str2) == 0 ? "YES" : "NO");
        }
    }
    return 0;
}

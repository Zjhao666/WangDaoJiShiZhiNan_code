#include <stdio.h>
#include <string.h>

struct Node
{
    Node *lchild;
    Node *rchild;
    char c;
} Tree[50];
int loc; //静态数组中已分配的节点个数
Node *creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}
char str1[30], str2[30]; //保存前序和中序遍历结果字符串

void postOrder(Node *T) //后序遍历
{
    if (T->lchild != NULL)
    {
        postOrder(T->lchild);
    }
    if (T->rchild != NULL)
    {
        postOrder(T->rchild);
    }
    printf("%c", T->c);
}

//由字符串的前序和中序遍历还原树，并返回根节点
//前序遍历结果为str1[s1]到str1[e1]
//中序遍历结果为str2[s2]到str2[e2]
Node *build(int s1, int e1, int s2, int e2)
{
    Node *ret = creat();

    //前序
    ret->c = str1[s1];
    int rootIdx;
    //查找该根节点字符在中序遍历中的位置
    for (int i = s2; i <= e2; i++)
    {
        if (str2[i] == str1[s1])
        {
            rootIdx = i;
            break;
        }
    }
    if (rootIdx != s2) //左子树不为空
    {
        //递归还原左子树
        ret->lchild = build(s1 + 1, s1 + (rootIdx - s2), s2, rootIdx - 1);
    }
    if (rootIdx != e2) //右子树不为空
    {
        //递归还原右子树
        ret->rchild = build(s1 + (rootIdx - s2) + 1, e1, rootIdx + 1, e2);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    while (scanf("%s", str1) != EOF)
    {
        scanf("%s", str2);
        loc = 0;
        int L1 = strlen(str1);
        int L2 = strlen(str2);
        Node *T = build(0, L1 - 1, 0, L2 - 1);
        postOrder(T);
        printf("\n");
    }
    return 0;
}

#include <stdio.h>

using namespace std;

#define N 1000

int Tree[N];
int findRoot(int x) //查找某个节点所在树的根节点
{
    if (Tree[x] == -1)
        return x;
    else
    {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        scanf("%d", &m);
        for (int i = 1; i <= n; i++)
            Tree[i] = -1;
        while (m-- != 0)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            //若两个定点不在同一个集合则合并这两个集合
            if (a != b)
                Tree[a] = b;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (Tree[i] == -1)
                ans++;
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}

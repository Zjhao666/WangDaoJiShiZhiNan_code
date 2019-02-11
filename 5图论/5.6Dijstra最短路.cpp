#include <stdio.h>
#include <vector>
using namespace std;
struct E //邻接链表
{
    int next;
    int c;
};
vector<E> edge[101];
bool mark[101]; //标记，当mark[j]为true时表示j的最短路径已经得到，该结点已加入集合K
int Dis[101];   //距离向量，当mark[i]为true时表示已得的最短路径长度；否则为过K的最短
int main(int argc, char const *argv[])
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++)
            edge[i].clear();
        while (m--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            E tmp;
            tmp.c = c;
            tmp.next = b;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
        for (int i = 1; i <= n; i++)
        {
            Dis[i] = -1;     //距离无穷大即不可达
            mark[i] = false; //不属于集合K
        }
        Dis[1] = 0;
        mark[1] = true;
        int newP = 1;               //新加入集合K中的结点为1
        for (int i = 1; i < n; i++) //确定其余n-1个结点的最短路径长度
        {
            //遍历与该新加入集合K中的结点直接相邻的边
            for (int j = 0; j < edge[newP].size(); j++)
            {
                int t = edge[newP][j].next;
                int c = edge[newP][j].c;
                if (mark[t] == true) //另一个结点也属于集合K
                    continue;
                if (Dis[t] == -1 || Dis[t] > Dis[newP] + c)
                    Dis[t] = Dis[newP] + c;
            }
            int min = __INT_MAX__;
            //遍历所有结点
            for (int j = 1; j <= n; j++)
            {
                if (mark[j] == true) //另一个结点也属于集合K
                    continue;
                if (Dis[j] == -1)
                    continue;
                if (Dis[j] < min)
                {
                    min = Dis[j];
                    newP = j;
                }
            }
            mark[newP] = true;
        }
        printf("%d\n", Dis[n]);
    }
    return 0;
}

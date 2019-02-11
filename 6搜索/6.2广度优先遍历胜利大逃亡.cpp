#include <stdio.h>
#include <queue>
using namespace std;
bool mark[50][50][50]; //标记数组
int maze[50][50][50];  //保存立方体信息
struct N
{
    int x, y, z;
    int t;
};
queue<N> Q; //队列中的元素为状态
int go[][3] = {{1, 0, 0},
               {-1, 0, 0},
               {0, 1, 0},
               {0, -1, 0},
               {0, 0, 1},
               {0, 0, -1}};  //状态变换数组
int BFS(int a, int b, int c) //广度优先搜索，返回其最少耗时
{
    while (Q.empty() == false)
    {
        N now = Q.front();
        Q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = now.x + go[i][0];
            int ny = now.y + go[i][1];
            int nz = now.z + go[i][2];
            if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c)
                continue;
            if (maze[nx][ny][nz] == 1)
                continue;
            if (mark[nx][ny][nz] == true)
                continue;
            N tmp;
            tmp.x = nx;
            tmp.y = ny;
            tmp.z = nz;
            tmp.t = now.t + 1;       //新状态耗时加一
            Q.push(tmp);             //将该状态放入队列
            mark[nx][ny][nz] = true; //标记该坐标已被访问
            if (nx == a - 1 && ny == b - 1 && nz == c - 1)
                return tmp.t;
        }
    }
    return -1; //若所有的状态被查找完后，仍得不到所需坐标，则返回-1
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b, c, t;
        scanf("%d%d%d%d", &a, &b, &c, &t);
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    scanf("%d", &maze[i][j][k]);
                    mark[i][j][k] = false;
                }
            }
        }
        while (Q.empty() == false)
            Q.pop();
        mark[0][0][0] = true;
        N tmp;
        tmp.t = tmp.x = tmp.y = tmp.z = 0;
        Q.push(tmp);
        int rec = BFS(a, b, c); //广度优先搜索
        if (rec <= t)
            printf("%d\n", rec);
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}

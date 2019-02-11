#include <stdio.h>
#include <queue>
using namespace std;
struct N
{
    int a, b, c; //每个杯子中可乐的体积
    int t;       //得到该体积组倾倒次数
};
queue<N> Q;
bool mark[101][101][101]; //第一次得到的状态才为有效状态
//容积sa,sb 原始含有可乐体积a,b
void AtoB(int &a, int sa, int &b, int sb)
{
    if (sb - b >= a) //a可以全部倒入b中
    {
        b += a;
        a = 0;
    }
    else //a将b倒满，但a还有剩余
    {
        a -= sb - b;
        b = sb;
    }
}
int BFS(int s, int n, int m)
{
    while (Q.empty() == false)
    {
        N now = Q.front();
        Q.pop();
        int a, b, c;
        a = now.a;
        b = now.b;
        c = now.c; //读出三个杯子中的可乐体积

        for (int turn = 0; turn < 6; turn++)
        {
            if (turn == 0)
                AtoB(a, s, b, n); //由a倾倒向b
            else if (turn == 1)
                AtoB(b, n, a, s); //由a倾倒向b
            else if (turn == 2)
                AtoB(a, s, c, m); //由a倾倒向b
            else if (turn == 3)
                AtoB(c, m, a, s); //由a倾倒向b
            else if (turn == 4)
                AtoB(b, n, c, m); //由a倾倒向b
            else if (turn == 5)
                AtoB(c, m, b, n); //由a倾倒向b
            if (mark[a][b][c] == false)
            {
                mark[a][b][c] = true;
                N tmp;
                tmp.a = a;
                tmp.b = b;
                tmp.c = c;
                tmp.t = now.t + 1;
                if (a == s / 2 && b == s / 2)
                    return tmp.t;
                if (c == s / 2 && b == s / 2)
                    return tmp.t;
                if (a == s / 2 && c == s / 2)
                    return tmp.t;
                Q.push(tmp); //否则放入队列
            }
            a = now.a;
            b = now.b;
            c = now.c;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int s, n, m;
    while (scanf("%d%d%d", &s, &n, &m) != EOF)
    {
        if (s == 0)
            break;
        if (s % 2 == 1) //若s为奇数则不可能平分，直接输出NO
        {
            puts("NO");
            continue;
        }
        for (int i = 0; i <= s; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= m; k++)
                {
                    mark[i][j][k] = false;
                }
            }
        }
        N tmp;
        tmp.a = s;
        tmp.b = 0;
        tmp.c = 0;
        tmp.t = 0;
        while (Q.empty() == false)
            Q.pop();
        Q.push(tmp);
        mark[s][0][0] = true;
        int rec = BFS(s, n, m);
        if (rec == -1)
            puts("NO");
        else
            printf("%d\n", rec);
    }
    return 0;
}

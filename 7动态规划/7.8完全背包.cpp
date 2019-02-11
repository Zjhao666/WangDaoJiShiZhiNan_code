#include <stdio.h>
int min(int a, int b) { return a < b ? a : b; }
struct E //钱币结构体
{
    int w; //重量
    int v; //价值
} list[501];
int dp[100001]; //状态
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int s, tmp;
        scanf("%d%d", &tmp, &s); //空储蓄罐数量 装满钱币的储蓄罐重量
        s -= tmp;                //计算钱币所占重量
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &list[i].v, &list[i].w);
        }
        for (int i = 0; i <= s; i++)
        {
            dp[i] = __INT_MAX__;
        }
        dp[0] = 0; //要求恰好装满，故除了dp[0]外的dp[j]均为无穷
        for (int i = 1; i <= n; i++)
        {
            for (int j = list[i].w; j <= s; j++)
            {
                if (dp[j - list[i].w] != __INT_MAX__)
                    dp[j] = min(dp[j], dp[j - list[i].w] + list[i].v);
            }
        }
        if (dp[s] != __INT_MAX__)
            printf("The mimimum amount of money in the piggy-bank is %d.\n", dp[s]);
        else
            puts("This is impossible.\n");
    }
    return 0;
}

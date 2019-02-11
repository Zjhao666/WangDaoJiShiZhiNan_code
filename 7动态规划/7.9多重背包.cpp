#include <stdio.h>
struct E
{
    int w;
    int v;
} list[2001];
int dp[101];
int max(int a, int b) { return a > b ? a : b; }
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int s, n;
        scanf("%d%d", &s, &n);
        int cnt = 0; //拆分后物品总重量
        for (int i = 1; i <= n; i++)
        {
            int v, w, k;
            scanf("%d%d%d", &w, &v, &k);
            int c = 1;
            while (k - c > 0)
            {
                k -= c;
                // 拆分后的大米重量
                list[++cnt].w = c * w;
                // 价格均为组成该物品的大米的重量价格和
                list[cnt].v = c * v;
                c *= 2;
            }
            list[++cnt].w = w * k;
            list[cnt].v = v * k;
        }
        for (int i = 1; i <= s; i++)
            dp[i] = 0;
        // 对拆分后的所有物品进行零一背包
        for (int i = 1; i <= cnt; i++)
        {
            for (int j = s; j >= list[i].w; j--)
            {
                dp[j] = max(dp[j], dp[j - list[i].w] + list[i].v);
            }
        }
        printf("%d\n", dp[s]);
    }
    return 0;
}

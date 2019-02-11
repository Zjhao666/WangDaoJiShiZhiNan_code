#include <stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int list[26];     //各导弹的高度
int dp[26] = {0}; //保存第i个导弹结尾的最长不增子序列长度
int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &list[i]);
        } //输入
        for (int i = 1; i <= n; i++)
        {
            int tmax = 1; //最长不增子序列长度至少为1
            for (int j = 1; j < i; j++)
            {
                if (list[j] >= list[i])
                    tmax = max(tmax, dp[j] + 1);
            }
            dp[i] = tmax;
        }
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
#include <stdio.h>
#define OFFSET 2000 //橘子重量差存在负数,偏置为合法数组下标
//dp[i][j] 前i个橘子被选择后，第一堆比第二堆重j时，两堆的最大总重量和
int dp[101][4001];
int list[101]; //保存柑橘数量
int main(int argc, char const *argv[])
{
    int T;
    int cas = 0;
    scanf("%d", &T);
    while (T-- != 0)
    {
        int n;
        scanf("%d", &n);
        bool HaveZero = false; //统计是否存在重量为0的柑橘
        int cnt = 0;           //记录共有多少个重量非0的柑橘
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &list[++cnt]);
            if (list[cnt] == 0)
            {
                cnt--;
                HaveZero = true;
            }
        }
        n = cnt;
        for (int i = -2000; i <= 2000; i++)
        {
            dp[0][i + OFFSET] = -__INT_MAX__;
        } //对重量加上offset后读取或调用
        dp[0][0 + OFFSET] = 0;
        for (int i = 1; i <= n; i++) //每个柑橘
        {
            for (int j = -2000; j <= 2000; j++) //每个可能的重量差
            {
                int tmp1 = -__INT_MAX__, tmp2 = -__INT_MAX__;
                //状态可以由放在第一堆转移而来
                if (j + list[i] <= 2000 && dp[i - 1][j + list[i] + OFFSET] != -__INT_MAX__)
                {
                    tmp1 = dp[i - 1][j + list[i] + OFFSET] + list[i];
                }
                //状态可以由放在第二堆转移而来
                if (j - list[i] >= -2000 && dp[i - 1][j - list[i] + OFFSET] != -__INT_MAX__)
                {
                    tmp2 = dp[i - 1][j - list[i] + OFFSET] + list[i];
                }
                if (tmp1 < tmp2)
                {
                    tmp1 = tmp2;
                } //取两者中较大的那个
                if (tmp1 < dp[i - 1][j + OFFSET])
                {
                    tmp1 = dp[i - 1][j + OFFSET];
                }
                //保存为三个转移来源转移得到的新值中最大的那个
                dp[i][j + OFFSET] = tmp1;
            }
        }
        printf("Case %d: ", ++cas); //按题目要求输出
        if (dp[n][0 + OFFSET] == 0)
        {
            puts(HaveZero == true ? "0" : "-1");
        }
        else
        {
            printf("%d\n", dp[n][0 + OFFSET] / 2);
        }
    }

    return 0;
}

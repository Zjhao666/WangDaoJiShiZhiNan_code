#include <stdio.h>
int max(int a, int b) { return a > b ? a : b; }
struct E
{          //保存物品信息结构体
    int w; //物品的体积
    int v; //物品的价值
} list[101];
//dp[i][j]表示前i个物品组成的总体积不大于j的最大价值和
int dp[101][1001];
int main(int argc, char const *argv[])
{
    //s 可用资源
    //n 物品种类数
    int s, n;
    while (scanf("%d%d", &s, &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &list[i].w, &list[i].v);
        } //输出
        for (int i = 0; i <= s; i++)
        {
            dp[0][i] = 0;
        } //初始化状态
        for (int i = 1; i <= n; i++)
        {
            //为了保证状态的正确转移
            //我们必须保证在每次更新中确定状态dp[j]时
            //dp[j]和dp[j-list[i].w]尚未被本次更新修改
            //所以倒序遍历
            for (int j = s; j >= list[i].w; j--)
            {
                //仅与二维数组中本行的上一行有关
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - list[i].w] + list[i].v);
            }
            //状态进能来源于dp[i-1][j]，所以直接赋值
            for (int j = list[i].w - 1; j >= 0; j--)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
        printf("%d\n", dp[n][s]);
    }

    return 0;
}

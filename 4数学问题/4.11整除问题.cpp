#include <stdio.h>
#include <string.h>

bool mark[1010];
int prime[1010];
int primeSize;

void init() //筛选出0到1000范围内的所有素数
{
    for (int i = 1; i < 1000; i++)
    {
        mark[i] = false;
    }
    primeSize = 0;
    for (int i = 2; i <= 1000; i++)
    {
        if (mark[i])
            continue;
        prime[primeSize++] = i;
        for (int j = i * i; j <= 1000; j += i)
        {
            mark[j] = true;
        }
    }
}

int cnt[1010];  //prime[i]在n!中因子数
int cnt2[1010]; //prime[i]在a中因子数

int main(int argc, char const *argv[])
{
    int n, a;
    init();
    while (scanf("%d%d", &n, &a) == 2)
    {
        for (int i = 0; i < primeSize; i++)
        {
            cnt[i] = cnt2[i] = 0;
        }
        //对n!分解素因数，遍历每一个0到1000的素数
        for (int i = 0; i < primeSize; i++)
        {
            int t = n;
            //确定素数prime[i]在n中的因子数
            while (t)
            {
                cnt[i] += t / prime[i];
                t = t / prime[i];
            } //依次计算t/prime[k]^k，累加其值。直到t/prime[i]^k变为0
        }
        int ans = __INT_MAX__;
        for (int i = 0; i < primeSize; i++) //对a分解素因数
        {
            while (a % prime[i] == 0)
            {
                cnt2[i]++;
                a /= prime[i];
            } //计算a中素因数prime[i]对应的幂指数
            if (cnt2[i] == 0)
                continue;
            if (cnt[i] / cnt2[i] < ans)
                ans = cnt[i] / cnt2[i]; //统计商中的最小值
        }
        printf("%d\n", ans);
    }
    return 0;
}

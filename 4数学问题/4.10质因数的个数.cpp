#include <stdio.h>

bool mark[100001]; //若mark[x]为true，则表示该数已被标记成非素数
int prime[100001]; //保存筛得的素数
int primeSize;     //保存素数的个数

void init()
{
    for (int i = 1; i < 10000; i++)
    {
        mark[i] = false;
    }
    primeSize = 0;
    for (int i = 2; i <= 100000; i++)
    {
        if (mark[i] == true)
            continue;
        prime[primeSize++] = i;
        if (i >= 1000)
            continue;
        for (int j = i * i; j <= 100000; j += i)
        {
            mark[j] = true;
        }
    }
}
int main(int argc, char const *argv[])
{
    init();
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ansPrime[30]; //按顺序保存分解出的素因数
        int ansSize = 0;  //分解出素因数的个数
        int ansNum[30];   //保存分解出的素因数对应的幂指数
        for (int i = 0; i < primeSize; i++)
        {
            if (n % prime[i] == 0)
            {
                ansPrime[ansSize] = prime[i]; //则该素数为其幂指数
                ansNum[ansSize] = 0;          //初始化幂指数为0
                while (n % prime[i] == 0)
                {
                    ansNum[ansSize]++;
                    n /= prime[i];
                }
                ansSize++;
                if (n == 1)
                    break;
            }
        }
        //剩余的因数一定是一个大于100000的素因数
        if (n != 1)
        {
            ansPrime[ansSize] = n;
            ansNum[ansSize++] = 1;
        }
        int ans = 0;
        for (int i = 0; i < ansSize; i++)
        {
            ans += ansNum[i];//统计各个素因数的幂指数
        }
        printf("%d\n", ans);
    }
    return 0;
}

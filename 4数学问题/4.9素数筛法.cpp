#include <stdio.h>

int prime[10000]; //保存筛得的素数
int primeSize;    //保存素数的个数
bool mark[10001]; //若mark[x]为true，则表示该数已被标记成非素数
void init()
{
    for (int i = 1; i < 10000; i++)
    {
        mark[i] = false;
    }
    primeSize = 0;
    for (int i = 2; i < 10000; i++)
    {
        if (mark[i] == true)
            continue;
        prime[primeSize++] = i;
        for (int j = i * i; j <= 10000; j += i)
        {
            mark[j] = true;
        }
    }
}

int main(int argc, char const *argv[])
{
    init(); //得到2到10000中所有素数
    int n;
    while (scanf("%d", &n) != EOF)
    {
        bool isOutput = false; //表示是否输出了符合条件的数字
        for (int i = 0; i < n; i++)
        {
            if (prime[i] < n && prime[i] % 10 == 1)
            // 若当前输出为第一个输出的数字
            // 则标记已经给出了符合条件的数字
            // 且该数字前不输出空格
            {
                isOutput = true;
                printf(" %d", prime[i]);
            }
            else
                continue;
        }
        if (isOutput == false)
        {
            printf("-1\n");
        }
        else
            printf("\n");
    }

    return 0;
}

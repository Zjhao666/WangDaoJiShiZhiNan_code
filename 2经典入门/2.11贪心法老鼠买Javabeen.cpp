#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct goods
{
    double j; //总重
    double f; //总价值
    double s; //性价比
    bool operator<(const goods &A) const
    {
        return s > A.s;
    }
} buf[1000];

int main(int argc, char const *argv[])
{
    double m;
    int n;
    while (scanf("%lf%d", &m, &n) != EOF)
    {
        if (m == -1 && n == -1)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &buf[i].j, &buf[i].f);
            buf[i].s = buf[i].j / buf[i].f;
        }
        sort(buf, buf + n); //降序排序
        int idx = 0;        //当前货物下标
        double ans = 0;     //累加总重量
        while (m > 0 && idx < n)
        {
            if (m > buf[idx].f)
            {
                ans += buf[idx].j;
                m -= buf[idx].f;
            }
            else
            {
                ans += buf[idx].j * m / buf[idx].f;
                m = 0;
            }
            idx++;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}

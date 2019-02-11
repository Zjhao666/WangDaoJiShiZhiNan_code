#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long a, b;
    int m;
    while (scanf("%d", &m) != EOF)
    {
        if (m == 0)
            break;
        scanf("%lld%lld", &a, &b);
        a = a + b;
        int ans[50], size = 0;
        do
        {
            ans[size++] = a % m;
            a /= m;
        } while (a != 0);
        //输出顺序从高位到低位
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
long long F(int num)
{
    if (num == 1)
        return 2;
    else
        return 3 * F(num - 1) + 2;
}
int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%lld\n", F(n));
    }
    return 0;
}

#include <stdio.h>

int gcd(int a, int b) //求最大公约数
{
    return b != 0 ? gcd(b, a % b) : a;
}

int main(int argc, char const *argv[])
{
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        printf("%d\n", a * b / gcd(a, b));
    }
    return 0;
}

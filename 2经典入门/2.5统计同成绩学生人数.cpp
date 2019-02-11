#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        int Hash[101] = {0};
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            Hash[x]++;
        }
        int x;
        scanf("%d", &x);
        printf("%d\n", Hash[x]);
    }

    return 0;
}

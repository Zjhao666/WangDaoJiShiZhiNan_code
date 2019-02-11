#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int buf[200];
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &buf[i]);
        }
        int x, ans = -1;
        scanf("%d", &x);
        for (int i = 0; i < n; i++)
        {
            if (x == buf[i])
            {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

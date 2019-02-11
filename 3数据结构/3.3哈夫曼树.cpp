#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> Q;

int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        while (Q.empty() == false)
        {
            Q.pop();
        }
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            Q.push(x);
        }
        int ans = 0;
        while (Q.size() > 1)
        {
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            ans += (a + b);
            Q.push(a + b);
        }
        printf("%d\n", ans);
    }

    return 0;
}

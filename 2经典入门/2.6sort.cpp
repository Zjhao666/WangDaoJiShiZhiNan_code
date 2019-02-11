#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define OFFSET 500000
int Hash[1000001] = {0};

int main(int argc, char const *argv[])
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            Hash[x + OFFSET] = 1;
        }

        for (int i = 500000; i >= -500000; i--)
        {
            if (Hash[i + OFFSET] == 1)
            {
                printf("%d", i);
                m--;
                if (m != 0)
                {
                    printf(" ");
                }
                else
                {
                    printf("\n");
                    break;
                }
            }
        }
    }

    return 0;
}

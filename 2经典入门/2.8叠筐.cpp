#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int outPutBuf[82][82];
    char a, b;
    int n;
    bool firstCase = true;
    while (scanf("%d %c %c", &n, &a, &b) == 3)
    {
        if (firstCase == true)
        {
            firstCase = false;
        }
        else
        {
            printf("\n");
        }
        for (int i = 1, j = 1; i <= n; i += 2, j++)
        {
            int x = n / 2 + 1, y = x;
            //每个圈左上角点的坐标
            x -= j - 1;
            y -= j - 1;
            char c = j % 2 == 1 ? a : b;
            for (int k = 1; k <= i; k++)
            {
                outPutBuf[x + k - 1][y] = c;         //左边
                outPutBuf[x][y + k - 1] = c;         //上边
                outPutBuf[x + i - 1][y + k - 1] = c; //右边
                outPutBuf[x + k - 1][y + i - 1] = c; //下边
            }
        }
        if (n != 1)
        {
            outPutBuf[1][1] = ' ';
            outPutBuf[n][1] = ' ';
            outPutBuf[1][n] = ' ';
            outPutBuf[n][n] = ' ';
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%c", outPutBuf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

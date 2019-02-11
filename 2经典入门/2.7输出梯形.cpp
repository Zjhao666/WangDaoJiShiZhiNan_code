#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int h;
    while (scanf("%d", &h) != EOF)
    {
        int maxLine = h + (h - 1) * 2;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= maxLine; j++)
            {
                if (j < maxLine - h - (i - 1) * 2 + 1)
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

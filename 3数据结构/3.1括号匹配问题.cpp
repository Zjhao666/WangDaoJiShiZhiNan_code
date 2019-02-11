#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> S;
char str[110]; //输入字符串
char ans[110]; //输出字符串

int main(int argc, char const *argv[])
{
    while (scanf("%s", str) != EOF)
    {
        int i;
        for (i = 0; str[i] != 0; i++)
        {
            if (str[i] == '(')
            {
                S.push(i);
                ans[i] = ' '; //暂且将对应的为输出字符串改为空格
            }
            else if (str[i] == ')')
            {
                if (S.empty() == false)
                {
                    S.pop();
                    ans[i] = ' ';
                }
                else
                {
                    ans[i] = '?';
                }
            }
            else
            {
                ans[i] = ' '; //其他字符不管
            }
        }
        while (!S.empty()) //当字符串遍历完成后，尚且留在堆栈中的左括号无法匹配
        {
            ans[S.top()] = '$';
            S.pop();
        }
        ans[i] = 0; //输出字符串最后一个为空字符
        puts(str);  //原始字符串
        puts(ans);  //答案字符串
    }
    return 0;
}

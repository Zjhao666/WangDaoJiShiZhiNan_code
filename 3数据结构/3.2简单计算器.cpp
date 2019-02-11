#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>

using namespace std;

char str[220]; //保存表达式字符串
//mat[i][j]表示第i号运算符优先级大于j号运算符
// 0 首尾标记运算符, 1 +, 2 -, 3 *, 4 /
int mat[][5] = {
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0},
    {1, 1, 1, 0, 0},
};

stack<int> op;    //保存运算符编号
stack<double> in; //保存中间运算结果
//reto 真为运算符，假为数字，都保存在retn中，i为表达式下标
void getOp(bool &reto, int &retn, int &i)
{
    //遍历第一个字符，运算符栈为空，添加编号为0的标记字符
    if (i == 0 && op.empty() == true)
    {
        reto = true;
        retn = 0;
        return;
    }
    //字符串已遍历完成
    if (str[i] == 0)
    {
        reto = true;
        retn = 0;
        return;
    }
    //遍历到数字
    if (str[i] >= '0' && str[i] <= '9')
    {
        reto = false;
    }
    else
    {
        reto = true;
        if (str[i] == '+')
        {
            retn = 1;
        }
        else if (str[i] == '-')
        {
            retn = 2;
        }
        else if (str[i] == '*')
        {
            retn = 3;
        }
        else if (str[i] == '/')
        {
            retn = 4;
        }
        i += 2; //i递增，跳过该运算字符和该运算字符后的空格
        return;
    }
    retn = 0; //返回结果为数字
    for (; str[i] != ' ' && str[i] != 0; i++)
    {
        retn *= 10;
        retn += str[i] - '0';
    }
    if (str[i] == ' ')
    {
        i++;
    }
    return;
}

int main(int argc, char const *argv[])
{
    while (gets(str))
    {
        //输入只有一个0，则退出
        if (str[0] == '0' && str[1] == 0)
        {
            break;
        }
        //函数所需要的两个引用变量
        bool retop;
        int retnum;

        int idx = 0; //遍历到的字符串下标，初始值为0
        //清空数字栈和运算符栈
        while (!op.empty())
        {
            op.pop();
        }
        while (!in.empty())
        {
            in.pop();
        }
        while (true) //循环遍历字符串表达式
        {
            getOp(retop, retnum, idx);
            if (retop == false) //该元素为数字
            {
                in.push((double)retnum);
            }
            else
            {
                double tmp;
                //运算符堆栈为空或者当前遍历到的运算符优先级大于栈顶运算符
                //将该运算符压入运算符堆栈
                if (op.empty() == true || mat[retnum][op.top()] == 1)
                {
                    op.push(retnum);
                }
                else
                {
                    //当前运算符小于栈顶运算符，重复循环
                    while (mat[retnum][op.top()] == 0)
                    {
                        int ret = op.top(); //保存栈顶运算符
                        op.pop();           //弹出
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop();
                        if (ret == 1)
                        {
                            tmp = a + b;
                        }
                        else if (ret == 2)
                        {
                            tmp = a - b;
                        }
                        else if (ret == 3)
                        {
                            tmp = a * b;
                        }
                        else
                        {
                            tmp = a / b;
                        }
                        in.push(tmp);
                    }
                    op.push(retnum);
                }
            }
            //只有标记运算符，表达式求值结束
            if (op.size() == 2 && op.top() == 0)
            {
                break;
            }
        }
        //输出数字栈中唯一的数字,即为答案
        printf("%.2f\n", in.top());
    }

    return 0;
}

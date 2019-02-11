#include <stdio.h>
#include <string.h>

struct bigInteger
{
    int digit[1000]; //按四位数一个单元保存数值
    int size;        //下一个我们我们未使用的数组单元
    void init()
    {
        for (int i = 0; i < 1000; i++)
        {
            digit[i] = 0;
        }
        size = 0;
    }
    void set(char str[]) //从字符串中提取整数
    {
        init();
        int L = strlen(str);
        //从最后一个字符开始倒序遍历字符串j,四个字符一个数字
        //t临时保存字符转换为数字的中间值
        //c表示当前位的权重,按照1,10,1000,1000顺序变化
        for (int i = L - 1, j = 0, t = 0, c = 1; i >= 0; i--)
        {
            t += (str[i] - '0') * c;
            j++;
            c *= 10;
            //已四个字符或已到达最后一个字符
            if (j == 4 || i == 0)
            {
                digit[size++] = t;
                j = 0; //重新开始计算下四个字符
                t = 0;
                c = 1; //权重变为1
            }
        }
    }
    void output() //输出
    {
        for (int i = size - 1; i >= 0; i--)
        {
            if (i != size - 1)
                printf("%04d", digit[i]);
            else
                printf("%d", digit[i]);
        }
        printf("\n");
    }
    bigInteger operator+(const bigInteger &A) const
    {
        bigInteger ret; //返回值,即两数相加的结果
        ret.init();
        int carry = 0; //进位，初始值为0
        for (int i = 0; i < A.size || i < size; i++)
        {
            int tmp = A.digit[i] + digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.size++] = tmp;
        }
        if (carry != 0) //计算完成后若最高位有进位
        {
            ret.digit[ret.size++] = carry;
        }
        return ret;
    }
} a, b, c;

char str1[1002], str2[1002];

int main(int argc, char const *argv[])
{
    while (scanf("%s%s", str1, str2) != EOF)
    {
        a.set(str1);
        b.set(str2);
        c = a + b;
        c.output();
    }
    return 0;
}

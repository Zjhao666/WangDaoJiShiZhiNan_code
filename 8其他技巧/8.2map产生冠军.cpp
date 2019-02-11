#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;

map<string, int> M;
int in[2002];
int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        for (int i = 0; i < 2 * n; i++)
        {
            in[i] = 0;
        }
        M.clear();
        int idx = 0; //下一个被映射的数字
        for (int i = 0; i < n; i++)
        {
            char str1[50], str2[50];
            scanf("%s%s", str1, str2);
            string a = str1, b = str2;
            int idxa, idxb;
            if (M.find(a) == M.end()) //没有
            {
                idxa = idx;
                M[a] = idx++;
            }
            else
            {
                idxa = M[a];
            }
            if (M.find(b) == M.end())
            {
                idxb = idx;
                M[b] = idx++;
            }
            else
            {
                idxb = M[b];
            }
            in[idxb]++;
        }
        int cnt = 0;
        for (int i = 0; i < idx; i++)
        {
            if (in[i] == 0)
            {
                cnt++;
            }
        }
        puts(cnt == 1 ? "YES" : "NO");
    }
    return 0;
}

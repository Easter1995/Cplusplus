#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, ans, max = 0;
    int a[10000] = {0};
    int b[10000] = {0};
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)//存储数据
        {
            cin >> a[i];
            b[i]=1;//初始化
        }
        for (int i = 1; i <= n; i++)
        {
            for (int k = 1; k <= i; k++)
            {
                if (a[i] > a[k])//寻找递增数//扫描子问题
                {
                    if(b[i]<b[k]+1)//寻找最优子问题
                    b[i] = b[k] + 1;//链接
                }
            }
        }
        for (int i = 1; i <= n; i++)//扫描最优解
        {
            if (b[i] > max)
                max = b[i];
        }
        printf("%d\n", max);
        max = 0;
    }
    return 0;
}

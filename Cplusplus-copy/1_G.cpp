//猫鼠交易
//结构体数组的排序
#include <bits/stdc++.h>
using namespace std;
struct cat
{
    double a, b;
    double c;
} arr[1000];
bool cmp(cat x, cat y)
{
    return x.c < y.c;
}
int main()
{
    int m, n, i;
    double result;
    while (cin >> m >> n)
    {
        if (m == -1 && n == -1)
            break;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i].a >> arr[i].b;
            arr[i].c = arr[i].a / arr[i].b;
        }
        sort(arr, arr + n, cmp);
        //排序
        for (i = n - 1; i >= 0; i--)
        {
            if (m < arr[i].b)
            {
                result += m * arr[i].c;
                break;
            }
            else
                result += arr[i].a;
            m = m - arr[i].b;
            if (m - 0 < 0.0001)
                break;
        }
        result *= 1000;
        result = (int)(result + 0.5);
        result /= 1000;
        printf("%.3lf\n", result);
        result = 0;
    }
    return 0;
}
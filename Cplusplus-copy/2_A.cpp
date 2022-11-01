//数塔
#include<bits/stdc++.h>
using namespace std;
// long long max(long long x,long long y)
// {
//     if(x>=y)
//         return x;
//     else
//         return y;
// }
//C++自带max和min函数，可以求两个数的最大值
int main()
{
    int c,n;
    cin>>c;
    for(int i=0;i<c;i++)
    {
        cin>>n;
        long long p[100][100]={0};
        //sum表示j+1行的几个数塔的最大值
        long long sum[100][100]={0};
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=j;k++)
            {
                cin>>p[j][k];
                if(j==n)
                    sum[j][k]=p[j][k];
            }
        }
        for(int j=n-1;j>=1;j--)
        {
            for(int k=1;k<=j;k++)
            {
                sum[j][k]=max(p[j][k]+sum[j+1][k],p[j][k]+sum[j+1][k+1]);
            }
        }
        cout<<sum[1][1]<<endl;
    }
    return 0;
}
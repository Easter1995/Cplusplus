#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long p[50]={0,3,6,6};
    while(scanf("%d",&n)!=EOF)
    {
        //i从4开始
        //因为i=3时，做不到前n-1个首位相同
        for(int i=4;i<=n;i++)
        {
            //前n-1个首尾不同+前n-1个首尾相同
            //前n-1首尾相同，则前n-2个首尾不同，且第n-1个两种颜色可选，第n个一种颜色可选
            p[i]=p[i-1]+2*p[i-2];
        }
        cout<<p[n]<<endl;
    }
}
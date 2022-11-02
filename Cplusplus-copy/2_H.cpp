//重建希望小学
//多重背包问题
#include<bits/stdc++.h>
using namespace std;
int price[1050],weight[1050],amount[1050],dp[1050];
int main()
{
    int t;
    int n,m,w,cnt;
    int a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cnt=1;
        for(int i=1;i<=m;i++)
        {
            w=1;
            cin>>a>>b>>amount[i];
            //把多个相同物品按二进制分成cnt组，把多重背包转换为01背包
            while(amount[i]>=w)
            {
                price[cnt]=a*w;
                weight[cnt++]=b*w;
                amount[i]-=w;
                w<<=1;
            }
            if(amount[i])
            {
                price[cnt]=a*amount[i];
                weight[cnt++]=b*amount[i];
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<cnt;i++)
        {
            for(int j=n;j>=price[i];j--)
                dp[j]=max(dp[j],dp[j-price[i]]+weight[i]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
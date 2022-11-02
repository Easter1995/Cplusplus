//寒冰王座
//完全背包
#include<bits/stdc++.h>
using namespace std;
int dp[10001];
int main()
{
    int T,n;
    int p[3]={150,200,350};
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<3;i++)
        {
            for(int j=p[i];j<=n;j++)
                dp[j]=max(dp[j],dp[j-p[i]]+p[i]);
        }
        cout<<n-dp[n]<<endl;
    }
}
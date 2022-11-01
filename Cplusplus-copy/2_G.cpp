#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f;
int dp[10001];
int v[10001],w[10001];
int main()
{
    int t,empty,full,n;
    cin>>t;
    while(t--)
    {
        memset(dp,inf,sizeof(dp));
        dp[0]=0;
        cin>>empty>>full;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>w[i]>>v[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=v[i];j<=full-empty;j++)
                dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
        }
        if(dp[full-empty]>=inf)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[full-empty]);
    }
    return 0;
}
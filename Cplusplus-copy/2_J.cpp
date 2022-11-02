//减肥记
#include<bits/stdc++.h>
using namespace std;
int a[101],b[101];
int dp[100000];
int n,m;
int main()
{    
    //输入多组数据一定要加那个!=EOF，不然程序结束不了会超时
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i],&b[i]);
        scanf("%d",&m);
        for(int i=0;i<n;i++)
        {
            for(int j=b[i];j<=m;j++)
                dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
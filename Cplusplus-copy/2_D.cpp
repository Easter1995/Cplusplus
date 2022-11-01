#include<bits/stdc++.h>
using namespace std;
int dp[100500][20];
int main()
{
	int n,a,b,x,t;
	while(scanf("%d",&n))
	{
		if(n==0)
		    break; 
		b=-1;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{ 
			scanf("%d %d",&x,&t);//坐标 时间 
			dp[t][x]++;//记录同一个时间点馅饼掉了多少个 
			b=max(b,t);
		}
		//printf("%d\n",b);
		for(int i=b-1;i>=0;i--)//时间限制
			for(int j=0;j<=10;j++)//步数限制 
				dp[i][j]=max(max(dp[i+1][j+1],dp[i+1][j-1]),dp[i+1][j])+dp[i][j];
		printf("%d\n",dp[0][5]);
	}
	return 0;
}
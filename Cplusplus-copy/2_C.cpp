//搬寝室
#include<bits/stdc++.h>
using namespace std;
int q[2010],dp[2010][2010];
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
		    scanf("%d",&q[i]);
        //sort函数默认升序排列
		sort(q+1,q+n+1);
        
        //dp[i][j]表示第i趟对前j个物体进行选择
        //i也表示选择第i对
		for(int i=1;i<=k;i++)
		{
			for(int j=2*i;j<=n;j++)
			{
                //前面i-1趟，搬j-2个物体的最优解+选择了最后一对
				dp[i][j]=dp[i-1][j-2]+(q[j]-q[j-1])*(q[j]-q[j-1]);
				//在选择前j-1个物体和选择了最后一对中找最优解
                if(j!=2*i)
				    dp[i][j]=min(dp[i][j],dp[i][j-1]);
			}
		}
		cout<<dp[k][n]<<endl;
	}
	return 0;
} 

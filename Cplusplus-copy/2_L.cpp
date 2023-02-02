//一个人的旅行
//多起点多终点
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define M 1005
int Map[M][M],Dist[M],Visit[M];
int main()
{
    int T,S,D,a,b,time,start2,targe2,Min,next;
    int i,j,number;
    while(scanf("%d %d %d",&T,&S,&D)==3)
    {
        Min=inf;
        for(i=0;i<M;i++)
        {
            Visit[i]=1;
            Dist[i]=inf;
            for(j=0;j<M;j++)
                Map[i][j]=inf;
        }
        number=0;//记录编号最大的城市
        while(T--)
        {
            scanf("%d %d %d",&a,&b,&time);
            number=max(number,max(a,b));
            Map[a][b]=min(Map[a][b],time);
            Map[b][a]=Map[a][b];
        }
        while(S--)//虚拟起点为0，虚拟起点到多个真正的起点间的距离为0
        {
            scanf("%d",&start2);
            Map[0][start2]=0;
            Map[start2][0]=0;
        }
        int targe=number+1;//设置虚拟终点为number+1，虚拟终点到各个真正终点间距离为0
        for(i=0;i<D;i++)
        {
            scanf("%d",&targe2);
            Map[targe2][targe]=0;
            Map[targe][targe2]=0;
        }
        Visit[0]=0;
        Dist[0]=0;
        int start=0;
        while(start!=targe)//相同的松弛操作
        {
            Min=inf;
            for(i=1;i<=targe;i++)//i一定要写成i<=targe,之前写成了number QAQ
            {
                if(Map[start][i]!=inf)
                    Dist[i]=min(Dist[i],Map[start][i]+Dist[start]);
                if(Dist[i]<Min&&Visit[i])
                {
                    Min=Dist[i];
                    next=i;
                }
            }
            start=next;
            Visit[start]=0;
        }
        printf("%d\n",Dist[targe]);
    }
    return 0;
}
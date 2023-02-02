//畅通工程续、最短路径
//最短要么直达，要么在直达最短的点处转一下
#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define M 201
int Map[M][M],Dist[M],Visit[M];//map是邻接矩阵，Dist储存从出发点到每个点的已知最短距离，Visit标记是否处理过
int main()
{
    int n,m,start,targe,next;
    int i,j,dis,a,b,Min;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0;i<n;i++)//初始化
        {
            Dist[i]=inf;
            Visit[i]=1;//1表示没处理过，0表示处理过
            for(j=0;j<n;j++)
                Map[i][j]=inf;
        }
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&dis);
            Map[a][b]=min(Map[a][b],dis);
            Map[b][a]=Map[a][b];//双向道路对称
        }
        scanf("%d %d",&start,&targe);
        Dist[start]=0;
        Visit[start]=0;
        //Map[start][start]=0;
        while(start!=targe)
        {
            Min=inf;
            for(i=0;i<n;i++)
            {
                if(Map[start][i]!=inf)//如果有路的话
                    Dist[i]=min(Dist[i],Dist[start]+Map[start][i]);//在直达和转一次中找最小的
                if(Visit[i]&&Dist[i]<Min)//标记过的点就不再参与大小的比较
                {
                    Min=Dist[i];
                    next=i;
                }  
            }
            if(Min==inf)
               break;
            start=next;
            Visit[start]=0;//终点为start的点已经被处理过了        
        }
        if(Dist[targe]==inf)
            printf("%d\n",-1);
        else
            printf("%d\n",Dist[targe]);
    }
    return 0;
}
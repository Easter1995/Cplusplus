//Choose the Best Route
//单向最短路径
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define M 1005
using namespace std;
int Dist[M],Map[M][M],Visit[M];
int main()
{
    int n,m,s,p,q,t,Min,w,start,next;
    int i,j;
    while(scanf("%d%d%d",&n,&m,&s)==3)
    {
        Min=inf;
        for(i=0;i<=n;i++)
        {
            Visit[i]=1;
            Dist[i]=inf;
            for(j=0;j<=n;j++)
                Map[i][j]=inf;
        }
        while(m--)
        {
            scanf("%d%d%d",&p,&q,&t);
            Map[p][q]=min(Map[p][q],t);
            //Map[q][p]=Map[p][q];
        }
        scanf("%d",&w);
        for(i=0;i<w;i++)
        {
            scanf("%d",&start);
            Map[0][start]=0;
            //Map[start][0]=0;
        }
        Dist[0]=0;
        Visit[0]=0;
        start=0;
        while(start!=s)
        {
            Min=inf;
            for(i=1;i<=n;i++)
            {
                if(Map[start][i]!=inf)
                    Dist[i]=min(Map[start][i]+Dist[start],Dist[i]);
                if(Visit[i]&&Dist[i]<Min)
                {
                    Min=Dist[i];
                    next=i;
                }    
            }
            if(Min==inf)
                break;
            start=next;
            Visit[start]=0;
        }
        if(Dist[s]!=inf)
            printf("%d\n",Dist[s]);
        else
            printf("%d\n",-1);
    }
    return 0;
}
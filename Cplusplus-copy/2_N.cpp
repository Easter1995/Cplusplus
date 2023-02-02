//bfs
#include<bits/stdc++.h>
using namespace std;
int N,Start,End;//N表示楼层总数，Start表示开始的楼层，End表示目标楼层
int k[202]={1},vis[202];//k[]用来存储ki，vis[]用来存储是否来过这个楼层
struct pos
{
    int level,steps;
};
void bfs();
int main()
{
    int i;
    while(scanf("%d",&N)==1)
    {
        if(N==0)
            break;
        scanf("%d%d",&Start,&End);
        for(i=1;i<=N;i++)
        {
            scanf("%d",&k[i]);
            vis[i]=0;
        }
        bfs();
    }
}
void bfs()
{
    pos current,next;//用结构体来存储状态
    current.level=Start;
    current.steps=0;
    queue <pos>qu;//把pos类型变量排成队列
    qu.push(current);//把当前的楼层状态加入队列
    vis[Start]=1;
    while(!qu.empty())//队列非空
    {
        current=qu.front();//取出队列里的第一个
        qu.pop();//去掉队列里的第一个
        if(current.level==End)
        {
            printf("%d\n",current.steps);
            return;
        }
        //第一种分支：UP
        next.level=current.level+k[current.level];
        next.steps=current.steps+1;
        if(next.level<=N)
        {
            if(!vis[next.level])
            {
                vis[next.level]=1;
                qu.push(next);//加入队列
            }
        }
        //第二种分支：DOWN
        next.level=current.level-k[current.level];
        next.steps=current.steps+1;
        if(next.level>=0)
        {
            if(!vis[next.level])
            {
                vis[next.level]=1;
                qu.push(next);
            }
        }
    } 
    printf("%d\n",-1);
    return;
}
#include<bits/stdc++.h>
using namespace std;
int s,n,m,vis[101][101][101];
void bfs();
struct coke
{
    int step,a,b,c;
};
int main()
{   
    while(scanf("%d%d%d",&s,&n,&m)==3)
    {
        if(s==0&&n==0&&m==0)
            break;
        bfs();
    }
    return 0;
}
void bfs()
{
    queue <coke>qu;
    int i,j,k;
    coke current,next;
    current.a=s;current.b=0;current.c=0;
    current.step=0;
    qu.push(current);
    if(s%2)
    {
        printf("NO\n");
        return;
    } 
    // for(i=0;i<=s;i++)
    //     for(j=0;j<=n;j++)
    //         for(k=0;k<=m;k++)
    //             vis[i][j][k]=0;
    memset(vis,0,sizeof(vis));//只能用来把int类型全部赋值为0或-1
    while(!qu.empty())
    {
        current=qu.front();
        qu.pop();
        if((current.a==s/2&&current.b==s/2) || (current.a==s/2&&current.c==s/2) || (current.b==s/2&&current.c==s/2))
        {
            printf("%d\n",current.step);
            return;
        }
        //一共有六种状态转移方法
        next.c=current.c;
        //a-->b
        if(current.a+current.b>n)
        {
            next.a=current.a-(n-current.b);
            next.b=n;    
        }
        else
        {
            next.a=0;
            next.b=current.a+current.b;
        }
        if(!vis[next.a][next.b][next.c])
        {
            vis[next.a][next.b][next.c]=1;
            next.step=current.step+1;
            qu.push(next);
        }
        //b-->a
        if(current.a+current.b>s)
        {
            next.a=s;
            next.b=current.b-(s-current.a);    
        }
        else
        {
            next.a=current.a+current.b;
            next.b=0;
        }
        if(!vis[next.a][next.b][next.c])
        {
            vis[next.a][next.b][next.c]=1;
            next.step=current.step+1;
            qu.push(next);
        }
        //a-->c
        next.b=current.b;
        if(current.a+current.c>m)
        {
            next.a=current.a-(m-current.c);
            next.c=m;    
        }
        else
        {
            next.a=0;
            next.c=current.a+current.c;
        }
        if(!vis[next.a][next.b][next.c])
        {
            vis[next.a][next.b][next.c]=1;
            next.step=current.step+1;
            qu.push(next);
        }
        //c-->a
        if(current.a+current.c>s)
        {
            next.a=s;
            next.c=current.c-(s-current.c);    
        }
        else
        {
            next.a=current.a+current.c;
            next.c=0;
        }
        if(!vis[next.a][next.b][next.c])
        {
            vis[next.a][next.b][next.c]=1;
            next.step=current.step+1;
            qu.push(next);
        }
        //b-->c
        next.a=current.a;
        if(current.b+current.c>m)
        {
            next.b=current.b-(m-current.c);
            next.c=m;    
        }
        else
        {
            next.b=0;
            next.c=current.b+current.c;
        }
        if(!vis[next.a][next.b][next.c])
        {
            vis[next.a][next.b][next.c]=1;
            next.step=current.step+1;
            qu.push(next);
        }
        //c-->b
        if(current.b+current.c>n)
        {
            next.b=n;
            next.c=current.c-(n-current.b);    
        }
        else
        {
            next.b=current.b+current.c;
            next.c=0;
        }
        if(!vis[next.a][next.b][next.c])
        {
            vis[next.a][next.b][next.c]=1;
            next.step=current.step+1;
            qu.push(next);
        }
    }
    printf("NO\n");
    return;
}
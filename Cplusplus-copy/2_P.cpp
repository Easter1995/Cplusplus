#include<bits/stdc++.h>
using namespace std;
int vis[9][9];//vis[x][y]==0表示没有访问过(x,y),vis[x][y]==1则表示访问过
int pos[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};
//pos[i][0]表示x方向的移动，pos[i][1]表示y方向的移动
char startx,endx;//开始的x坐标和结束的x坐标
int starty,endy;//开始的y坐标和结束的y坐标
struct knight
{
    char x;//存x坐标
    int y,step;//存y坐标和步数
};
void bfs();
int main()
{
    while(scanf(" %c%d %c%d",&startx,&starty,&endx,&endy)==4)
    {
        memset(vis,0,sizeof(vis));
        bfs();
    }
}
void bfs()
{
    //常规bfs操作
    int i,j;
    knight cur,nex;
    cur.step=0;
    cur.x=startx;
    cur.y=starty;
    queue <knight>qu;
    qu.push(cur);
    while(!qu.empty())
    {
        cur=qu.front();
        qu.pop();
        if(cur.x==endx&&cur.y==endy)
        {
            printf("To get from %c%d to %c%d takes %d knight moves.\n",startx,starty,endx,endy,cur.step);
            return;
        }
        //直接用循环状态转移
        for(i=0;i<8;i++)
        {
            nex.x=cur.x+pos[i][0];
            nex.y=cur.y+pos[i][1];
            if(nex.y>=1&&nex.y<=8&&nex.x>='a'&&nex.x<='h')
            {
                if(!vis[nex.x-'a'+1][nex.y])//记得把x变成数字1~8
                {
                    vis[nex.x-'a'+1][nex.y]=1;
                    nex.step=cur.step+1; 
                    qu.push(nex);
                }
            }
        }
    }
}
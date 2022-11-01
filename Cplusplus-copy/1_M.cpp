//畅通工程
#include<bits/stdc++.h>
using namespace std;
int bin[1002];
//找到X的老大
int findx(int x)
{
    while(bin[x]!=x)//这个是X是老大的标准
        x=bin[x];
    return x;
}
//把不同的老大合并 
void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fx!=fy)
        bin[fx]=fy;
}
int main()
{
    int n,m,x,y;
    int i,cnt;
    while(scanf("%d",&n),n)
    {
        cnt=-1;
        scanf("%d",&m);
        //初始化，每个元素的老大都是它自己
        for(i=1;i<=n;i++)
        {
            bin[i]=i;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            merge(x,y);
        }
        for(i=1;i<=n;i++)
        {
            if(bin[i]==i)//看一共有几个老大
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
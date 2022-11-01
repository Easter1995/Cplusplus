//小希的迷宫
#include<bits/stdc++.h>
using namespace std;
int boss[100000]={0};
int findx(int x)
{
    if(x!=boss[x])
	    boss[x]=findx(boss[x]);
	return boss[x];
}
void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fx!=fy)
        boss[fx]=fy;
}
int main()
{
    int a,b;
    int i,flag,sum;
    while(1)
    {
        sum=0;
        flag=0;
        i=1;
        while(scanf("%d %d",&a,&b)!=EOF&&a&&b)
        {
            if(a==-1||b==-1)
			    return 0;
            //一定要加上这个if语句，只把没有“初始化”的数字的老大改成自己，因为后面可能出现重复数字
            //比如6 8  8 9而之前也许把boss[8]改成了6，这样boss[8]再改成8就会出错
            if(boss[a]==0)
                boss[a]=a;
            if(boss[b]==0)
                boss[b]=b;
            if(findx(a)==findx(b))
                flag=1;
            merge(a,b);
        }
        for(i=1,sum=0;i<=100000;i++)
        {
            if(boss[i]==i)
                sum++;
            boss[i]=0;
        }
        //sum>1：没有连通。而且0 0也要输出yes
        if(flag==1||sum>1)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
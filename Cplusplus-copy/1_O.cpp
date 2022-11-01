#include<bits/stdc++.h>
using namespace std;
int boss[5000];
struct vi
{
    int x,y;
    long long len;
}bin[5000];
int findx(int x)
{
    while(x!=boss[x])
    {
        x=boss[x];
    }
    return x;
}
void merge(int m,int n)
{
    boss[m]=n;
}
bool cmp(vi x,vi y)
{
    return x.len<y.len;
}
int main()
{
    int m,n,fx,fy,cnt,i;
    long long sum;
    while(cin>>m>>n,m)
    {
        sum=0;
        for(i=1;i<=n;i++)
              boss[i]=i;
        for(i=1;i<=m;i++)
            cin>>bin[i].x>>bin[i].y>>bin[i].len;
        sort(bin+1,bin+m+1,cmp);
        for(cnt=0,i=1;i<=m;i++)
        {
            fx=findx(bin[i].x);
            fy=findx(bin[i].y);
            if(fx!=fy)
            {
                sum+=bin[i].len;
                merge(fx,fy);
                cnt++;
            }
        }
        if(cnt>=n-1)
            cout<<sum<<endl;
        else
            cout<<"?"<<endl;
    }
    return 0;
}
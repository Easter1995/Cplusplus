//畅通工程
#include<bits/stdc++.h>
using namespace std;
int boss[1000];
struct vi
{
    int a,b,road;
    long long len;
}bin[5000];
bool cmp(vi x,vi y)
{
    //优先考虑已经修好的路
    if(x.road==y.road)
        return x.len<y.len;
    else
        return x.road>y.road;
}
int findx(int x)
{
    if(boss[x]==x)
        return x;
    boss[x]=findx(boss[x]);
    return boss[x];
}
void merge(int x,int y)
{
    boss[x]=y;
}
int main()
{
    int n,a,b,road,cnt,fa,fb,i;
    long long sum;
    while(cin>>n,n)
    {
        sum=0;
        cnt=0;
        for(int i=1;i<=n;i++)
            boss[i]=i;
        for(int i=1;i<=(n*(n-1))/2;i++)
        {
            cin>>bin[i].a>>bin[i].b>>bin[i].len>>bin[i].road;
            cnt+=bin[i].road;
        }
        if(cnt>=n-1)
        {
            cout<<0<<endl;
        }
        else
        {
            sort(bin+1,bin+(n*(n-1))/2+1,cmp);
            for(int i=1;cnt<n-1;i++)
            {
                fa=findx(bin[i].a);
                fb=findx(bin[i].b);
                if(fa!=fb)
                {
                    merge(fa,fb);
                    if(bin[i].road==0)
                    {
                        cnt++;
                        sum+=bin[i].len;
                    }
                }
            }
            cout<<sum<<endl;
        }   
    }
}
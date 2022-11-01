#include<bits/stdc++.h>
using namespace std;
int boss[101];
struct vi
{
    int x,y;
    long long len;
}bin[10000];
int findx(int x)
{
    int r=x;
    if(boss[r]==r)
        return r;
    boss[r]=findx(boss[r]);
    return boss[r];
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
    int n,fx,fy,cnt,i;
    long long sum;
    while(cin>>n,n)
    {
        sum=0;
        for(i=1;i<=n;i++)
            boss[i]=i;
        for(i=1;i<(n*(n-1))/2+1;i++)
            cin>>bin[i].x>>bin[i].y>>bin[i].len;
        sort(bin+1,bin+(n*(n-1))/2+1,cmp);
        for(cnt=0,i=1;cnt<n-1;i++)
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
        cout<<sum<<endl;
    }
    return 0;
}
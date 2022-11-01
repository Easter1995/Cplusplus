#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long p[40]={0,3,8};
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=3;i<=n;i++)
        {
            p[i]=2*p[i-1]+2*p[i-2];
        }
        cout<<p[n]<<endl;
    }
    return 0;
}
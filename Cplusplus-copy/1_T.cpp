#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long p[50]={0,1,2};
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=3;i<=n;i++)
        {
            p[i]=p[i-1]+p[i-2];
        }
        cout<<p[n]<<endl;
    }
    return 0;
}
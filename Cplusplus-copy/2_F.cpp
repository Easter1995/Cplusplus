#include<bits/stdc++.h>
using namespace std;
int f[1001][1001];
int main()
{
    int t,n,volume;
    int v[1001]={0},w[1001]={0};
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>volume;
        for(int j=1;j<=n;j++)
            cin>>w[j];
        for(int j=1;j<=n;j++)
            cin>>v[j];
        memset(f,0,sizeof(f));
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<=volume;k++)
            {
                if(k>=v[j])
                    f[j][k]=max(f[j-1][k],f[j-1][k-v[j]]+w[j]);
                else
                    f[j][k]=f[j-1][k];
            }
        }
        cout<<f[n][volume]<<endl;
    }
    return 0;
}
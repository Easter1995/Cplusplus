#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,n;
    int p[10000]={0,2,7};
    cin>>c;
    for(int i=0;i<c;i++)
    {
        cin>>n;
        for(int j=2;j<=n;j++)
        {
            p[j]=p[j-1]+4*(j-1)+1;
        }
        cout<<p[n]<<endl;
    }
    return 0;
}
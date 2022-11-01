#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,n;
    long long p[30]={0,1,3,5};
    cin>>c;
    for(int i=0;i<c;i++)
    {
        cin>>n;
        for(int j=3;j<=n;j++)
        {
            p[j]=2*p[j-2]+p[j-1];
        }
        cout<<p[n]<<endl;
    }
    return 0;
}
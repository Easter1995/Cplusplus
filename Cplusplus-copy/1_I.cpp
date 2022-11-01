//搬桌子
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t,i,j,k,n,r1,r2,time;
    cin>>t;
    for(i=0;i<t;i++)
    {
        int room[200]={0};
        time=0;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>r1>>r2;
            r1=(r1-1)/2;
            r2=(r2-1)/2;
            if(r1<r2)
            {
                for(k=r1;k<=r2;k++)
                {
                    room[k]+=1;
                }
            }
            else
            {
                for(k=r2;k<=r1;k++)
                {
                    room[k]+=1;
                }
            }    
        }
        sort(room,room+200,cmp);
        time=10*room[0];
        cout<<time<<endl;
    }
    return 0;
}
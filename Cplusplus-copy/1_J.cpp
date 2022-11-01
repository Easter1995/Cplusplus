//今年暑假不AC
#include<bits/stdc++.h>
using namespace std;
struct tv
{
    int end,start;
} progarm[100];
bool cmp(tv x,tv y)
{
    return x.end<y.end;
}
int main()
{
    int n,time;
    int i,j,cnt=1;
    cin>>n;
    while(n!=0)
    {
        cnt=1;
        for(i=0;i<n;i++)
        {
            cin>>progarm[i].start>>progarm[i].end;
        }
        sort(progarm,progarm+n,cmp);
        time=progarm[0].end;
        for(j=1;j<n;j++)
        {
            if(time<=progarm[j].start)
            {
                cnt++;  
                time=progarm[j].end;
            }
        } 
        cout<<cnt<<endl;
        cin>>n;
    }
    return 0;
}
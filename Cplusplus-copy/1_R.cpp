#include<bits/stdc++.h>
using namespace std;
int floor(int x)
{
    int fn;
    if(x==2||x==1)
        return 1;
    else
    {
        fn=floor(x-1)+floor(x-2);
    }
    return fn;
}
int main()
{
    int n,m,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        cout<<floor(m)<<endl;
    }
    return 0;
}
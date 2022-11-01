//奋勇争先续
#include<bits/stdc++.h>
using namespace std;
struct score
{
    char name[10];
    int num,time;
}sc[1000];
//结构体数组排序
bool cmp(score x,score y)
{
    //如果答对题数相同，就按照时间排序
    if(x.num==y.num)
        return x.time<y.time;
    return x.num>y.num;
}
int main()
{
    int c,n,m,i,j,temp1;
    cin>>c;
    for(i=0;i<c;i++)
    {
        cin>>n>>m;
        for(j=0;j<n;j++)
        {
            cin>>sc[j].name>>sc[j].num>>sc[j].time;
        }
        sort(sc,sc+n,cmp);
        for(j=0;j<m;j++)
        {
            cout<<sc[j].name<<" "<<sc[j].num<<" "<<sc[j].time<<endl;
        }
    }
    return 0;
}
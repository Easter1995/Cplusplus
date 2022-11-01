//田忌赛马
#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,i,j;
    while(cin>>n)
    {
        int cnt=0,result=0;
        if(n==0)
            break;
        int tian[n];int king[n];
        for(i=0;i<n;i++)
        {
            cin>>tian[i];
        }
        sort(tian,tian+n,cmp);
        for(i=0;i<n;i++)
        {
            cin>>king[i];
        }
        sort(king,king+n,cmp);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(tian[i]>king[j])
                {
                    cnt++;
                    king[j]=tian[i];
                    break;
                }
            }
        }
        result=cnt*200-(n-cnt)*200;
        cout<<result<<endl;
    }
    return 0;
}
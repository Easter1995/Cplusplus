#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	long long int h[100];
	scanf("%d",&a);
	for(int i=0;i<a;i++)
	{
		scanf("%d%d",&b,&c);
		h[0]=0;
		h[1]=1;
		h[2]=2;
	    for(int i=3;i<=c;i++)
	    {
		    h[i]=h[i-1]+h[i-2];
	    }
	    printf("%lld\n",h[c-b]);
	}
	return 0;
}
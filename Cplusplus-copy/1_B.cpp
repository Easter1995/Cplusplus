#include<stdio.h>
#include<math.h>
int GCD(int a,int b)
{
    int temp;
    while(b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main()
{
    int n,m,a,b,c,lcm,gcd;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        scanf("%d %d",&a,&b);
        lcm=a*(b/GCD(a,b));
        for(j=0;j<m-2;j++){
            scanf("%d",&c);
            lcm=lcm*(c/GCD(lcm,c));
        }
        printf("%d\n",lcm);
    }
    return 0;
}
#include<stdio.h>
#include<math.h>
int gcd(int a,int b)
{
    int temp;
    while(b!=0){
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main()
{
    int lcm,a,b;
    while(scanf("%d %d",&a,&b)==2)
    {
        lcm=a*(b/gcd(a,b));
        printf("%d\n",lcm);
    }
    return 0;
}
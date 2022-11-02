//A的B次方，求出三位数字组成的整数
#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    int i;
    scanf("%d %d",&a,&b);
    while(a!=0&&b!=0)
    {   
        c=1;
        for(i=0;i<b;i++)
        {
            c*=a;
            //c>1000后，前面的数字跟后三位数字没有关系了
            //比如1001：1001*a==(1*a)+1000*a
            //而1000*a肯定加在千位及以后，后三位数只用看1*a是多少
            if(c>=1000)
            {
                c%=1000;
            }
        }   
        printf("%d\n",c); 
        scanf("%d %d",&a,&b);  
    }
    return 0;
}
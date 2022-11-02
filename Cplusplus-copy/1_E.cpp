//斐波拉契数列：找规律
//一般数字很多，数字排列有规律：抽屉原理直接找规律
#include<stdio.h>
#include<math.h>
int main()
{
    int f0=7,f1=11;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if((n+1)%8==3||(n+1)%8==7)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    
    return 0;
}
#include<stdio.h>
#include<math.h>
int main()
{   
    int a,n,m,result;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&n);
        m=n%10;
        if(n%4==0)
        {
            result=(int)pow(m,4)%10;
        }
        else
        {
            result=(int)pow(m,n%4)%10;
        }
        printf("%d\n",result);
    }
    
    return 0;
}
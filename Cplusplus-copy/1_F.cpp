#include<stdio.h>
#include<math.h>
double equ(double x)
{   
    double result;
    result=8*pow(x,4.0)+7*pow(x,3.0)+2*pow(x,2.0)+3*x+6;
    return	result;
}
int main()
{
    int t;
    double x,y,left,right,mid;
    scanf("%d",&t);
    
    for(int i=0;i<t;i++)
    {
        scanf("%lf",&y);
        if(y>=equ(0)&&y<=equ(100))//判断有没有解
        {
            left=0;
            right=100;
            while(right-left>1e-10)
            //科学计数法控制精度
            //1e-10表示10的-10次方
            {
                //二分法解方程
                //外层已经判断出有没有解了，所以只要能得出mid，肯定是解
                mid=(left+right)/2;
                double ans=equ(mid);
                if(ans>y)
                    //浮点数二分法，减的数比控制的精度多一位
                    right=mid-1e-11;
                else
                    left=mid+1e-11;
            }
            printf("%.4lf\n",mid);
        }
        else
            printf("No solution!\n");
    }
    return 0;
}
 //快速幂
 int power(int a,int n){
     int ans;
     if(a>=1000)
        a%=1000;
     if(n==0){
        ans=1;
     }
     else{
        ans=power(a*a,n/2);
        if(ans>1000)
            ans%=1000;
        if(n%2!=0)
            ans*=a;
     }
     return ans;
 }
 int main(){
     int a,b,c;
     while(scanf("%d %d",&a,&b)==2){
        if(a==0&&b==0)
            break;
        c=power(a,b);
        printf("%d\n",c);
     }
     return 0;
 }

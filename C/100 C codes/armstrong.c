#include<stdio.h>
int main(){
    int onum,num,sum=0,n=0,rem;
    printf("Enter number:");
    scanf("%d",&onum);
    num=onum;
    while(num>0){
        num/=10;
        n++;
    }
   
    num=onum;
    while(num>0){
        int pow=1;
        rem=num%10;
        for(int i=1;i<=n;i++){
            pow*=rem;  
        }
        sum+=pow;
        num/=10;
    }
    printf("\n%d",sum);
    if(sum==onum){
        printf("\nEntered number is armstrong");
    }
    else{
        printf("Entered number is not armstrong");
    }
}
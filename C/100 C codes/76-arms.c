#include<stdio.h>
int isArms(int,int);
int sum=0;
int main(){
    int onum,num,n;
    printf("Enter the number: ");
    scanf("%d",&onum);
    num=onum;
    while(num>0){
        num/=10;
        n++;
    }
    isArms(onum,n);
    if(sum==onum){
        printf("Is an armstrong number");
    }
    else{
        printf("Not an armstrong number");
    }
}
int isArms(int num,int dig){
    if(num==0){
        return sum;
    }
    int pow=1,rem;
        rem=num%10;
        for(int i=1;i<=dig;i++){
            pow*=rem;  
        }
        sum+=pow;
        return isArms(num/10,dig);
}
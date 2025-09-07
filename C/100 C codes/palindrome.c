#include<stdio.h>
int main(){
    int num,rem,ofnum,newnum;
    printf("Enter the number: ");
    scanf("%d",&ofnum);
    num=ofnum;
    while(num>0){
        rem=num%10;
        newnum=newnum*10+rem;
        num/=10;
    }
    if(newnum==ofnum){
        printf("Entered number is palindrome");
    }
    else{
        printf("Entered number is not palindrome");
    }
}
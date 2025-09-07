#include<stdio.h>
int palindrome(int);
int ofnum,num,rem,newnum;
int main(){
    printf("Enter the num:");
    scanf("%d",&ofnum);
    num=ofnum;
   
  
    palindrome(num);
    if(newnum==ofnum){
        printf("entered number is palindrome");
    }
    else{
        printf("entered number is not palindrome");
    }
}
int palindrome(int num){
    if(num==0){
        return 1;
    }
    rem=num%10;
        newnum=newnum*10+rem;
        return palindrome(num/=10);
    }

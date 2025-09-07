#include<stdio.h>
int main(){
    int arr[5];
    int rev_arr[5];
    for(int i=0;i<5;i++){
        printf("Enter the element: ");
        scanf("%d",&arr[i]);
    }
    int j=0;
    for(int i=4;i>=0;i--){
        
        rev_arr[j]=arr[i];
        j++;
    }

    int a;
    for(int i=0;i<5;i++){
        if(arr[i]==rev_arr[i]){
            a=1;
        }
        else{
            a=0;
        }
    }
    if(a==1){
        printf("Arr s palindrome");

    }
    else{
        printf("array is not palindrome");
    }
}
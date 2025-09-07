#include<stdio.h>
#include<string.h>
int main(){
    char smth[]="     Uday gadhavi    ";
    char new[50];
    int j=0;
    for(int i=0;i<strlen(smth);i++){
        if((smth[i]>='a'  && smth[i]<='z') || (smth[i]>='A' && smth[i]<='Z')){
        
            new[j]=smth[i];
            j++;
        }
    }
    new[j]='\0';
    for(int i=0;i<strlen(new);i++){
        printf("%c",new[i]);
    }
    
}
#include<stdio.h>
#include<string.h>
int main(){
    char c[40];
    printf("Enter your name:");
    fgets(c,sizeof(c),stdin);

    for(int i=0;i<strlen(c);i++){
        if(c[i]>='a' && c[i]<='z'){
            c[i]=c[i]-32;
        }
        
    }
    puts(c);
}
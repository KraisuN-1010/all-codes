#include<stdio.h>
#include<string.h>
int main(){
    char pass[10]="1234";
    char upass[10];
    printf("Enter the password:");
    fgets(upass,sizeof(upass),stdin);
    upass[strcspn(upass,"\n")]='\0';
    int ans=strcmp(pass,upass);
    if(ans==0){
        printf("You have entered the corerct password");
    }
    else{
        printf("Wronmf password entered.");
    }
}
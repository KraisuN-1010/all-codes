#include<stdio.h>
#include<string.h>
int main(){
    char name[40];
    char reverse[50];
    printf("Enter your name:");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]='\0';
    int j=strlen(name)-1;
    for(int i=0;i<strlen(name);i++){
        reverse[i]=name[j];
        j--;
    }
    reverse[strlen(name)]='\0';
    printf("%s",reverse);
}
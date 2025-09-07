#include<stdio.h>
int main(){
    FILE *filePointer=fopen("read.txt","r");
    FILE *filePointer1=fopen("read2.txt","a");
    if(filePointer==NULL){
        printf("File not opened");
    }
    else{
        printf("File opened sucsessfully\n");
    }
    
    char ch;
    while((ch=fgetc(filePointer))!=EOF){
        fprintf(filePointer1,"%c",ch);
    }
    fclose(filePointer);
    filePointer=NULL;
    fclose(filePointer1);
    filePointer1=NULL;
}
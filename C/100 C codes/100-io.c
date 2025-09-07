#include<stdio.h>
int main(){
    FILE *fp=fopen("read2.txt","a");
    if(fp==NULL){
        printf("File not opened");
    }
    else{
        printf("File opened sucsessfully\n");
    }
    char c[50];
    
    printf("Enter a string:");
    fgets(c,sizeof(c),stdin);
    fprintf(fp,c);
    fclose(fp);
    fp=NULL;
}
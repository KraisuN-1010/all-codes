#include<stdio.h>
#include<string.h>
int main(){
    char fileName[10];
    printf("Enter the file name: ");
    // fgets(fileName,sizeof(fileName),stdin);
    scanf("%s",&fileName);
    // fileName[strcspn(fileName,"\n")]='\0';
    FILE *filePointer=fopen(fileName,"r");
    if(filePointer==NULL){
        printf("File not opened");
    }
    else{
        printf("File opened sucsessfully");
    }
    fclose(filePointer);
    filePointer=NULL;
    return 0;
}
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
        printf("File opened sucsessfully\n");
    }
    int arr[10];
    for(int i=0;i<5;i++){
        fscanf(filePointer,"%d",&arr[i]);
    }
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    fclose(filePointer);
    filePointer=NULL;
    return 0;
}
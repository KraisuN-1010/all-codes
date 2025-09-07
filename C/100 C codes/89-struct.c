#include<stdio.h>
typedef struct{
    char name[50];
    char author[50];
    float price;
}books;
int main(){
    books books[3]={
        {"Harry potter","J.k Rowling",35.99},
        {"A song of ice and fire","George R.R",30.99},
        {"Alice in wonederland","Leewis carrol",35.99}
    };
    for(int i=0;i<3;i++){
        printf("\nName of book:%s, Name of author:%s, Price of book:%.2f$",books[i].name,books[i].author,books[i].price);
    }
}
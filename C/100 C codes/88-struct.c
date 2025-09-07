#include<stdio.h>
typedef struct
{
    char name[20];
    char author[20];
    float price;
}books;
int main(){
    books book={"Harry Potter","J.K Rowling",35.99};
    printf("Name of book:%s, Name of author:%s, Price of book:%.2f$",book.name,book.author,book.price);
    
}
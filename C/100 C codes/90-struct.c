#include<stdio.h>



typedef struct{
    char make[50];
    char model[50];
    int year;
    char col[50];
}cars;
void cardesc( cars *car);
int main(){
    cars car[3]={
        {"BMW","M5 CS", 2022,"Matte black"},
        {"Porsche","Carrera GT",2006,"Basalt black"},
        {"McLaren","P1",2015,"Volcano orange"}
    };
    cardesc(car);
}
void cardesc( cars *car){
    for (int i = 0; i < 3; i++){
        printf("\nThe car is %s %s in the color %s and the year of make is %d",car[i].make,car[i].model,car[i].col,car[i].year);
    }
}
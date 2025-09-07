#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char make[50];
    char model[50];
    int year;
    char col[50];
}cars;

int main(){
    
    cars car[3]={
        {"BMW","M5 CS", 2022,"Matte black"},
        {"Porsche","Carrera GT",2006,"Basalt black"},
        {"McLaren","P1",2015,"Volcano orange"}
    };
    cars *arr=(cars *)malloc(3*sizeof(cars));
    for(int i=0;i<3;i++){
        arr[i]=car[i];
    }
    printf("The car is:%s",arr[0].model);
    free(arr);
    arr=NULL;
}
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct
// {
//     char make[20];
//     char model[20];
//     int year;
//     char color[50];
// } Car;
// int main()
// {
//     Car C[3] =
//         {
//             {"BMW", "BMW iX", 2020, "Alpine white"},
//             {"Tesla", "Tesla Cybertruck", 2023, "silver"},
//             {"Ford", "Mustang", 2018, "grabber blue"}};
//     Car *arr = (Car *)malloc(sizeof(Car));
//     printf("The memory allocation is : %p\n", arr);
//     int a;
//     printf("Enter 0 for BMW enter 1 for Tesla and enter 2 for Ford");
//     scanf("%d", &a);
//     for (int i = 0; i < 3; i++)
//     {
//         arr[i] = C[i];
//     }
//     printf("The car make is %s .Its model is %s .Its year of launch is %d and color is %s.\n", arr[a].make, arr[a].model, arr[a].year, arr[a].color);
// }
#include<stdio.h>
int main(){
    int arr[2][3]={{1,2,4},{3,4,5}};
    int x,y;
    printf("Which row?:");
    scanf("%d",&x);
    printf("Which column?:");
    scanf("%d",&y);
    printf("The elemnt you want is %d",arr[x-1][y-1]);
}